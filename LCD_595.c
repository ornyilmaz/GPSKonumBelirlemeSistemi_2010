/*********************************************************************************
 ** Proje Başlığı: GPS ile Konum Belirleme					**
 ** Proje bağlantısı: http://www.mcu-turkey.com/?p=1938				**
 **-----------------------------------------------------------------------------**
 ** Proje Yürütücüsü: Orhan YILMAZ						**
 ** Danışman Hoca: Yrd.Doç.Dr.Ahmet ÖZMEN					**
 ** Üniversite: Dumlupınar Üniversitesi						**
 ** Bölüm: Elektrik - Elektronik Mühendisliği 					**
 ** ----------------------------------------------------------------------------**
 ** 										**
 ** Not: "Muhammet Fatih İnanç" Arkadaşımızın paylaşmış olduğu "IAR" derleyici 	**
 ** ortamı içinde yazılmış olan kodlardan yararlanılarak,"Code Composer Studio" **
 ** derleyicisi için tekrar hazırlandı.	Fatih arkadaşıma teşekkür ederim...	**
 ********************************************************************************/
 
#include "msp430.h"
#include "LCD_595.h"
 
#define E_1     0x08
#define RS_E_1  0x0C
 
void delay(unsigned long int d)
{
  	d*=100;
  	for(;d>0;d--);
}
 
void hc595_yaz(unsigned char gelen)
{
	char i;
  	for(i=8;i>0;i--)
  	{
		P1OUT &= ~Data;
    	if(gelen & 0x80)
    		P1OUT |= Data;
    	P1OUT |= Clk;
    	P1OUT &= ~Clk;
    	gelen*=2;
  	}
  	P1OUT |= Storage;
  	P1OUT &= ~Storage;
}
 
void lcd_write(unsigned char port)
{
  //ilk 4 bit gönderiliyor...
  	hc595_yaz(E_1);
  	hc595_yaz(( port & 0xF0) | E_1);
  	hc595_yaz(((port & 0xF0) | E_1) & 0xF0);
  //Son 4 bit gönderiliyor...
  	hc595_yaz(E_1);
  	hc595_yaz(( port<<4 ) | E_1);
  	hc595_yaz(((port<<4 ) | E_1) & 0xF0);
}
 
void lcd_putch(unsigned char port)
{
  //ilk 4 bit gönderiliyor...
  	hc595_yaz(RS_E_1);
  	hc595_yaz(( port & 0xF0 ) | RS_E_1);
  	hc595_yaz(((port & 0xF0 ) | RS_E_1) & 0xF4);
  //Son 4 bit gönderiliyor...
  	hc595_yaz(RS_E_1);
  	hc595_yaz(( port<<4) | RS_E_1);
  	hc595_yaz(((port<<4) | RS_E_1) & 0xF4);
}
 
void lcd_puts(const char * s)
{
  	_nop();
  	while(*s)
    	lcd_putch(*s++);
}
 
void lcd_temizle(void)
{
  	lcd_write(0x1);
  	delay(2);
}
 
void lcd_goto(char x, char y)
{
	if(x==1)
    	lcd_write(0x80+((y-1)%16));
  	else
    	lcd_write(0xC0+((y-1)%16));
}
 
void lcd_init(void)
{	//Çıkış Portları Ayarlanıyor..
	P1DIR |= Clk|Data|Storage;
 
	//Clk,Data,Storage portları başlangıçta
	//sıfırlanıyor..
	P1OUT &= ~(Clk|Data|Storage);
 
	//LCD hazırlanıyor..
  	hc595_yaz(0x00);
 	delay(15);
  	hc595_yaz(0x08);
  	lcd_write(0x02);  // İmleç 0x0 konumunda
  	delay(2);
 
	lcd_write(0x28);  // 4 Bit , Çift Satır LCD
  	lcd_write(0x0C);  // İmleç Gizleniyor
  	lcd_temizle();    // Ekran Temizleniyor
  	lcd_write(0x06);  // Sağa doğru yazma aktif
  	lcd_write(0x80);  // LCD Birinci Satır Konumunda
}
