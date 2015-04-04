/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 1984-2015  Benjamin D Lunt (fys [at] fysnet [dot] net)
//
//  This firmware is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This firmware is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
/////////////////////////////////////////////////////////////////////////

// http://www.fysnet.net/attiny2313.htm
#include <avr/io.h>
#include <avr/interrupt.h>  // for sei()

#include <util/delay.h>     // for _delay_ms()

int main(void) {
  
  // make bottom 2 PORTB pins output
  DDRB = 3;
  
  while (1) {        // main event loop
    PORTB = 1; // Turn LED on PB0 on and PB1 off
    _delay_ms(500); 
    PORTB = 2; // Turn LED on PB0 off and PB1 on
    _delay_ms(500); 
  }
  
  return 0;
}
