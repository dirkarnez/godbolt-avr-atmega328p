#define __AVR_ATmega328P__
#include <avr/io.h>

int main()
{
    PORTB = 0x01;
    DDRC = 0xFF;
    DDRD = 0xFF;
    
    
    //TCCR0 = 0x07;
    TCNT0 = 0x00;

    while (1) {
        do {
            PORTC = TCNT0;
        } while ((TIFR0 & (1 << TOV0)) == 0);

        TIFR0 = 0x1 << TOV0;
        PORTD++;
    }
}
