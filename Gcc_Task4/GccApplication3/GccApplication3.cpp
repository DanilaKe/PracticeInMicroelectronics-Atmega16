// �������� ��������� ��� LCD, ���� 8 ���
#include <avr/io.h>
#include <util/delay.h>

#define RS PC0 // RS ���������� � PC0 ����������������
#define EN PC2 // EN ���������� � PC2 ����������������

// ������� ������ ������� � LCD
void lcd_com(unsigned char p)
{
	PORTC &= ~(1 << RS); // RS = 0
	PORTC |= (1 << EN); // EN = 1 (������ ������ ������� � LCD)
	PORTD = p; // ����� ������� �� ���� DB0-7 LCD
	_delay_us(100); // ������������ ������� EN
	PORTC &= ~(1 << EN); // EN = 0 (����� ������ ������� � LCD)
	_delay_us(100); // ����� ��� ���������� �������
}

// ������� ������ ������ � LCD
void lcd_dat(unsigned char p)
{
	PORTC |= (1 << RS)|(1 << EN); // RS = 1, EN = 1 (������ ������ ������� � LCD)
	PORTD = p; // ����� ������� �� ���� DB0-7 LCD
	_delay_us(100); // ������������ ������� EN
	PORTC &= ~(1 << EN); // EN = 0 (����� ������ ������� � LCD)
	_delay_us(100); // ����� ��� ���������� �������
}

// ������� ������������� LCD
void lcd_init(void)
{
	DDRC |= (1 << PC2)|(1 << PC1)|(1 << PC0); // PC2-0 ������
	PORTC = 0x00; // ���. ���� �� ������
	DDRD = 0xFF; // PD7-0 ������
	PORTD = 0x00; // ���. ���� �� ������
	lcd_com(0x08); // ������ ���������� �������
	lcd_com(0x38); // 8 ��� 2 ������
	_delay_us(100);
	lcd_com(0x38); // 8 ��� 2 ������
	_delay_us(100);
	lcd_com(0x38); // 8 ��� 2 ������
	lcd_com(0x01); // ������� �������
	_delay_us(100);
	lcd_com(0x06); // ����� ������� ������
	_delay_ms(10);
	lcd_com(0x0C); // ������ �������
}

// �������� ���������
int main (void)
{
	lcd_init(); // ������������� �������
	lcd_dat('H'); // ������� ������� �� �����
	lcd_dat('e');
	lcd_dat('l');
	lcd_dat('l');
	lcd_dat('o');
	lcd_dat(' ');
	lcd_dat('w');
	lcd_dat('o');
	lcd_dat('r');
	lcd_dat('l');
	lcd_dat('d');
	lcd_dat('!');
	while(1)
	{
		// ������ ������ �� ������
	}
}