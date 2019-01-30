#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRD = 0x00;
	DDRC = 0xFF;
	DDRB = 0xFF;
	DDRA = 0xFF;
	while(1)
	{
		if(PIND&(1 << PD0))
		{
		DDRD = 0xFF;
		PORTA = 0b00111100;
		PORTB = 0b01000010;
		PORTC = 0b01000010;
		PORTD = 0b00111100;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD1))
		{
		DDRD = 0xFF;
		PORTA = 0b01001000;
		PORTB = 0b01000100;
		PORTC = 0b01111110;
		PORTD = 0b01000000;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD2))
		{
		DDRD = 0xFF;
		PORTA = 0b01000100;
		PORTB = 0b01100010;
		PORTC = 0b01010010;
		PORTD = 0b01001100;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD3))
		{
		DDRD = 0xFF;
		PORTA = 0b00100100;
		PORTB = 0b01000010;
		PORTC = 0b01011010;
		PORTD = 0b00100100;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD4))
		{
		DDRD = 0xFF;
		PORTA = 0b00001110;
		PORTB = 0b00001000;
		PORTC = 0b00001000;
		PORTD = 0b01111110;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD5))
		{
		DDRD = 0xFF;
		PORTA = 0b00101110;
		PORTB = 0b01001010;
		PORTC = 0b01001010;
		PORTD = 0b00110010;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD6))
		{
		DDRD = 0xFF;
		PORTA = 0b00111100;
		PORTB = 0b01010010;
		PORTC = 0b01010010;
		PORTD = 0b00100100;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
		if(PIND&(1 << PD7))
		{
		DDRD = 0xFF;
		PORTA = 0b00000010;
		PORTB = 0b01100010;
		PORTC = 0b00010010;
		PORTD = 0b00001110;
		_delay_ms(5000);
		PORTA = 0x00;
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
		DDRD = 0x00;
		}
	}
}
