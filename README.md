# Electric Heating Pad

<img src=heating_pad.jpeg alt="Heating pad circuitry " width=66%>

<p>
  This repository contains code and circuit diagram for building a feedback-controlled heating pad to regulate a mouse's body temperature while 
it is under anesthesia. The device monitors the mouse's body temperature, and supplies heat accordingly to maintain a temperature within a comfortable range.
</p>

Author(s): Alvin Adjei, University of California San Francisco

## Requirements

- 1 $\times$
  <a href="https://store.arduino.cc/products/arduino-uno-rev3?srsltid=AfmBOophdIvm8RfX5799wr4zovlr1sxV1jH-H7QClWuCym0v6gZN2AgC">
    Arduino Uno
  </a>
  or similar microcontroller (we used an
  <a href="https://www.adafruit.com/product/2488">
    Adafruit Metro Board
  </a>)
- 1 $\times$ potentiometer
- 1 $\times$
  <a href="https://www.adafruit.com/product/165">
    TMP36 temperature sensor
  </a>
- 1 $\times$
  <a href="https://www.adafruit.com/product/355">
    N-channel mosfet
  </a>
- 1 $\times$
  <a href="https://learn.adafruit.com/make-it-hot-or-cold/make-it-hot">
    electric heating pad
  </a>
- 1 $\times$
  <a href="https://www.sunfounder.com/collections/lcd-display/products/i2c-lcd1602-module">
    SunFounder LCD1602 Display Module
  </a>

## Assembly

<figure>
  <img src="Heating Pad Diagram.png" alt="Circuit Diagram" style="width:66%">
  <figcaption>
    Circuit diagram. The resistor on the breadboard represents the heating pad component.
    View circuit diagram in <a href="https://www.tinkercad.com/things/876OW5vUT7l-mouse-heating-pad-potentiometer">Tinkercad</a>.
  </figcaption>
</figure>
<br><br>
<img src="Heating Pad Schematic.png" alt="Circuit Schematic" style="width:66%">
