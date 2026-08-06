# JWG openHASP Changelog

This document records enhancements made in the JWG fork of openHASP.

The upstream project changelog remains in CHANGELOG.md.

---

## Unreleased

### Added Aug 6, 2026
- Added haptic_blip() which is 1/2 times haptic_click and applied it to wake up

### Added Aug 5, 2026
- Wake-from-deep-sleep haptic notification.

### Added Aug 4, 2026 PM
- USB power sensing on GPIO2.
- Prevention of deep sleep while USB power is present.
- Haptic feedback driver on GPIO3.
- Haptic feedback for touchscreen object presses.
- Haptic feedback for page navigation controls.
- Haptic feedback for physical GPIO buttons.
- Two-pulse notification when USB power is connected.
- Single-pulse notification when USB power is disconnected.

### Changed
- Increased haptic click duration for more reliable tactile feedback.
- Added `jwgBuild.sh` to `.gitignore`.

### Added Aug 4, 2026
- USB power sensing for charger detection.
- Haptic feedback framework.
- Touchscreen haptic feedback for object presses.
- Haptic feedback for page navigation.
- Haptic feedback for physical GPIO buttons.
- Non-blocking haptic driver infrastructure.

### Added

- Configurable default start page via build.sh
- Motion wake from deep sleep
- Wake display during OTA firmware updates
- Hide boot screen until online
- Wi-Fi status LED
- Default handheld pages.jsonl

### Changed

- Faster boot sequence
- Improved TFT power management
- Reduced compiler warnings
- Improved display wake behavior

### Fixed

- Motion wake now triggers on GPIO state change
- Numerous compiler warnings
- Removed compiler warning related to `D_TIMESTAMP`

### Security

- Removed embedded Wi-Fi credentials
- Rewrote Git history to remove committed credentials

---

## v0.1.0-alpha (2026-07-11)

Initial public state of the JWG fork.

### Features

- ESP32-S3 XIAO support
- ILI9341 + XPT2046 handheld remote
- MQTT/Home Assistant integration
- Deep sleep
- Motion wake
- OTA improvements
