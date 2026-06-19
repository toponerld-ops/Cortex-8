# **Cortex-8**

**8-in-1 AIO Flight Controller for X8 Coaxial Racing Drones**

Cortex-8 is a **custom 8-in-1 all-in-one flight controller** designed from scratch for high-performance X8 coaxial FPV racing drones. Every subsystem — flight control, ESC power stage, dual battery matrix, USB-PD charging, digital FPV video, and emergency crash locator — is integrated onto a **single 61×65mm 8-layer HDI PCB**.

---

## **Key Features**

### **Flight Control**
- **STM32H743BIT6** @ 480MHz with hardware crypto engine (AES/HMAC/HASH)
- **8-motor X8 coaxial** support with conflict-free **DShot600** bidirectional on all 8 channels simultaneously
- **Dual IMU**: ICM-42688-P primary (32kHz) + ICM-20602 backup for crash saturation recovery
- **128MB QSPI Blackbox** (W25Q128JW) with circular buffer wear leveling
- Temperature-compensated **16MHz TCXO** for clock stability
- **ESP32-S3** onboard for **ELRS** + Wi-Fi/BLE

### **Dual Battery Series/Parallel Matrix**
- Two 2S LiPo packs switch between **7.4V patrol** and **14.8V racing** mode in flight
- Hardware interlock (AND gate + inverter) physically prevents battery short-circuit
- TLV3201 comparator disables switching above 30A
- Pre-charge soft-switch eliminates inrush current
- **LM74610-Q1** ideal diode controllers for near-zero voltage drop reverse polarity protection
- Mid-flight battery balancing

### **Octo-ESC Power Stage**
- 8× **FD6288Q** dedicated 3-phase gate drivers
- 48× **CSD17313Q2** MOSFETs (2× parallel per position → **10A continuous per phase**)
- 2× **INA240A2** current sensors with Kelvin-connected shunts
- Snubber capacitors on every motor phase

### **Power System**
- **TPS62840** 3.3V/2A buck for STM32 & IMUs
- **TPS62170** 5V/2A buck for ESP32 & peripherals
- **140W USB-PD** charging (20V EPR) with **BQ25798** buck-boost charger
- Filtered VBAT rail for OpenFPV camera

### **Digital FPV Video**
- **OpenFPV** system: **SSC338Q + IMX415** camera
- **BL-M8812EU2** (RTL8812EU, **29dBm**) 5GHz Wi-Fi adapter
- **Up to 5–6km** range with PixelPilot ground station

### **Hardware Safety Systems**
- **Hardware arming inhibit** via JST-GH safety switch (kills all 8 gate driver EN pins)
- **WWDG + IWDG** dual watchdog
- **WS2812B** RGB LED status + passive buzzer
- **Emergency Crash Locator** with 300mAh backup LiPo + BLE SOS beacon (48+ hours)

> **You will never lose this drone.**

---

## **Key Specs**

| Parameter              | Value                                      |
|------------------------|--------------------------------------------|
| **MCU**                | STM32H743BIT6 @ 480MHz                     |
| **Wireless**           | ESP32-S3 (Wi-Fi + BLE + ELRS)              |
| **Motors**             | 8 (X8 Coaxial)                             |
| **Battery**            | 2× 2S LiPo (Series/Parallel switchable)   |
| **Voltage Modes**      | 7.4V (parallel) / 14.8V (series)          |
| **Max Current**        | 10A continuous per phase                   |
| **Charging**           | 140W USB-PD (20V EPR)                      |
| **Blackbox**           | 128MB QSPI Flash                           |
| **FPV**                | OpenFPV (SSC338Q + IMX415)                 |
| **Video Range**        | 5–6km @ 5GHz                               |
| **PCB Size**           | 61×65mm                                    |
| **Layers**             | 8-layer HDI                                |
| **Stack**              | 30.5×30.5mm M2                             |
| **Fabrication**        | JLCPCB Advanced + ENIG + X-ray             |

---

## **PCB Design**

- **61×65mm**, **8-layer HDI** with Via-in-Pad (POFV)
- 2oz copper outer layers + heavy power planes
- Separate **AGND/DGND** planes with single star point
- Optimized for thermal performance and signal integrity

**Layer Stackup:**

| Layer | Purpose                     | Copper |
|-------|-----------------------------|--------|
| L1    | Signal + Components         | 2oz    |
| L2    | DShot signals only          | 1oz    |
| L3    | DGND (clean digital)        | 1oz    |
| L4    | VBAT_PRIMARY (motor power)  | 2oz    |
| L5    | DGND (dirty ESC)            | 2oz    |
| L6    | DGND (extra shielding)      | 2oz    |
| L7    | AGND (analog)               | 1oz    |
| L8    | MOSFETs + Gate Drivers      | 2oz    |

---

**Built for performance. Engineered for reliability.**

Ready to push the limits of X8 coaxial racing.
IMAGES----

TOP PCB 3D

![TOP-PCB-3D](Images/TOP-PCB-3D.png)

BOTTOM PCB 3D

![BOTTOM-PCB-3D](Images/BOTTOM-PCB-3D.png)

TOP LAYER TRACE

![TOP-LAYER-TRACE](Images/TOP-LAYER-TRACE.png)

INNER LAYER 1

![INNER-LAYER-1](Images/INNER-LAYER-1.png)

INNER LAYER 2

![INNER-LAYER-2](Images/INNER-LAYER-2.png)

INNER LAYER 3

![INNER-LAYER-3](Images/INNER-LAYER-3.png)

INNER LAYER 4

![INNER-LAYER-4](Images/INNER-LAYER-4.png)

INNER LAYER 5

![INNER-LAYER-5](Images/INNER-LAYER-5.png)

INNER LAYER 6

![INNER-LAYER-6](Images/INNER-LAYER-6.png)

BOTTOM LAYER TRACE

![BOTTOM-LAYER-TRACE](Images/BOTTOM-LAYER-TRACE.png)

Designed by Muduganti Aman Reddy | Hackclub
