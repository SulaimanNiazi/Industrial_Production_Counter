# Industrial Production Counter

This project is a firmware application designed for the PIC16F877A microcontroller to count industrial production items. It displays the count and rate on LM016L LCD. The rate is refreshed every 10 seconds. 
The firmware is developed using the MPLAB X IDE and the XC8 compiler.

<video title="Industrial Production Counter Simulation Video" width="100%" controls autoplay>
    <source src="./Proteus Simulation/Industrial Production Counter Simulation Video.mp4">
    Your browser does not support the video tag.
</video>

## Table of Contents

- [Prerequisites](#prerequisites)
- [Building the Project](#building-the-project)
- [Apparatus](#apparatus)
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

## Apparatus 

Necessary components that can't be changed:

1. PIC16F877A microcontroller: To run the program.
1. LM016L LCD display: To display output.
1. Quartz Crystal and 2 1nF non polarized capacitors.

Optional components depending on your circuit:

1. Button: For clear input button.
1. LED: To indicate that an item is being detected.
1. OP-47 Op - Amp: For amplifying sensory input.
1. RLY-SPNO Magnetic Relay: to provide stable 5V to CCP pin.
1. Rheostat: To adjust op - amp potential according to sensor input
1. APDS-9002 Miniature Surface-mount Light Photo Sensor: For detecting the items.
1. 5 Resistors

## Uploading to the Microcontroller

After building the project, upload the generated `.hex` or `.cof` file to the PIC16F877A microcontroller using a suitable programmer.
The file can be find in either of the following paths:

1. In case of using MPLAB X IDE: [dist\default\debug\Industrial_Production_Counter.X.debug.hex](./dist/default/debug/Industrial_Production_Counter.X.debug.hex)
1. In case of using VScode (if the file name was set as default): [out\Industrial_Production_Counter\default.hex](./out/Industrial_Production_Counter/default.hex)
