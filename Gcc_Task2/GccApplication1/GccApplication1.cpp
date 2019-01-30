// Мигание светодиодом
#define  F_CPU  8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRA = 0xFF;
	PORTA = 0x01;
	while (1) {
		PORTA = PORTA<<1;
		if(PORTA == 0x00)
			PORTA = 0x01;
		_delay_ms(100);
	}
}