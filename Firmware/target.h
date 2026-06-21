#pragma once

#define TARGET_BOARD_IDENTIFIER "CX8"
#define USBD_PRODUCT_STRING     "Cortex-8"

// ============================================================
// MCU
// ============================================================
// STM32H743BIT6 LQFP-208 @ 480MHz

// ============================================================
// LED & BEEPER
// ============================================================
#define LED0_PIN                PC11   // WS2812B data line
#define LED0_INVERTED

#define BEEPER_PIN              PC12
#define BEEPER_INVERTED

// ============================================================
// UART (Serial Ports)
// ============================================================
// UART1 — ESP32-S3 (ELRS / telemetry)
#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9

// UART3 — OpenIPC camera
#define USE_UART3
#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PB10

// ============================================================
// SPI — IMU Bus (SPI1)
// ============================================================
#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

// ============================================================
// IMU 1 — ICM-42688-P (Primary, 32kHz)
// ============================================================
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_CS_PIN           PB6
#define GYRO_1_EXTI_PIN         PI8
#define GYRO_1_ALIGN            CW0_DEG

// ============================================================
// IMU 2 — ICM-20602 (Backup / crash saturation recovery)
// ============================================================
#define USE_GYRO_SPI_ICM20602
#define USE_ACC_SPI_ICM20602

#define GYRO_2_SPI_INSTANCE     SPI1
#define GYRO_2_CS_PIN           PB7
#define GYRO_2_EXTI_PIN         PC1
#define GYRO_2_ALIGN            CW0_DEG

// ============================================================
// QSPI Blackbox Flash — W25Q128JW (128MB)
// ============================================================
#define USE_FLASHFS
#define USE_FLASH_W25Q128FV
#define FLASH_CS_PIN            PI3
#define FLASH_SPI_INSTANCE      SPI1

// Note: QSPI hardware pins PH13/PH14/PI0/PI1/PI2/PI3
// EasyEDA routes these to QUADSPI peripheral — configure in CubeMX

// ============================================================
// I2C — BQ25798 Charger
// ============================================================
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN            PB8
#define I2C1_SDA_PIN            PB9
#define I2C_DEVICE              (I2CDEV_1)

// ============================================================
// MOTOR OUTPUTS — DShot600 Bidirectional
// All 8 channels conflict-free across TIM5/TIM3/TIM1
// ============================================================
#define USE_MOTOR
#define USE_DSHOT

// X8 Coaxial motor mapping:
// M1 Front Upper  — PA0  TIM5_CH1  DMA1_Stream0
// M2 Front Lower  — PA1  TIM5_CH2  DMA1_Stream1
// M3 Right Upper  — PA2  TIM5_CH3  DMA1_Stream2
// M4 Right Lower  — PA3  TIM5_CH4  DMA1_Stream3
// M5 Rear Upper   — PB0  TIM3_CH3  DMA1_Stream4
// M6 Rear Lower   — PB1  TIM3_CH4  DMA1_Stream5
// M7 Left Upper   — PE9  TIM1_CH1  DMA2_Stream6
// M8 Left Lower   — PE11 TIM1_CH2  DMA2_Stream7

#define MOTOR1_PIN              PA0
#define MOTOR2_PIN              PA1
#define MOTOR3_PIN              PA2
#define MOTOR4_PIN              PA3
#define MOTOR5_PIN              PB0
#define MOTOR6_PIN              PB1
#define MOTOR7_PIN              PE9
#define MOTOR8_PIN              PE11

// ============================================================
// ARMING / SAFETY
// ============================================================
// Hardware arming inhibit via 74LVC1G32 OR gate
// STM32 pulls ARM_INHIBIT high to kill all 8 gate driver EN pins
#define USE_BUTTONS
#define BUTTON_A_PIN            PD0    // ARM_INHIBIT — JST-GH safety switch

// ============================================================
// BATTERY / ADC
// ============================================================
#define USE_ADC
#define ADC_INSTANCE            ADC1

// Current sensing via INA240A2 — analog output to ADC
#define CURRENT_METER_ADC_PIN   PC0
#define VBAT_ADC_PIN            PC3

#define USE_VOLTAGE_METER
#define USE_CURRENT_METER

// ============================================================
// BATTERY MATRIX CONTROL GPIOs
// ============================================================
// STM32 GPIOs for dual battery series/parallel switching
// PARALLEL_EN  — PC4  (default HIGH = parallel = 7.4V)
// SERIES_EN    — PC5  (pull HIGH to switch to series = 14.8V)
// PRECHARGE_EN — PC6  (fires 5ms before SERIES_EN)
// BAL_CTRL     — PC7  (mid-flight balancing control)
// CHARGE_EN    — PC8  (active LOW — enables BQ25798 charging)
// PD_PG        — PC9  (input — CH224K power good)
// SERIES_INH   — PC10 (input — TLV3201 overcurrent inhibit)

// ============================================================
// STATUS LEDs & RGB
// ============================================================
#define USE_LED_STRIP
#define LED_STRIP_PIN           PC11   // WS2812B DIN

// ============================================================
// CRASH LOCATOR / BACKUP SYSTEM
// ============================================================
// TPS3840 voltage supervisor monitors main VBAT
// On dropout → P-FET switches power to ESP32 automatically
// ESP32 handles BLE beacon independently — no STM32 involvement
// CHG_STAT     — PD1  (BQ25798 charge status input)
// CHG_INT      — PD2  (BQ25798 interrupt input)

// ============================================================
// SWD DEBUG
// ============================================================
// 4-pin 1.27mm header on top layer
// Pin 1 — VCC_3V3
// Pin 2 — PA13 SWDIO
// Pin 3 — PA14 SWCLK
// Pin 4 — DGND

// ============================================================
// WATCHDOG
// ============================================================
#define USE_WATCHDOG
// WWDG + IWDG both enabled — feed into arming inhibit line

// ============================================================
// BLACKBOX
// ============================================================
#define USE_BLACKBOX
#define BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
// 128MB W25Q128JW — circular buffer wear leveling in firmware

// ============================================================
// TARGET FEATURES
// ============================================================
#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff
#define TARGET_IO_PORTE         0xffff
#define TARGET_IO_PORTH         0xffff
#define TARGET_IO_PORTI         0xffff

#define USABLE_TIMER_CHANNEL_COUNT 8
#define USED_TIMERS             (TIM_N(1) | TIM_N(3) | TIM_N(5))
