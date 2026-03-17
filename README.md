@ My AI Racing Buddy (or ash)

Building an AI-controlled FPV racing drone to be my racing partner since I have no one to race with.

##  Project Overview
**My-AI-Racing-Buddy** is a high-performance, 75mm micro FPV racing drone designed for indoor agility and future AI-assisted navigation. This project integrates a lightweight carbon fiber/nylon frame with a 5-in-1 AIO Flight Controller to maximize power-to-weight ratio.

###  Key Features
* **Compact Power:** Built on a 75mm whoop platform using 0802SE 19500KV brushless motors.
* **FPV Ready:** Equipped with a C03 Micro Camera and VR03 Goggles for low-latency immersive flight.
* **AI-Ready Architecture:** Designed with mounting points and power overhead for future integration of OpenCV-based companion computers.
* **Manufacturability:** Complete CAD source files (.f3d) and industry-standard .STEP files included for 3D printing 

@ The Setup
* **Drone 1 (Me):** Controlled with my Avionic transmitter
* **Drone 2 (AI):** Controlled by Raspberry Pi with computer vision
* **Ground Station:** Pi processes FPV feeds, sends commands


@ Why?
I love FPV racing but it's boring alone. Building my own opponent!
## CAD Design

### Complete Assembly
![Drone Assembly](images/fullassembly.png)

### Frame Design
![Frame](images/frame.png)

### Canopy with Camera Mount
![Canopy](images/canopy.png)

### Ducted Prop Guards
![Prop Guards](images/propguard.png)

### Wiring Diagram
![Wiring Diag](images/wiring-diag.png)

### BOM
| Product name                                  | Product description                     | Product link                                                                                    | Unit Price (INR) | Amount | Total (INR) |
|-----------------------------------------------|-----------------------------------------|-------------------------------------------------------------------------------------------------|------------------|--------|-------------|
| Radiomaster Pocket                            | ELRS Controller (Transparent)           | https://robu.in/product/radiomaster-pocket-radio-controller-elrs-charcoal/                      | 6356             | 1      | 6356        |
| Matrix 1S FC                                  | AIO Flight Controller (5-in-1)          | https://betafpv.com/products/matrix-1s-brushless-flight-controller                              | 4626.18          | 1      | 10982.18    |
| LAVA 1S 450mAh Battery                        | High-discharge LiPo (4-Pack)            | https://betafpv.com/products/lava-1s-450mAh-75c-battery-4pcs                                    | 1664.83          | 1      | 12647.01    |
| 0802SE Brushless Motors                       | 19500KV (2022 Version)                  | https://betafpv.com/products/0802se-brushless-motors-2022-version                               | 3608.21          | 1      | 16255.22    |
| 5.8G OTG Receiver                             | UVC Receiver for Android Phone          | https://loftyagrotech.com/5-8g-fpv-otg-receiver-for-android/                                    | 4100             | 1      | 20355.22    |
| BetaFPV 6-Port Charger                        | 1S LiPo/LiHV Charger & Adapter          | https://betafpv.com/products/bt2-0-ph2-0-1s-lipo-charger-adapter                                | 1109.58          | 1      | 21464.8     |
| Gemfan 1219S 3-Blade Propellers (1.0mm Shaft) | an ideal choice for high-speed rotating | https://betafpv.com/products/gemfan-1219s-3-blade-propellers-1-0mm-shaft?variant=41018473054342 | 831.95           | 1      | 22296.75    |
| Camera C03                                    | FPV Micro Camera                        | https://betafpv.com/products/c03-fpv-micro-camera                                               | 1109.58          | 1      | 23406.33    |
| BT2.0 Whoop Pigtail                           | Battery Connector (Pack of 6)           | https://robu.in/product/betafpv-bt2-0-whoop-cable-pigtail-6pcs/                                 | 646.84           | 1      | 24053.17    |
| Air75 II Frame                                | 75mm Whoop Frame (Black)                | https://betafpv.com/products/air75-ii-brushless-whoop-frame                                     | 461.78           | 2      | 24,976.73   |
| Heat Shrink 1mm Red                           | WOER HST (1M)                           | https://robu.in/product/heat-shrink-sleeve-1mm-red-industrial-grade-woer-hst/                   | 10               | 1      | 24986.73    |
| Heat Shrink 2mm Red                           | WOER HST (1M)                           | https://robu.in/product/heat-shrink-sleeve-2mm-red-industrial-grade-woer-hst/                   | 12               | 1      | 24998.73    |
| Heat Shrink 3mm Red                           | WOER HST (1M)                           | https://robu.in/product/heat-shrink-sleeve-3mm-red-industrial-grade-woer-hst/                   | 7                | 1      | 25005.73    |
| Heat Shrink 4mm Red                           | WOER HST (1M)                           | https://robu.in/product/heat-shrink-sleeve-4mm-red-industrial-grade-woer-hst/                   | 18               | 1      | 25023.73    |
| Heat Shrink 5mm Red                           | WOER HST (1M)                           | https://robu.in/product/heat-shrink-sleeve-5mm-red-industrial-grade-woer-hst/                   | 23               | 1      | 25046.73    |
| Heat Shrink 8mm Red                           | WOER HST (1M)                           | https://robu.in/product/heat-shrink-sleeve-8mm-red-industrial-grade-woer-hst/                   | 29               | 1      | 25075.73    |
| 22AWG Flex Wire Black                         | Power Wiring (Negative)                 | https://robu.in/product/high-quality-ultra-flexible-22awg-silicone-wire-1000m-black/            | 18               | 3      | 25129.73    |
| 22AWG Flex Wire Red                           | Power Wiring (Positive)                 | https://robu.in/product/high-quality-ultra-flexible-22awg-silicone-wire-1500m-red/              | 18               | 3      | 25183.73    |
| 30AWG Flex Wire Red                           | Signal/Camera Wiring                    | https://robu.in/product/30awg-high-quality-ultra-flexible-silicone-wire-red/                    | 5                | 4      | 25203.73    |
| Eachine EV800 FPV Goggles – Black             | fpv goggles                             | https://robu.in/product/eachine-ev800-fpv-goggles-black/                                        | 7,960.00         | 1      | 33163.73    |

### CAD 
[CAD Files](./CAD)

## Tech Stack
* 75mm brushless whoops
* Raspberry Pi 4 + GPS + camera
* OpenCV for drone tracking
* Custom 3D printed frames in Fusion 360

## Progress
- [x] Design custom 75mm drone frame 
- [x] Design camera canopy 
- [x] Design ducted prop guards 
- [x] Complete CAD assembly with electronics
- [x] Export .STEP file for manufacturing
- [ ] Order parts 
- [ ] Build physical drone
- [ ] Develop virtual AI opponent (OpenCV)
- [ ] Test flight & tune
- [ ] Code real AI control system
- [ ] First race!

Custom-designed every component from scratch:
- Lightweight X-frame (8g)
- Protective ducted guards (4g)  
- Integrated camera canopy
- Optimized for 0802SE motors + Matrix FC

## Firmware

Uses **Betaflight 4.5.0** (pre-installed on Matrix FC).

Default configuration works out of the box. 
Custom tuning done after test flights.

## Wiring
| Component | Connects To |
|-----------|-------------|
| Motors 1-4 | Matrix FC motor pads |
| Camera | Matrix FC cam input |
| Battery | Matrix FC BAT input |
| (Matrix has built-in VTX, RX, ESC) |

## Phase 1: Single Drone Build
Building ONE real drone first with virtual AI opponent.
Ground station (Raspberry Pi) will be added in future 
phase - for now AI runs on laptop with camera feed.
