@ My AI Racing Buddy (or ash)

Building an AI-controlled FPV racing drone to be my racing partner since I have no one to race with.

@ The Setup
* **Drone 1 (Me):** Controlled with my Avionic transmitter
* **Drone 2 (AI):** Controlled by Raspberry Pi with computer vision
* **Ground Station:** Pi processes FPV feeds, sends commands

@ Why?
I love FPV racing but it's boring alone. Building my own opponent!
## CAD Design

### Complete Assembly
![Drone Assembly](images/full assembly.png)

### Frame Design
![Frame](images/frame.png)

### Canopy with Camera Mount
![Canopy](images/canopy.png)

### Ducted Prop Guards
![Prop Guards](images/prop-guards.png)

## Tech Stack
* 75mm brushless whoops
* Raspberry Pi 4 + GPS + camera
* OpenCV for drone tracking
* Custom 3D printed frames in Fusion 360

## Progress
- [x] Design custom 75mm drone frame (30h)
- [x] Design camera canopy (28h)  
- [x] Design ducted prop guards (17h)
- [x] Complete CAD assembly with electronics (8h)
- [x] Export .STEP file for manufacturing
- [ ] Order parts ($400 budget)
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
