#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	DDRB = 0xFF;
	DDRA = 0xFF;
	while(1)
	{
		PORTA = 0xff;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTA = 0b00000001;
		PORTB = 0b00000001;
		PORTC = 0b00000001;
		PORTD = 0b00000001;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		_delay_ms(10000);
		PORTA = 0b00010000;
		PORTB = 0b00101100;
		PORTC = 0b00101100;
		PORTD = 0b00010000;
		_delay_ms(10000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
	}
}
