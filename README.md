# GPSKonumBelirlemeSistemi_2010
2010 Yılı MCU-TURKEY için hazırlanmış olan yarışma kodlarını içerir.

ORHAN YILMAZ, 14 Kasım 2010, Pazar
---
Proje Amacı       : GPS modül ile seri port üzerinden alınan verilerin ayrıştırılarak LCD yardımıyla kullanıcıya sunulması.

Proje Sahibi      : Orhan YILMAZ
Proje Danışmanı   : Yrd.Doç.Dr. Ahmet Özmen
Üniversite        : Dumlupınar Üniversitesi
Bölüm             : Elektrik-Elektronik Mühendisliği


Proje Detayları
---
GPS Nedir: GPS (Global Positioning System; Küresel Konumlama Sistemi), düzenli olarak kodlanmış bilgi yollayan bir uydu ağıdır ve uydularla arasındaki mesafeyi ölçerek Dünya üzerindeki kesin yeri tespit etmeyi mümkün kılar.(tr.wikipedia.org) Kullanımı ücretsizdir.

GPS modülü olarak piyasada bulabileceğim, Sirfstar3 çipli ve seri port üzerinden direk çalıştırılabilen modülü kullanmayı düşündüm.
Bu işlem MSP430 kontrolörün Rx – Tx haberleşme portu üzerinden direk haberleştirme işlemiyle başlıyor. Devamında alınan verilerin çözülmesi ve son olarak Lcd display’e yazılması işlemiyle son buluyor.
