/////////////////////////////////////////////////////////////////////////
// Programcı: ORHAN YILMAZ                                             //
// Proje: GPS ile Konum Belirleme                                      //
// Üniversite: Dumlupınar Üniversitesi                                 //
// Danışman Hoca: Yrd.Doç.Dr.Ahmet ÖZMEN                               //
// Yazılım: GPS Modülünden gelen verilerden kullanılacak satırın       //
// yakalanarak gönderilmesi.					       //
/////////////////////////////////////////////////////////////////////////
#include "uart.h"
#define CS 83
 
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
 
	}
}
