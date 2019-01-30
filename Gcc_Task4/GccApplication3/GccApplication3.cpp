// Тестовая программа для LCD, шина 8 бит
#include <avr/io.h>
#include <util/delay.h>

#define RS PC0 // RS подключаем к PC0 микроконтроллера
#define EN PC2 // EN подключаем к PC2 микроконтроллера

// Функция записи команды в LCD
void lcd_com(unsigned char p)
{
	PORTC &= ~(1 << RS); // RS = 0
	PORTC |= (1 << EN); // EN = 1 (начало записи команды в LCD)
	PORTD = p; // Вывод команды на шину DB0-7 LCD
	_delay_us(100); // Длительность сигнала EN
	PORTC &= ~(1 << EN); // EN = 0 (конец записи команды в LCD)
	_delay_us(100); // Пауза для выполнения команды
}

// Функция записи данных в LCD
void lcd_dat(unsigned char p)
{
	PORTC |= (1 << RS)|(1 << EN); // RS = 1, EN = 1 (начало записи команды в LCD)
	PORTD = p; // Вывод команды на шину DB0-7 LCD
	_delay_us(100); // Длительность сигнала EN
	PORTC &= ~(1 << EN); // EN = 0 (конец записи команды в LCD)
	_delay_us(100); // Пауза для выполнения команды
}

// Функция инициализации LCD
void lcd_init(void)
{
	DDRC |= (1 << PC2)|(1 << PC1)|(1 << PC0); // PC2-0 выходы
	PORTC = 0x00; // Лог. нули на выходе
	DDRD = 0xFF; // PD7-0 выходы
	PORTD = 0x00; // Лог. нули на выходе
	lcd_com(0x08); // Полное выключение дисплея
	lcd_com(0x38); // 8 бит 2 строки
	_delay_us(100);
	lcd_com(0x38); // 8 бит 2 строки
	_delay_us(100);
	lcd_com(0x38); // 8 бит 2 строки
	lcd_com(0x01); // Очистка дисплея
	_delay_us(100);
	lcd_com(0x06); // Сдвиг курсора вправо
	_delay_ms(10);
	lcd_com(0x0C); // Курсор невидим
}

// Основная программа
int main (void)
{
	lcd_init(); // Инициализация дисплея
	lcd_dat('H'); // Выводим символы на экран
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
		// Больше ничего не делаем
	}
}