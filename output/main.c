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
#include <avr/wdt.h>
#include <avr/interrupt.h>  // for sei()

#include <util/delay.h>     // for _delay_ms()

#include "usbdrv.h"

// -------------------------------------------------------------------------

// this gets called when custom control message is received 
USB_PUBLIC uchar usbFunctionSetup(uchar data[8]) { 
  usbRequest_t *rq = (void *)data; // cast data to correct type 
  
  if ((rq->bRequest >= 0) && (rq->bRequest <= 7)) { // custom command is in the bRequest field 
    PORTB ^= (1 << rq->bRequest); // toggle LED on pin
    return 0; 
  }
  
  return 0;
}

int main(void) {
  wdt_enable(WDTO_1S);
  usbInit();
  
  // make all PORTB pins output
  DDRB = 0xFF;
  PORTB = 0;
  
  sei();
  while (1) {        // main event loop
    wdt_reset();
    usbPoll();
  }
  
  return 0;
}
