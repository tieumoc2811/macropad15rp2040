// board.h - so do chan Macropad15 tren Pro Micro RP2040 (lay tu keyboards/macropad15/keyboard.json cua ban Vial).
// Moi chan deu co the doi bang -D khi chay cmake, vd: cmake .. -DLED_PIN=23   (dat -1 de tat)
#pragma once

// Ma tran 4 hang x 5 cot: diode ROW2COL (hang -> cong tac -> anode diode, cathode ve cot).
// Firmware keo hang len cao, doc cot (pull-down). Cot 4 = 3 nut nhan encoder: R0 = nho trai, R1 = nho phai, R2 = nut to.
#define ROW_PINS {1, 0, 2, 3}
#define COL_PINS {7, 8, 29, 28, 4}

// Encoder {A, B}. Chi so encoder = hang cua nut nhan cung nui xoay:
//   E1 (nut nhan R0) = nho trai: GP26/GP27,  E2 (R1) = nho phai: GP23/GP22,  E3 (R2) = nut to: GP5/GP6
// Neu mot nui xoay bi nguoc chieu: doi cho A va B cua nui do.
#define ENC_PINS {{26, 27}, {23, 22}, {5, 6}}

// OLED SSD1306 tren I2C0 (GP20 = SDA, GP21 = SCL)
#define OLED_SDA 20
#define OLED_SCL 21
#ifndef OLED_H
#define OLED_H 32            // 32 = OLED 0.91" (128x32, mac dinh) ; 64 = OLED 0.96" (128x64, cmake -DOLED_H=64)
#endif

// LED WS2812 (-1 = khong dung)
#ifndef LED_PIN
#define LED_PIN 25           // WS2812 onboard cua SparkFun Pro Micro RP2040 (GP25)
#endif
#ifndef EXT_PIN
#define EXT_PIN -1           // led 7 mau ngoai (ban RP2350 dung GP4; o day GP4 la cot ma tran nen tat)
#endif
#ifndef STRIP_PIN
#define STRIP_PIN 9          // day den 15 bong WS2812 (DIN): GP9 la chan con trong duy nhat tren Pro Micro
#endif
