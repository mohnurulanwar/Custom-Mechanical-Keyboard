# 🧠 Custom Mechanical Keyboard (ATmega32A + QMK Firmware)

This project is a custom mechanical keyboard designed from scratch using **KiCad** for schematic and PCB layout, and programmed with **QMK Firmware** to enable advanced keyboard functionalities. The final firmware is compiled into a `.hex` file and uploaded to the **ATmega32A microcontroller** using **QMK Toolbox**.

---

## 🧩 Features

- Custom PCB layout with full schematic
- Uses ATmega32A microcontroller (custom QMK port)
- Programmed using QMK Firmware
- Flashing with QMK Toolbox (.hex file)
- Designed to work with standard mechanical key switches
- USB powered with basic protection components

---

## 🧰 Components Used

| Component                | Description                         |
|--------------------------|-------------------------------------|
| **ATmega32A**            | Microcontroller (40-pin DIP)        |
| **Crystal Clock 16MHz**  | External clock source               |
| **Resistors**            | Pull-up/down and current limiting   |
| **Ceramic Capacitors**   | Decoupling and oscillator support   |
| **Electrolytic Capacitors** | Power filtering                  |
| **PTC Resettable Fuse**  | Overcurrent protection              |
| **Zener Diodes**         | Voltage clamping/protection         |
| **LEDs**                 | Indicator LEDs                      |
| **Key Switches**         | Mechanical switches (1 per key)     |

---

## 🖥️ Software & Tools

| Tool            | Usage                                |
|----------------|--------------------------------------|
| **KiCad**       | PCB and schematic design             |
| **QMK Firmware**| Keyboard firmware and keymap config  |
| **QMK Toolbox** | Flash `.hex` file to ATmega32A       |
| **Python**      | QMK CLI toolchain setup              |
| **Git**         | Version control                      |

---

## 📐 KiCad Design

The schematic and PCB are created using **KiCad**. It includes:

- Power regulation
- USB connection with basic ESD protection
- Matrix wiring for switches (rows & columns)
- Crystal oscillator circuit for ATmega32A
- Resettable fuse and zener diode protection

### 🗂 Files:
- `/hardware/*.sch` – Schematic
- `/hardware/*.kicad_pcb` – PCB layout
- `/hardware/gerber/` – For PCB manufacturing

---

## ⌨️ QMK Firmware Setup

> Since QMK officially supports ATmega32U4, using ATmega32A requires a custom port with an external USB interface (e.g., V-USB). This project assumes such setup is handled.

### Steps:

1. **Clone QMK Firmware**:
`
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
`
2. Create custom keyboard folder:
Put your keyboard files into:
`
qmk_firmware/keyboards/your_keyboard/
`
3. Add keymap:
Define your keymap in:
`
keyboards/your_keyboard/keymaps/default/keymap.c
`
4. Compile firmware:
`
qmk compile -kb your_keyboard -km default
`
Result: your_keyboard_default.hex
----------------------------------------------------------
🚀 Flash Firmware to ATmega32A
1. Using QMK Toolbox:
2. Open QMK Toolbox
3. Load the .hex file from build output
4. Connect keyboard to USB (enter bootloader mode)
5. Press Flash
