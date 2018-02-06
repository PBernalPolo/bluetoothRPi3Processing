/*
 * Copyright (C) 2017 P.Bernal-Polo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *
 * @author P.Bernal-Polo
 */

// Connections:    Arduino     HC-05
//                  5V -------- VCC
//                  GND ------- GND
//                  pin 4 ----- TX
//                  pin 5 ----- RX

#include <SoftwareSerial.h>


SoftwareSerial btSerial( 4 , 5 );  // RX , TX  (in SoftwareSerial)
int i = 0;


void setup() {
  Serial.begin(115200);  // begin serial
  btSerial.begin(9600); // begin bluetooth
}


void loop() {
  // we write from the bluetooth
  btSerial.print( "Hi! I am Arduino: " );
  btSerial.println( i++ );
  // we read from the bluetooth
  while( btSerial.available() ){
    Serial.print( (char)btSerial.read() );
  }
  // we wait a little
  delay( 1000 );
}

