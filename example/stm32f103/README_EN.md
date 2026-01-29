# STM32F103C8T6 Oscilloscope UI Library Example

[中文页](README.md) | English

## Project Introduction

This project is an example application for the Oscilloscope UI Library (OSC.c/.h), developed based on the STM32F103C8T6 microcontroller and ILI9341 display, by Xingwen37. 

## Hardware Requirements

- STM32F103C8T6 microcontroller
- ILI9341 2.4-inch TFT display
- Necessary connection circuits

## Software Requirements

- Keil MDK-ARM development environment
- STM32F1xx HAL library

## File Structure

```
STM32F103C8T6_OSC/
├── Core/             # Core code directory
├── Drivers/          # Driver library directory
│   ├── CMSIS/        # CMSIS standard library
│   └── STM32F1xx_HAL_Driver/ # STM32F1 series HAL driver
├── MDK-ARM/          # Keil MDK project files
├── hardware/         # Hardware related code
│   └── screen/       # Display related code
│       ├── OSC.c     # Oscilloscope UI library implementation
│       ├── OSC.h     # Oscilloscope UI library header file
│       └── ili9341_driver.c/h # ILI9341 display driver
├── README.md         # Chinese project description file
└── README_EN.md      # English project description file
```

## Usage

1. Open the `MDK-ARM/teach_test.uvprojx` project file with Keil MDK-ARM
2. Compile the project and download it to the STM32F103C8T6 development board
3. Connect the ILI9341 display to the development board
4. Power on and run, you can see the oscilloscope UI interface

#