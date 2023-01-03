 
 
 
/*********************************************************************************
 ** Proje Başlığı: GPS ile Konum Belirleme					**
 ** Proje bağlantısı: http://www.mcu-turkey.com/?p=1938				**
 **-----------------------------------------------------------------------------**
 ** Proje Yürütücüsü: Orhan YILMAZ						**
 ** Danışman Hoca: Yrd.Doç.Dr.Ahmet ÖZMEN					**
 ** Üniversite: Dumlupınar Üniversitesi						**
 ** Bölüm: Elektrik - Elektronik Mühendisliği 					**
 ** ----------------------------------------------------------------------------**
 ** Not: Danışman hocamın yardımıyla tamamladığım uart uygulamasına 		**
 ** değişiklikler yapılarak kütüphane haline getirildi.				**
 ** Şuan değişiklik yapmadan,fonksiyonlar çağırılarak standart kütüphane gibi 	**
 ** kullanılabilir.								**
 ********************************************************************************/
 
//******************************************************************************
//  MSP430G2xx1 - Timer_A, Ultra-Low Pwr UART 9600, 32kHz ACLK
//******************************************************************************
#include "msp430g2231.h"
 
//------------------------------------------------------------------------------
// Hardware-related definitions
//------------------------------------------------------------------------------
#ifndef UART_TXD
#define UART_TXD   0x02 		// TXD on P1.1 (Timer0_A.OUT0)
#endif
 
#ifndef UART_RXD
#define UART_RXD   0x04                 // RXD on P1.2 (Timer0_A.CCI1A)
#endif
//------------------------------------------------------------------------------
// Conditions for 9600 Baud SW UART, SMCLK = 1MHz
//------------------------------------------------------------------------------
#define CLK 1000000
 
#ifndef BAUND
#define BAUND 9600
#endif
 
#define UART_TBIT_DIV_2     (CLK / (BAUND * 2))
#define UART_TBIT           (CLK / BAUND) 
 
//------------------------------------------------------------------------------
// Global variables used for full-duplex UART communication (Global Değişkenler)
//------------------------------------------------------------------------------ 
 
unsigned int txData;                        // UART internal variable for TX
unsigned char rxBuffer;                     // Received UART character 
 
//------------------------------------------------------------------------------
// Function prototypes (Fonksiyonlar)
//------------------------------------------------------------------------------
void UARTInit(void);
void SendByte(unsigned char byte);
void SendStr(char *string);
unsigned char RecvByte(void);
void RecvStr(char *msg, unsigned char n);
void RecvStrTEMP(void);
 
 
 
 
