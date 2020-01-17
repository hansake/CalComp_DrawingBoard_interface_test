# CalComp_DrawingBoard_interface_test
Test program for serial interface of CalComp DrawingBoard Model 23120

The CalComp DrawingBoard has a 25-pin D-sub connector where pin 7 is Gnd and pin 3 is Tx.
The default baud rate is 9600.
My DrawingBoard has Model Number: 23120 and Part Number: 15134-080114.

I could not find any information on Internet about the interface protocol of this device.
After some experimentation the following information was collected.
Making a driver based on this information is perhaps another project.

The tablet sends a continuous stream of characters (bytes) where each frame starts with a character with bit 7 set (0x80).
Each frame is 6 bytes long
* Byte 1 is the one with bit 7 set, the other bytes in the frame all have bit 7 reset.<br>
    Pressing button 0 sets bit 2 (0x04)<br>
    Pressing button 1 sets bit 3 (0x08)<br>
    Pressing button 2 sets bit 4 (0x10)<br>
    Pressing button 3 sets bit 5 (0x20)<br>
* Byte 2 most significant X value in bits 0 - 6<br>
* Byte 3 least significant X value in bits 0 - 6<br>
    The X value in byte 2 & 3 is 0 in left edge of drawing area. The right edge outputs 0x5d 0x5f (decimal 0 - 11999).<br>
* Byte 4 always 0<br>
* Byte 5 most significant Y value in bits 0 - 6<br>
* Byte 6 least significant Y value in bits 0 - 6<br>
    The Y value in byte 5 & 6 is 0 in bottom edge of drawing area. The top edge outputs 0x5d 0x5f (decimal 0 - 11999).<br>

Running the program:<br>
    hal@LinuxServer:~/digitizer$ ./dtest < /dev/ttyS0<br>
    Frame: [bc 31 2d 00 2e 0f]  X:  6317, Y:  5903, Button: 0 1 2 3 <br>
    Exit dtest<br>

Status of the digitizer is updated for each frame that is sent.
The program is stopped if all four buttons are pressed (or using Ctrl-C).
