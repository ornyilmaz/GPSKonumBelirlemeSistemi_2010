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
#define Clk BIT4
#define Data BIT5
#define Storage BIT7
 
void delay(unsigned long int);
void hc595_yaz(unsigned char);
void lcd_write(unsigned char);
void lcd_putch(unsigned char);
void lcd_puts(const char*);
void lcd_temizle(void);
void lcd_goto(char,char);
void lcd_init(void);
