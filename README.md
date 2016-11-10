# trampuino
An runner game for the trampoline RTOS (github.com/TrampolineRTOS/trampoline)

## Requirement

Hardware : You need an Arduino uno and a LCD12864 Shield (V1.0) to run it.

Software : 
- trampoline RTOS with U8glib integreted.
- Python installed
- goil installed
- avrdude installed 

## Build instructions

Integrate this project in trampoline root directory (in a src/ directory for example)

Go into this project directory

To build the project run :

```
$ goil --target=avr/arduino/uno --templates=../goil/templates/ main.oil
```

To compile it : 

```
$ ./make.py
```

To flash it in the arduino (assuming /dev/ttyACM0 is the arduino tty):

```
$ sudo avrdude -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:trampuinoDino.hex
```
