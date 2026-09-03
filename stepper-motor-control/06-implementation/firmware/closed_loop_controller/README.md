# ESP32 Closed-Loop Controller

This is the first firmware/UI scaffold for the project. It deliberately uses a
mock encoder so the API and dashboard can be exercised before the encoder is
chosen.

## Current defaults

- Direct drive, 200 full steps/revolution, 1/16 microstepping
- `STEP=GPIO26`, `DIR=GPIO27`, `ENABLE=GPIO25`
- Target tolerance: `0.1` degrees
- Fault threshold: `5` degrees
- Shortest-path movement in the range `0 <= angle < 360`

## Use

1. Set `WIFI_SSID` and `WIFI_PASSWORD` in the sketch.
2. Install the ESP32 Arduino core and upload the sketch.
3. Replace `readEncoder()` with the selected absolute encoder implementation.
4. Serve `index.html` from the ESP32 filesystem or a local development server.

The API is intentionally small: `GET /api/status`, `POST /api/move` with
`{"target": 120}`, plus `/api/stop`, `/api/toggle-enable`, `/api/reset-zero`,
and `/api/clear-fault`.

Do not connect a motor until the GPIO polarity, TB6600 common-anode/common-
cathode wiring, current setting, and microstep switches have been verified.
