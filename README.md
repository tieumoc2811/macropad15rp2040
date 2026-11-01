# Macropad15 - firmware RP2040 (Pro Micro RP2040), khong LED

Firmware tu viet (Pico SDK) giong ban RP2350: 15 phim + 3 nut nhan encoder + 3 encoder, OLED SSD1306,
Nokia multitap, tap dance, combo, latch, 16 macro, doi ten layer, cau hinh bang `firmware/macropad15.html` (WebHID).
Da bo het LED (WS2812 / day den / den onboard) va PIO.

## Chan (lay theo ban Vial)
| Chuc nang | Chan |
|---|---|
| Hang R0..R3 | GP1, GP0, GP2, GP3 |
| Cot C0..C4 | GP7, GP8, GP29, GP28, GP4 |
| Encoder 1 / 2 / 3 (A,B) | GP5,GP6 / GP26,GP27 / GP23,GP22 |
| OLED SSD1306 (I2C0) | SDA = GP20, SCL = GP21 |

Ma tran diode ROW2COL, giu nguyen vi tri phim nhu ban RP2350 (phim = hang*5 + cot, nut encoder o cot C4 -> vi tri 4, 9, 14).

## Build
1. Day repo len GitHub -> tab Actions -> "Build RP2040 firmware" -> tai artifact `macropad15_rp2040_uf2`.
2. Hoac build tay: `cd firmware && mkdir build && cd build && cmake .. -DPICO_BOARD=pico && make` (can Pico SDK 2.1.1).
3. OLED 0.91" (128x32): them `-DOLED_H=32`. Mac dinh 128x64 nhu ban Vial.

## Nap
Giu BOOT, cam USB (hoac bam RESET 2 lan) -> o `RPI-RP2` -> keo `macropad15.uf2` vao.
Nen nap `flash_nuke.uf2` truoc neu board dang chay Vial (xoa EEPROM cu), sau do nap firmware nay.

## Cau hinh
Mo `firmware/macropad15.html` bang Chrome/Edge, bam ket noi (VID `0xC1A0`, PID `0x0017`).

## Luu y
- Cac cai dat LED trong app van hien nhung firmware bo qua, khong co tac dung. Phim LED (`KC_LEDFX`) gan trong app cung khong lam gi.
- Encoder quay nguoc chieu: doi cho 2 chan cua encoder do trong mang `encp` o dau `main.c`.
- Du lieu cau hinh nam o cuoi flash 2MB (`PICO_BOARD=pico`), dung duoc cho board flash >= 2MB.
- Nut BOOT tren board: bam 1 lan = chuyen layer ke tiep.
