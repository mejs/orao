Orao: Yugoslav 8-bit school microcomputer
=====================================
![logo](/imgs/orao2007.jpg)

Orao was an 8-bit computer developed by Miroslav Kocijan for PEL Varaždin in 1984. This repo includes roms, programs and tools for working with this computer. 

I've built a replica of this computer based on [Josip Perušanec's Orao 2007 project](http://www.deltasoft.com.hr/projects/orao2007.php?title=Orao%202007). This replica is fully compatible with the original, but it uses a single EPROM and RAM instead of multiple ones like the original.

### [Roms](https://github.com/mejs/orao/tree/master/roms)
There were 2 roms for the Orao:
* ROM 102: first rom version with basic (sic) BASIC and monitor program. This rom is in BCS.
* ROM 103: second rom version with advanced BASIC and monitor program. This rom is in English

Both of these roms were originally stored on two 2764 EPROMs, one would have the BASIC and the other the monitor. The version I have here combines both the 102 and 103 ROM versions with both BASIC and monitor into a single hex bin for loading onto a 27256 EPROM.

### [Orao keyboard](https://github.com/mejs/orao/tree/master/orao_keyboard)
![keyboard](/imgs/keyboard.png)

Since I don't own an original Orao, I needed a way to connect a regular PS2 keyboard to the replica. This is a work in progress project for an Arduino based interface that uses an MT8816 analog switch matrix to use a PS2 keyboard with the Orao. The interface supports all Orao keys and key combinations including PF keys, control and shift key support. You can find the list of all Orao key combinations [here (in BCS)](https://github.com/mejs/orao/tree/master/orao_keyboard/combinations.png) I've used an Arduino Mega for testing.

![kbdschematics](/imgs/kbdschematics.jpeg)

Orao's keyboard input works by shorting connections between 6 data lines (D4-D7) and 10 address lines (A0-A9). When a key is pressed, the connection is shorted between corresponding lines to input a key press. I.e., to type "A", the key short address line A7 and data line D5. MT8816 is an analog switch relay. It contains a 8 x 16 array of crosspoint switches along with a 7 to 128 line decoder and latch circuits. The 8 lines are labeled Y0-Y7, and the 16 lines are labelled X0-X15. MT8816 can connect any Y line with any X line, and it can make multiple concurrent connections. Y1 to Y6 lines are connected to Orao's keyboard connector pins 1-6 (data lines D4-D7), and X0 to X9 are connected to Orao keyboard connector pins 7-16 (address lines A0-A9).

MT8816 connections are selected by seting bits on address inputs AX0-Ax3 and AY0-AY3. The addresses are defined in the [MT8816 datasheet](https://github.com/mejs/orao/tree/master/orao_keyboard/MT8816-datasheet.pdf) in Table 1 - Address Decode Truth Table on page 11. Address inputs are connected to Arduino digital I/O pins 31-37. Arduino uses PS2KeyAdvanced library to read keycodes from the connected PS/2 keyboard, connected to digital I/O pins 2 and 3. When a key is pressed (i.e. 32833 for A), Arduino sets the bits on the address inputs (1100101 for A), raises MT8816 data pin to save it to memory, raises and lowers strobe, holds for 22ms, then lowers data and raises reset. This makes the connection between A7 and D5 on the Orao.


Due to the physical difference between modern, Model-M compatible keyboards and Orao's keyboard, I've made the following key placement decisions:

* Insert key is used for * : Orao key
* Home key is used for / ? Orao key
* Backspace is used as left arrow key in addition to the actual left arrow key because it effectively works as backspace

This project was inspired by Marko Šolajić's [galaksija-keyboard-interface project](https://github.com/msolajic/galaksija-keyboard-interface) and the [C64-keyboard project](https://github.com/Hartland/C64-Keyboard)

orao_keyboard is still a prototype, and my next step is to design and manufacture it as PCB.

### [Gerbers](https://github.com/mejs/orao/tree/master/schematics)

The gerbers files hosted on Josip Perušanec's website include [one connection missing in the gerbers](https://twitter.com/mejs/status/1338876219308322817), preventing video output without an additional jumper. The version hosted here fixes this.

### [Manuals](https://github.com/mejs/orao/tree/master/manuals)
![keyboard](/imgs/kit.jpg)
I've used a number of manuals while working on the Orao, especially the manual for the never released DIY kit that was [posted online by RetroInfo](https://retroinfo.hr/dvije-knjige-za-pel-orao/). 
