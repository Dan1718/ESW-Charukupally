#include <WiFi.h>
#include <WebServer.h>

// Replace these defaults before connecting hardware.
const char *WIFI_SSID = "CHANGE_ME";
const char *WIFI_PASSWORD = "CHANGE_ME";
constexpr uint8_t STEP_PIN = 26;
constexpr uint8_t DIR_PIN = 27;
constexpr uint8_t ENABLE_PIN = 25;
constexpr float MOTOR_STEPS_PER_REV = 200.0f;
constexpr uint8_t MICROSTEPS = 16;
constexpr float TOLERANCE_DEG = 0.1f;
constexpr float FAULT_LIMIT_DEG = 5.0f;
constexpr uint32_t MOVE_TIMEOUT_MS = 30000;

WebServer server(80);
float targetDeg = 0.0f;
float commandedDeg = 0.0f;
float encoderDeg = 0.0f; // Mock encoder: replace readEncoder() when hardware is selected.
bool enabled = true;
bool moving = false;
bool faulted = false;
uint32_t moveStartedAt = 0;
uint32_t lastStepAt = 0;
constexpr uint32_t STEP_INTERVAL_US = 1200;

float normalize(float angle) {
  while (angle >= 360.0f) angle -= 360.0f;
  while (angle < 0.0f) angle += 360.0f;
  return angle;
}

float shortestError(float target, float actual) {
  float error = normalize(target) - normalize(actual);
  if (error > 180.0f) error -= 360.0f;
  if (error < -180.0f) error += 360.0f;
  return error;
}

float readEncoder() {
  // Simulation follows the commanded shaft. A real implementation must return
  // the absolute output-shaft angle in degrees and validate its signal.
  return commandedDeg;
}

void setFault(const char *message) {
  faulted = true;
  moving = false;
  digitalWrite(ENABLE_PIN, HIGH);
  server.send(409, "application/json", String("{\"error\":\"") + message + "\"}");
}

String statusJson() {
  float error = shortestError(targetDeg, encoderDeg);
  String json = "{";
  json += "\"target\":" + String(targetDeg, 4) + ",\"expected\":" + String(commandedDeg, 4);
  json += ",\"actual\":" + String(encoderDeg, 4) + ",\"error\":" + String(error, 4);
  json += ",\"enabled\":" + String(enabled ? "true" : "false");
  json += ",\"moving\":" + String(moving ? "true" : "false");
  json += ",\"fault\":" + String(faulted ? "true" : "false") + "}";
  return json;
}

void handleStatus() { server.send(200, "application/json", statusJson()); }

void handleMove() {
  if (!server.hasArg("plain")) { server.send(400, "application/json", "{\"error\":\"JSON body required\"}"); return; }
  String body = server.arg("plain");
  int key = body.indexOf("target");
  int colon = body.indexOf(':', key);
  if (key < 0 || colon < 0) { server.send(400, "application/json", "{\"error\":\"target is required\"}"); return; }
  targetDeg = normalize(body.substring(colon + 1).toFloat());
  faulted = false;
  moving = enabled;
  moveStartedAt = millis();
  server.send(200, "application/json", statusJson());
}

void handleStop() { moving = false; server.send(200, "application/json", statusJson()); }
void handleEnable() { enabled = !enabled; digitalWrite(ENABLE_PIN, enabled ? LOW : HIGH); if (!enabled) moving = false; server.send(200, "application/json", statusJson()); }
void handleReset() { targetDeg = commandedDeg = encoderDeg = 0.0f; faulted = false; moving = false; server.send(200, "application/json", statusJson()); }
void handleClearFault() { faulted = false; server.send(200, "application/json", statusJson()); }

void controlLoop() {
  encoderDeg = readEncoder();
  float error = shortestError(targetDeg, encoderDeg);
  if (fabs(error) > FAULT_LIMIT_DEG && moving) { faulted = true; moving = false; return; }
  if (!moving || faulted || !enabled || fabs(error) <= TOLERANCE_DEG) { moving = false; return; }
  if (micros() - lastStepAt < STEP_INTERVAL_US) return;
  lastStepAt = micros();
  bool direction = error > 0;
  digitalWrite(DIR_PIN, direction ? HIGH : LOW);
  digitalWrite(STEP_PIN, HIGH); delayMicroseconds(3); digitalWrite(STEP_PIN, LOW);
  float increment = 360.0f / (MOTOR_STEPS_PER_REV * MICROSTEPS);
  commandedDeg = normalize(commandedDeg + (direction ? increment : -increment));
  if (millis() - moveStartedAt > MOVE_TIMEOUT_MS) { faulted = true; moving = false; }
}

void setup() {
  pinMode(STEP_PIN, OUTPUT); pinMode(DIR_PIN, OUTPUT); pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(250);
  server.on("/api/status", HTTP_GET, handleStatus);
  server.on("/api/move", HTTP_POST, handleMove);
  server.on("/api/stop", HTTP_POST, handleStop);
  server.on("/api/toggle-enable", HTTP_POST, handleEnable);
  server.on("/api/reset-zero", HTTP_POST, handleReset);
  server.on("/api/clear-fault", HTTP_POST, handleClearFault);
  server.begin();
}

void loop() { server.handleClient(); controlLoop(); }
