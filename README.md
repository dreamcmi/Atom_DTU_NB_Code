# ATomDTU Code

## 一、简介

本项目使用M5Stack公司推出的AtomDTU-NB产品，使用Arduino框架做一些小demo。

AtomDTU-NB采用的是esp32-pico+sim7020c组合，以AT指令进行数据指令交互。

## 二 、准备工作

1、Arduino环境

2、ESP32支持包 [仓库跳转](https://github.com/espressif/arduino-esp32)

3、AtomDTUNB支持库 [仓库跳转](https://github.com/m5stack/ATOM_DTU_NB)

## 三、代码目录

- [AT-test](./AT-test/AT-test.ino) ：使用Atom的本身串口模拟与SIM7020C进行AT指令交互，用于AT指令的测试。

- [Socket-TCP](./Socket-TCP/Socket-TCP.ino) : Socket TCP功能演示

