# Industrial Production Counter

This project is a firmware application designed for the PIC16F877A microcontroller to count industrial production items. The firmware is developed using the MPLAB X IDE and the XC8 compiler.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Building the Project](#building-the-project)
- [Uploading to the Microcontroller](#uploading-to-the-microcontroller)


## Prerequisites

- MPLAB X IDE
- XC8 Compiler
- PIC16F877A Microcontroller

## Building the Project

1. Open the project in MPLAB X IDE.
1. Ensure the XC8 compiler is selected.
1. Build the project to generate the `.hex` or `.cof` file.
1. Alternatively, you can build the project using Visual Studio Code with the MPLAB extension. Set the project output file path, name, and extension using `Ctrl+Shift+P` and selecting "Edit Project Properties".

## Uploading to the Microcontroller

After building the project, upload the generated `.hex` or `.cof` file to the PIC16F877A microcontroller using a suitable programmer.
The file can be find in either of the following paths:

1. In case of using MPLAB X IDE: [dist\default\debug\Industrial_Production_Counter.X.debug.hex](./dist/default/debug/Industrial_Production_Counter.X.debug.hex)
1. In case of using VScode (if the file name was set as default): [out\Industrial_Production_Counter\default.hex](./out/Industrial_Production_Counter/default.hex)
