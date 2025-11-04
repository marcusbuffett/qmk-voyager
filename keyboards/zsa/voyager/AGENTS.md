# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## ZSA Voyager Keyboard

This is the QMK firmware for the ZSA Voyager keyboard - a split ergonomic keyboard with STM32F303xC MCU, active left side (USB host), low-profile switches, and RGB lighting via IS31FL3731 LED drivers.

## Build Commands

All build commands must be run from the QMK firmware root directory (3 levels up from here):

```bash
cd /Users/marcusbuffett/projects/qmk_firmware
```

**Build firmware:**
```bash
make zsa/voyager:default
```

**Build and flash to keyboard:**
```bash
make zsa/voyager:default:flash
```

The build system uses DFU (Device Firmware Update) with specific vendor/product IDs (3297:0791).

## Keymap Structure

Keymaps are located in `keymaps/<name>/` directories. Each keymap contains:

- **keymap.c** - Layer definitions, custom keycodes, combos, leader key sequences, and custom behavior
- **config.h** - Keymap-specific configuration (timing, features, mousekey settings)
- **rules.mk** - Feature enables/disables (COMBO_ENABLE, MOUSEKEY_ENABLE, LEADER_ENABLE, etc.)

### Current Default Keymap Features

The default keymap includes several advanced QMK features:

- **Chordal Hold** - Asymmetric chordal holds enabled via `CHORDAL_HOLD` and `chordal_hold_layout` matrix
- **Combos** - Key combinations that trigger different keys (e.g., C+S for CMD, S+T for CTRL)
- **Leader Key** - Two-key sequences for window management (w prefix), media controls (i prefix), and tools (t prefix)
- **One Shot Modifiers (OSM)** - Tap for one-shot modifier behavior
- **One Shot Layers (OSL)** - Tap to activate layer temporarily
- **Layer Tap (LT)** - Hold for layer, tap for key
- **Dual Function Keys** - Custom tap/hold behavior (e.g., DUAL_FUNC_0 sends @ on tap, # on hold)
- **Mouse Keys** - Layer 5 provides mouse movement and buttons

## Hardware Architecture

**Split keyboard communication:**
- Left side (MCU): STM32F303xC with 12×7 matrix
- Right side (I/O expander): MCP23018 via I2C
- Custom matrix scanning in `matrix.c` (optimized with `-O3`)

**LED Control:**
- 4 indicator LEDs controlled via `STATUS_LED_1(bool)` through `STATUS_LED_4(bool)`
  - LED 1: Top left
  - LED 4: Bottom right
- Default: Layer state indicators (define `VOYAGER_USER_LEDS` to show caps/num/scroll lock instead)
- RGB matrix via dual IS31FL3731 drivers (addresses GND and VCC)

**Split detection:**
Use `is_transport_connected()` in `housekeeping_task_user()` to detect if right half is connected (useful for gaming mode when disconnecting right side).

## Important Configuration Values

**Timing:**
- `FLOW_TAP_TERM`: 150ms - QMK Oryx Flow tap term
- `LEADER_TIMEOUT`: 200ms - Leader key sequence timeout
- `COMBO_TERM`: 30ms - Combo trigger window
- Mouse acceleration and speed settings are heavily customized

**Matrix:**
- 12 rows × 7 columns (6 rows per hand)
- Custom matrix driver required (`CUSTOM_MATRIX = lite`)

## Key Files

- `voyager.c` - Keyboard initialization, LED control, dynamic macro hooks, startup animation
- `voyager.h` - Hardware definitions and macros
- `matrix.c` - Custom matrix scanning for split keyboard with I2C expander
- `config.h` - Hardware configuration (matrix size, I2C addresses, mousekey defaults)
- `rules.mk` - Build configuration (MCU linker script, DFU settings, required drivers)
- `keyboard.json` - Keyboard metadata and layout definitions

## Development Notes

- The default keymap uses ZSA's Oryx configurator system (`ORYX_ENABLE = yes`)
- When adding custom keycodes, start from `ZSA_SAFE_RANGE` instead of `SAFE_RANGE`
- The MCP23018 I/O expander requires the I2C driver (`I2C_DRIVER_REQUIRED = yes`)
- Matrix scanning is performance-critical and uses compiler optimizations
- The keyboard has startup sequence hooks via deferred execution (`startup_exec`)
