# Macropad15 - firmware RP2040 (Pro Micro RP2040)

Ban port tu firmware RP2350: giu nguyen tinh nang (15 phim + 3 encoder, HID + Raw HID, OLED, Nokia multitap, tap dance, combo, latch, macro, day LED 25 hieu ung, app cau hinh WebHID `firmware/macropad15.html`). Chi doi phan cung (so do chan nam het trong `firmware/board.h`).

## So do chan (lay tu ban Vial)
| Chuc nang | Chan |
|---|---|
| Hang R0..R3 | GP1, GP0, GP2, GP3 |
| Cot C0..C4 | GP7, GP8, GP29, GP28, GP4 (C4 = 3 nut nhan encoder: R0 nho trai, R1 nho phai, R2 nut to) |
| Encoder nho trai (E1) | GP26 / GP27 |
| Encoder nho phai (E2) | GP23 / GP22 |
| Encoder nut to (E3) | GP5 / GP6 |
| OLED SSD1306 (I2C0) | SDA GP20, SCL GP21 (mac dinh 128x64) |
| LED onboard WS2812 | GP25 (SparkFun Pro Micro RP2040) |
| Day den 15 bong WS2812 | GP9 (chan con trong duy nhat) |

Doi chan / OLED 128x32: sua `board.h` hoac them `-D` luc cmake, vd `cmake .. -DOLED_H=32 -DLED_PIN=23 -DSTRIP_PIN=9` (dat `-1` de tat). Neu mot nui xoay bi nguoc chieu, doi cho A va B cua nui do trong `ENC_PINS`.

## Build
GitHub Actions (`.github/workflows/build.yml`) -> tai artifact `macropad15_rp2040_uf2`, hoac tu may: `PICO_SDK_PATH=... cmake -DPICO_BOARD=pico .. && make`.

## Nap
Giu BOOT khi cam USB (hoac bam RESET 2 lan) -> o dia `RPI-RP2` -> keo `macropad15.uf2` vao. USB: VID 0xC1A0 / PID 0x0017. Cau hinh luu o sector cuoi cua 2 MB flash dau (cung bo cuc nhu ban RP2350), nen khong dung chung voi firmware Vial: lan dau nen nap `flash_nuke.uf2` neu truoc do da chay Vial.
