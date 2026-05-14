# MAR Racing Drone X8 — AI Racing Buddy (ASH)

> A 100mm X8 coaxial ultra-whoop with a fully custom 8-in-1 AIO flight controller, dual-battery series/parallel switching matrix, 140W USB-PD charging, OpenIPC digital video, and a hardware crash locator system. Built from scratch for Hack Club Stasis.

---

## Why

I love FPV racing but have no one to race with. So I decided to build my own opponent instead of waiting.

ASH (my AI drone) will race against me using computer vision and autonomous flight. But before the AI layer comes the hardware — and this hardware is unlike anything off-the-shelf. Every component, every trace, every safety interlock was designed from scratch.

---

## What Makes This Different

Most FPV builds use off-the-shelf 4-in-1 ESC stacks. This is an **8-in-1 AIO** — a single PCB that integrates:

- Full flight controller (STM32H753 @ 480MHz)
- 8 independent ESC channels (one per motor, X8 coaxial)
- Dual 2S battery series/parallel switching matrix
- Hardware safety interlock (cannot explode even if firmware crashes)
- 140W USB-PD fast charging
- OpenIPC digital FPV video (Sony IMX335 + SigmaStar SSC338Q)
- ESP32-S3 ELRS receiver + crash locator beacon
- Dual IMU with crash saturation recovery

This is Rev5. The journey from Rev1 (STM32F411, 4 motors, basic ESC) to Rev5 (STM32H753, 8 motors, full safety system) is documented in [JOURNAL.md](JOURNAL.md).

---

## The Drone

| Parameter | Spec |
|---|---|
| Frame | 100mm X8 Coaxial |
| Motors | BETAFPV LAVA Series 1104 7200KV x8 |
| Props | 3 inch |
| Battery | 2x Tattu R-Line 550mAh 2S 95C LiHV |
| Max Voltage | 14.8V (4S series mode) |
| Max Burst Power | ~1000W |
| AUW | ~110-125g |
| Thrust-to-Weight | ~4:1 to 5:1 |
| Flight Time | 4-6 min patrol (2S) / ~2 min racing (4S) |

---

## The Custom AIO FC — Rev5

### Board Specs

| Parameter | Spec |
|---|---|
| Size | 40x40mm |
| Layers | 8-layer HDI |
| Copper | 2oz outer / 2oz inner (L4, L5, L6) |
| Via-in-pad | POFV (epoxy-filled, copper-capped) |
| Fab | JLCPCB Advanced |
| Mounting | 4x M2 holes at 30.5x30.5mm stack pattern |

### Brain

| Component | Package | Purpose |
|---|---|---|
| STM32H753BIT6 | UFBGA-176 | Main FC — 480MHz, crypto engine |
| ESP32-S3-FN8 | QFN-56 | ELRS + Wi-Fi/BLE + crash locator |
| ICM-42688-P | LGA-14 | Primary IMU — 32kHz gyro |
| ICM-20602 | LGA-16 | Backup IMU — crash saturation recovery |
| W25Q128JW | WSON-8 | 128MB QSPI blackbox flash |
| TCXO 16MHz | SMD | Temperature-compensated HSE clock |

### Octo-ESC Power Stage

- **8x FD6288Q** gate drivers — one dedicated 3-phase driver per motor
- **48x CSD17313Q2** motor FETs — 2x parallel per switch position for 10A continuous per phase
- **2x INA240A2** current sensors with 0.5mΩ shunts and Kelvin connections
- DShot600 bidir on all 8 channels via TIM5/TIM3/TIM1 across DMA1/DMA2 — zero conflicts

### Dual-Battery Series/Parallel Matrix

The most unique feature. Two 2S packs can be configured in:
- **Parallel (2S 7.4V)** — patrol mode, 4-6 min flight
- **Series (4S 14.8V)** — racing mode, full punch

Hardware switching with multiple safety layers prevents catastrophic failure:

1. **SN74LVC1G08 AND gate + SN74LVC1G04 inverter** — physically prevents parallel and series FETs from being on simultaneously
2. **TLV3201 comparator + LM4040 reference** — disables mode switching above 30A current regardless of firmware state
3. **2N7002 pre-charge FET + 10Ω MELF resistor** — soft-switches 5ms before main FET to eliminate inrush current
4. **LM74610-Q1 ideal diode controllers** — near-zero drop reverse polarity protection on each battery input
5. **Si2323ADS P-FET** — mid-flight battery balancing (80% SOC logic)

### Power System

| Rail | Component | Output | Powers |
|---|---|---|---|
| 3.3V | TPS62840 | 3.3V/2A | STM32, IMUs, logic |
| 5V | TPS62170 | 5V/2A | ESP32-S3, LEDs, buzzer |
| Filtered VBAT | LC filter + TVS | Direct VBAT | OpenIPC video module |
| Backup | JST 1x2 + P-FET | 3.7V | Crash locator (ESP32 only) |

### USB-PD 140W Charging

- **MP5031** negotiates 20V EPR from wall adapter
- **SC8815** I²C-programmable buck-boost charges both 2S packs in parallel to 8.4V
- **PRTR5V0U2X** ESD protection on USB-C CC and data lines
- **SMBJ24A** TVS clamp on 20V input rail

### Emergency & Safety Systems

**Hardware Arming Inhibit:**
JST-GH 1x3 safety switch header. Pulling low instantly kills all 8 FD6288Q EN pins via 74LVC1G32 OR gate. Works even if STM32 is crashed.

**Independent Watchdogs:**
Both WWDG (window) and IWDG (independent, 32kHz LSI) feed into the arming inhibit line.

**Status Indication:**
- WS2812B RGB LED — armed (green), low battery (orange), crash (red + buzzer), locator active (blue)
- Passive buzzer with driver FET

**Crash Locator:**
- 100-200mAh 3.7V backup LiPo via JST 1x2
- Automatic switchover via TPS3840 voltage supervisor + P-FET when main power lost
- ESP32-S3 wakes every 20 min, broadcasts BLE beacon with last known position from W25Q128 blackbox
- ~48 hours beacon life on backup battery
- Rechargeable via USB-C when recovered

### Video System

OpenIPC digital FPV — Sony IMX335 sensor + SigmaStar SSC338Q SoC. Stacked on top of the AIO via 30.5mm M2 pattern. Powered directly from filtered VBAT rail.

---

## 8-Layer Stackup

| Layer | Type | Weight | Purpose |
|---|---|---|---|
| L1 (Top) | Signal | 2oz | Components, signal escapes, regulators |
| L2 | Signal | 1oz | DShot signals — shielded between L1 and L3 |
| L3 | Ground (DGND) | 1oz | Clean digital ground for STM32 + IMU |
| L4 | Power | 2oz | VBAT_PRIMARY motor power plane |
| L5 | Ground (Dirty) | 2oz | ESC return ground — all FET sources via here |
| L6 | Power | 2oz | VBAT_SECONDARY motor power plane |
| L7 | Ground (AGND) | 1oz | Analog ground for INA240 + IMU |
| L8 (Bottom) | Signal/Power | 2oz | 48x MOSFETs + 8x gate drivers |

AGND and DGND are separate nets joined at a single star point at the battery negative pad only.

---

## Schematic Progress

| Block | Status |
|---|---|
| BLK3_BATTERY — Matrix, interlock, pre-charge, ideal diodes, INA240 | ✅ Complete |
| BLK4_POWER — 3.3V/5V bucks, OpenIPC filter, crash locator switchover | 🔄 In Progress |
| BLK1_STM32 — H753 power pins, QSPI, SWD, TCXO | ⏳ Pending |
| BLK2_IMU — ICM-42688-P + ICM-20602 | ⏳ Pending |
| BLK5_ESC — 8x FD6288Q + 48x CSD17313Q2 | ⏳ Pending |
| BLK6_USBPD — MP5031 + SC8815 | ⏳ Pending |
| BLK7_ESP32 — ELRS + crash locator | ⏳ Pending |

---

## Repository Structure

```
├── PCB/
│   ├── MAR_X8_Rev5.easyeda/     ← EasyEDA Pro project
│   └── gerbers/                 ← Export when ready
├── Images/
├── JOURNAL.md                   ← Full build log
└── README.md
```

---

## Progress

- [x] Rev1 — STM32F411, 4 motors, basic ESC schematic
- [x] Rev2/Rev3 — DRV8323RS motor drivers, ICM-42688-P, KiCad
- [x] Rev4 — STM32H753, 8 motors, dual battery concept
- [x] Rev5 spec — Full AIO design locked, all failure modes resolved
- [x] BLK3_BATTERY schematic complete
- [ ] BLK4-7 schematic
- [ ] Full ERC pass
- [ ] PCB layout
- [ ] JLCPCB order
- [ ] Build and bench test
- [ ] Betaflight custom target
- [ ] AI racing opponent (Phase 2)

---

## About

Built by **Muduganti Aman Reddy** — Grade 12, Hyderabad, India. Hack Club Stasis grant project.

3rd place Asia Pacific RoboCup Junior International. Building hardware since age 8.

> *"Racing alone is boring. So I built my own opponent."*
