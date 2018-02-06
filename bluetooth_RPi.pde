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
 
import processing.serial.*;


Serial sp;
int i = 0;

void setup(){
  // we define the serial port (a symbolic link must have been previously created)
  sp = new Serial( this , "/dev/rfcomm0" , 9600 );
}


void draw(){
  // we write to the bluetooth
  sp.write( "Hi! I am Processing: " + i++ + "\n" );
  // we read from the bluetooth
  while( sp.available() > 0 ){
    print( (char)sp.read() );
  }
  // we wait a little
  delay( 1000 );
}