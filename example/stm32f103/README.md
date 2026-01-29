# STM32F103C8T6 示波器UI库示例

中文页 | [English](README_EN.md)

## 项目简介

本项目是示波器UI库（OSC.c/.h）的示例应用，基于STM32F103C8T6微控制器和ILI9341显示屏开发，由Xingwen37编写。

## 硬件要求

- STM32F103C8T6 微控制器
- ILI9341 2.4英寸TFT显示屏
- 必要的连接电路

## 软件要求

- Keil MDK-ARM 开发环境
- STM32F1xx HAL 库

## 文件结构

```
STM32F103C8T6_OSC/
├── Core/             # 核心代码目录
├── Drivers/          # 驱动库目录
│   ├── CMSIS/        # CMSIS 标准库
│   └── STM32F1xx_HAL_Driver/ # STM32F1系列HAL驱动
├── MDK-ARM/          # Keil MDK项目文件
├── hardware/         # 硬件相关代码
│   └── screen/       # 显示屏相关代码
│       ├── OSC.c     # 示波器UI库实现
│       ├── OSC.h     # 示波器UI库头文件
│       └── ili9341_driver.c/h # ILI9341显示屏驱动
├── README.md         # 中文项目说明文件
└── README_EN.md      # 英文项目说明文件
```

## 使用方式

1. 使用Keil MDK-ARM打开 `MDK-ARM/teach_test.uvprojx` 项目文件
2. 编译项目并下载到STM32F103C8T6开发板
3. 连接ILI9341显示屏到开发板
4. 上电运行，即可看到示波器UI界面

