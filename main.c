/*///////////////////////////////////////////////////////////////////////
// Programcı: ORHAN YILMAZ                                             //
// Proje: GPS ile Konum Belirleme                                      //
//---------------------------------------------------------------------//
// Üniversite: Dumlupınar Üniversitesi                                 //
// Danışman Hoca: Yrd.Doç.Dr.Ahmet ÖZMEN                               //
//---------------------------------------------------------------------//
// Yazılım: GPS v0.1						       //
// Derleyici: Code Compose Studio v4.xx	 			       //
//								       //
// Amaç:Gerekli verilerin seçilerek LCD'de gösterilmesi ve Koordinat   //
// içeren GPS verisinin tekrar seri port üzerinden geri gönderilmesi   //
//								       //
//---------------------------TEŞEKKÜR----------------------------------//
// Danışman hocam Sn. Ahmet ÖZMEN 'e ve Modül PCB hazırlanmasında      //
// desteklerini esirgemeyen Sn. Fırat AYDEMİR 'e 		       //
// Teşekkürlerimi Sunarım...		   			       //
//-****************************************ORHAN YILMAZ***************-//
///////////////////////////////////////////////////////////////////////*/
 
#include "uart.h"
#include "LCD_595.h"
#define CS 83
 
void Data_w(char *ch);
void main(void)
{
	char ch[CS];
 
	uart();	//Temel uart konfigürasyonu çağrısı...
	lcd_init();
	lcd_temizle();
	lcd_goto(1,2);
	lcd_puts("ORHAN YILMAZ");
	lcd_goto(2,3);
	lcd_puts("MCU-TURKEY'11");
  	delay(1000);
  	lcd_temizle();
  	lcd_goto(1,1);
	lcd_puts("Uydudan Konum ");
	lcd_goto(2,1);
	lcd_puts("Aliniyor...");
	RecvStrTEMP();	//Gereksiz bilgi...
 
	for(;;)
	{
 
		RecvStr(ch,CS);	//$GPGGA anahtarlı veri alınıyor.
		Data_w(ch);		//Okunan veri ayrıştırılarak gönderilir..
 
  		//lcd_puts("DUMLUPINAR UNIV.");
  		//lcd_goto(2,2);
	}
}
 
 void Data_w(char *ch)
{
 unsigned char i,j=0,k;
 
	j=0;
	if(*ch == '$')
	if(*(ch+1) == 'G')
	if(*(ch+2) == 'P')
	if(*(ch+3) == 'G')
		if(*(ch+4) == 'G')
			if(*(ch+5) == 'A')
				for(i=0;i<CS;i++)
				{
					if(*(ch+i) == 'n')
						break;
 
				else if(*(ch+i) == ',')
					{
						j++;
						k = 0;
					}
					switch(j)
					{
						case 1:
							if(k == 0)
							{
								SendStr(ch);	//Onaylanan veri seri porttan gönderiliyor.
								//SendStr("rn----------rn");
								//SendStr("UTC Saati:");
								//////LCD////////
								lcd_temizle();
   								lcd_goto(1,1);
  								lcd_puts("UTC Saati:");
  								lcd_goto(2,1);
  								///////END LCD/////
								k++;
							}
							if(*(ch+i) != ',')
							{
							//	SendByte(*(ch+i));
 
								lcd_putch(*(ch+i));
							}
							break;
						case 2:
							if(k == 0)
							{
							//	SendStr("rn");
							//	SendStr("Enlem:");
								//////LCD////////
								delay(1000);
								lcd_temizle();
 
  								lcd_goto(1,1);
  								lcd_puts("Enlem:");
  								lcd_goto(2,1);
								k++;
							}
							if(*(ch+i) != ',')
							{
							//	SendByte(*(ch+i));
 
								lcd_putch(*(ch+i));
							}
							break;
						case 3:
						/*	if(k == 0)
							{
								//SendStr("rn");
								//SendStr("Kutup(N-S):");
								k++;
							}
						*/	if(*(ch+i) != ',')
							{
							//	SendByte(*(ch+i));
 
								lcd_putch(*(ch+i));
							}
							break;
						case 4:
							if(k == 0)
							{
							//	SendStr("rn");
							//	SendStr("Boylam:");
								//////LCD////////
								delay(1000);
								lcd_temizle();
   								lcd_goto(1,1);
  								lcd_puts("Boylam:");
  								lcd_goto(2,1);
 
								k++;
							}
							if(*(ch+i) != ',')
							{
							//	SendByte(*(ch+i));
 
								lcd_putch(*(ch+i));
							}
							break;
						case 5:
						/*	if(k == 0)
							{
								//SendStr("rn");
								//SendStr("Dogu-Bati(E-W):");
								k++;
							}
						*/	if(*(ch+i) != ',')
							{
							//	SendByte(*(ch+i));
 
								lcd_putch(*(ch+i));
							}
							break;
					/*	case 6:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("GPS Kalite:");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 7:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Baglanti Sayisi(Uydu):");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 8:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Yatay hassasiyet:");
								k++;
							}
							if(ch[i] != ',')
								SendByte(*(ch+i));
							break;
						case 9:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Rakim:");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							if(*(ch+i+1) == ',')
								SendStr("rn----------rnrn");
							break;
					*/	default:
                                                    if(j == 6)
                                                        delay(500);
                                                    if(j == 7)
                                                    {
						        lcd_temizle();
						        lcd_goto(1,1);
						        lcd_puts("Lutfen");
						        lcd_goto(2,3);
						        lcd_puts("Bekleyiniz...");
                                                    }
						break;
					}
				}
 
}
