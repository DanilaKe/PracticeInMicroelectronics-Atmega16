#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	while(1)
	{
		ADMUX = 0b01000000;
		ADCSRA = 0b11011111;
		PORTD = ADCL;
		PORTC = ADCH;
		_delay_ms(1000);
	}
}
