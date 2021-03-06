#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#define e1 PORTD|=0b00001000
#define e0 PORTD&=0b11110111
#define rs1 PORTD|=0b00000100
#define rs0 PORTD&=0b11111011

void port_ini(void)
{
	PORTD=0x00;
	DDRD=0xFF;
}
void sendhalfbyte(unsigned char c)
{
	_delay_ms(15);
	c<<=4;
	e1;
	_delay_us(50);
	PORTD&=0b00001111;
	PORTD|=c;
	e0;
	_delay_us(50);
	
}
void sendbyte(unsigned char c, unsigned char mode)
{
	if (mode==0) rs0;
	else rs1;
	unsigned char hc=0;
	hc=c>>4;
	sendhalfbyte(hc); sendhalfbyte(c);
}
void sendchar(unsigned char c)
{
	sendbyte(c,1);
}
void LCD_ini(void)
{
	_delay_ms(15);
	sendhalfbyte(0b00000011);
	_delay_ms(4);
	sendhalfbyte(0b00000011);
	_delay_us(100);
	sendhalfbyte(0b00000011);
	_delay_ms(1);
	_delay_ms(1);
	sendhalfbyte(0b00000010);
	_delay_ms(1);
	_delay_ms(1);
	sendbyte(0b00101000, 0);
	_delay_ms(1);
	sendbyte(0b00001100, 0);
	_delay_ms(1);
	sendbyte(0b00000110, 0);
	_delay_ms(1);
}
void setpos(unsigned char x, unsigned y)
{
	char adress;
	adress=(0x40*y+x)|0b10000000;
	sendbyte(adress, 0);
}
void sendstring(char str[])
{
	int i = 0;
	while(str[i]!='\0')
	{
		sendchar(str[i]);
		i++;
	}
}
int main(void)
{
	port_ini();
	LCD_ini();
	sendstring("KEDRINSKII");
	setpos(1,4);
	sendstring("DANILA");
	_delay_ms(3000);
	sendbyte(0x01,0);
    while(1)
	{
		asm("NOP");
	}
}