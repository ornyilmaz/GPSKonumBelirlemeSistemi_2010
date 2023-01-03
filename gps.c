/////////////////////////////////////////////////////////////////////////
// Programcı: ORHAN YILMAZ                                             //
// Proje: GPS ile Konum Belirleme                                      //
// Üniversite: Dumlupınar Üniversitesi                                 //
// Danışman Hoca: Yrd.Doç.Dr.Ahmet ÖZMEN                               //
// Yazılım: GPS Modülünden gelen verilerden kullanılacak satırın       //
// ayrıştırılması ve ayrıştırılmış verinin gönderilmesi.               //
/////////////////////////////////////////////////////////////////////////
 
#include "uart.h"
#define CS 83
unsigned char i,j=0,k;
 
void Data(char *ch);
void main(void)
{
	char ch[CS];
 
	uart();	//Temel uart konfigürasyonu çağrısı...
	RecvStrTEMP(); //İlk olarak 2 satır Modul versiyon bilgisi gelir ve
	RecvStrTEMP(); //proje için çöp veridir.
 
	for(;;)
	{
 
		RecvStr(ch,CS);	//$GPGGA anahtarlı veri alınıyor.
		RecvStrTEMP();	//Gereksiz bilgi...
		RecvStrTEMP();	//Gereksiz bilgi...
		RecvStrTEMP();	//Gereksiz bilgi...
		SendStr(ch);	//Okunan veri gönderiliyor.
		Data(ch);
 
	}
}
 
 void Data(char *ch)
{
	j=0;
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
								SendStr("rn----------rn");
								SendStr("UTC Saati:");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 2:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Enlem:");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 3:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Kutup(N-S):");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 4:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Boylam:");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 5:
							if(k == 0)
							{
								SendStr("rn");
								SendStr("Dogu-Bati(E-W):");
								k++;
							}
							if(*(ch+i) != ',')
								SendByte(*(ch+i));
							break;
						case 6:
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
						default:
							break;
					}
				}
 
}
