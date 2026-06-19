Cortex-8

8-in-1 AIO Flight Controller for X8 Coaxial Racing Drones

Cortex-8 is a custom 8-in-1 all-in-one flight controller designed from scratch for high-performance X8 coaxial FPV racing drones. Every subsystem -- flight control, ESC power stage, dual battery matrix, USB-PD charging, digital FPV video, and emergency crash locator -- is integrated onto a single 61x65mm 8-layer HDI PCB.


Flight Control


STM32H743BIT6 running at 480MHz with hardware crypto engine (AES/HMAC/HASH)
8-motor X8 coaxial support with conflict-free DShot600 bidirectional on all 8 channels simultaneously (TIM5/TIM3/TIM1 across DMA1/DMA2)
Dual IMU -- ICM-42688-P primary at 32kHz + ICM-20602 backup for crash saturation recovery
128MB QSPI blackbox flash (W25Q128JW) with circular buffer wear leveling
Temperature-compensated 16MHz TCXO for clock stability across motor heat cycles
ESP32-S3 onboard for ELRS RC link + Wi-Fi/BLE



Dual Battery Series/Parallel Matrix


Two 2S LiPo packs switch between 7.4V patrol mode and 14.8V racing mode in flight
Hardware interlock (AND gate + inverter) physically prevents battery short-circuit regardless of firmware state
TLV3201 comparator with LM4040 shunt reference disables mode switching above 30A
Pre-charge soft-switch (2N7002 + 10 ohm MELF) fires 5ms before main FET to eliminate inrush current
LM74610-Q1 ideal diode controllers on each battery input -- near-zero voltage drop reverse polarity protection
Mid-flight battery balancing via Si2323ADS P-FET (80% SOC logic)



Octo-ESC Power Stage


8x FD6288Q gate drivers -- one dedicated 3-phase driver per motor, no shared bootstrap
48x CSD17313Q2 MOSFETs -- 2x parallel per switch position for 10A continuous per phase
2x INA240A2 current sensors with Kelvin-connected 10mohm shunts and 50V/V PWM rejection
Snubber caps on every motor phase for flyback spike suppression



Power System


TPS62840 3.3V/2A synchronous buck for STM32 and IMUs
TPS62170 5V/2A synchronous buck for ESP32 and peripherals
Filtered VBAT rail for OpenFPV camera module
140W USB-PD charging -- CH224K negotiates 20V EPR, BQ25798 I2C-programmable buck-boost charges both 2S packs in parallel to 8.4V



Digital FPV Video


OpenFPV system -- SSC338Q + IMX415 camera stacked on top via 30.5x30.5mm M2 pattern
BL-M8812EU2 WiFi adapter (RTL8812EU, 29dBm) for long-range 5GHz digital video
Range: up to 5-6km with PixelPilot ground station on Android



Hardware Safety Systems


Hardware arming inhibit -- JST-GH safety switch instantly kills all 8 gate driver EN pins via 74LVC1G32 OR gate, works even if STM32 is crashed or frozen
WWDG + IWDG dual watchdog -- both feed into arming inhibit line
WS2812B RGB LED status -- armed (green), low battery (orange), crash (red + buzzer), locator active (blue)
Passive buzzer with driver FET



Emergency Crash Locator


Dedicated 300mAh backup LiPo connected via JST 1x2
When main batteries disconnect mid-crash, TPS3840 voltage supervisor detects the dropout and automatically switches power to ESP32 via P-FET -- no firmware intervention needed
ESP32 wakes from deep sleep every 30 minutes and broadcasts a BLE SOS beacon containing the last known GPS/position data written to the W25Q128 blackbox before impact
Beacon runs for approximately 48+ hours on the 300mAh backup cell
Backup battery recharges automatically via USB-C when drone is recovered
You will never lose this drone



PCB


61x65mm, 8-layer HDI
Via-in-pad (POFV) for STM32 UFBGA-176 BGA escape
2oz copper outer layers, 2oz power planes on L4/L5/L6
Separate AGND/DGND planes joined at single star point
JLCPCB Advanced fabrication with X-ray inspection
4x M2 mounting holes at 30.5x30.5mm standard stack pattern



Layer Stackup

LayerPurposeCopperL1 (Top)Signal + components2ozL2DShot signals only1ozL3DGND clean digital ground1ozL4VBAT_PRIMARY motor power2ozL5DGND dirty ESC ground2ozL6DGND extra shielding2ozL7AGND analog ground1ozL8 (Bottom)MOSFETs + gate drivers2oz


Key Specs

ParameterValueMCUSTM32H743BIT6 @ 480MHzWirelessESP32-S3-FN8 (Wi-Fi + BLE + ELRS)Motors supported8 (X8 coaxial)Battery input2x 2S LiPo (series/parallel switchable)Voltage modes7.4V (2S parallel) / 14.8V (4S series)Max motor current10A continuous per phaseCharging140W USB-PD (20V EPR)Blackbox128MB W25Q128JW QSPI flashFPV systemOpenFPV (SSC338Q + IMX415)Video range5-6km @ 5GHzPCB size61x65mmPCB layers8 (HDI)Stack pattern30.5x30.5mm M2FabricationJLCPCB Advanced + ENIG + X-ray


Project Status


Schematic: Complete (7 blocks, 0 DRC errors)
PCB Layout: In progress
Fabrication: Pending



Designed by Muduganti Aman Reddy | Hackclub
