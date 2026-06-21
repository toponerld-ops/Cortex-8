#include <stdint.h>
#include "platform.h"
#include "drivers/io.h"
#include "drivers/dma.h"
#include "drivers/timer.h"
#include "drivers/timer_def.h"

// ============================================================
// Timer / DMA assignments for DShot600 bidirectional
// STM32H743 — 8 motors across TIM1/TIM3/TIM5
// ============================================================

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    // TIM5 — Motors 1-4 (PA0-PA3) — DMA1 Stream 0-3
    DEF_TIM(TIM5, CH1, PA0,  TIM_USE_MOTOR, 0, 0),  // M1 Front Upper
    DEF_TIM(TIM5, CH2, PA1,  TIM_USE_MOTOR, 0, 1),  // M2 Front Lower
    DEF_TIM(TIM5, CH3, PA2,  TIM_USE_MOTOR, 0, 2),  // M3 Right Upper
    DEF_TIM(TIM5, CH4, PA3,  TIM_USE_MOTOR, 0, 3),  // M4 Right Lower

    // TIM3 — Motors 5-6 (PB0-PB1) — DMA1 Stream 4-5
    DEF_TIM(TIM3, CH3, PB0,  TIM_USE_MOTOR, 0, 4),  // M5 Rear Upper
    DEF_TIM(TIM3, CH4, PB1,  TIM_USE_MOTOR, 0, 5),  // M6 Rear Lower

    // TIM1 — Motors 7-8 (PE9, PE11) — DMA2 Stream 6-7
    DEF_TIM(TIM1, CH1, PE9,  TIM_USE_MOTOR, 0, 6),  // M7 Left Upper
    DEF_TIM(TIM1, CH2, PE11, TIM_USE_MOTOR, 0, 7),  // M8 Left Lower
};
