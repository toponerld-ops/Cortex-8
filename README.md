# My AI Racing Buddy (ASH)

Building an AI-controlled FPV racing drone to be my racing partner because racing alone is boring.

## Why

I love FPV racing but have no one to race with. So I decided to build my own opponent instead of waiting. ASH (my AI drone) will eventually race against me using computer vision and autonomous flight. This is phase 1 getting the hardware right.

## The Concept

Two identical 75mm whoops. One controlled by me, one controlled by a Raspberry Pi. The Pi watches the FPV feed, tracks the gates, and tries to beat me. Ground station runs on the Pi itself.

## What Makes This Different

Most FPV builds use off-the-shelf flight controllers. I designed my own from scratch in KiCad a custom STM32F411 based FC with a dedicated UART port for the Raspberry Pi. This means the Pi can send flight commands directly to the FC using MSP protocol without any extra hardware.

## Custom Flight Controller

Designed entirely from scratch in KiCad 8. Never designed a PCB before this project.

**Specs:**
- MCU: STM32F411CEUx
- Gyro: MPU6000 via SPI
- ESCs: 4x DMN3404L MOSFETs
- Power: AMS1117-3.3 + L7805
- UART1: ELRS receiver input
- UART2: Raspberry Pi MSP connection
- Board size: ~30x35mm
- Mounting: 20x20mm M2 pattern

### Schematic
![Schematic](images/schematic.png)

### PCB
![PCB](images/pcb.png)

## Firmware

Betaflight 4.5.0 on STM32F411. UART2 set to MSP for Raspberry Pi communication. Manual control via ELRS on UART1.

AI layer on the Pi is planned for Phase 2 using OpenCV.

## Wiring

| Component | Connects To |
|-----------|-------------|
| Motors 1-4 | FC motor pads J1-J4 |
| Camera | FC cam input |
| Battery | BT2.0 connector J7 |
| ELRS Receiver | J5 UART1 |
| Raspberry Pi | J6 UART2 MSP |

## Repository Structure
```
├── PCB/
│   ├── AI_Racing_Buddy_FC.kicad_pro
│   ├── AI_Racing_Buddy_FC.kicad_sch
│   ├── AI_Racing_Buddy_FC.kicad_pcb
│   └── gerbers.zip
├── firmware/
├── journal.md
└── BOM.csv
```

## Progress

- [x] Design custom FC schematic
- [x] Complete PCB layout and routing
- [x] Export Gerbers
- [ ] Complete CAD frame design
- [ ] Export STEP and STL files
- [ ] Order parts
- [ ] Build drone
- [ ] Develop AI control (OpenCV)
- [ ] First race

## Phase 2 — AI Control

Raspberry Pi 4 connected via UART2 using MSP protocol. OpenCV for gate detection and opponent tracking. GPS connected directly to Pi for position data. This is the part I'm most excited about.
