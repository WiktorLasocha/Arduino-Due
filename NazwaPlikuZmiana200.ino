//-------------nazwa pliku  int+dec or char--------------//
#include <SPI.h>
#include <SD.h>
char x;
char y;
long zmienna=0;
int dec1=75;
int dec2=65;
String nazwa1;
String nazwa2;
String nazwa;
File myFile;
void setup() {
  Serial.begin(9600);
  while (!Serial)
  {
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(53))
  {Serial.println("initialization failed!");return;}
  Serial.println("initialization done.");
  //}
}
///////////////////////////////////////////////////
void loop() {  nadanie_nazwy();odczyt_pliku();}
//--------------------------
void odczyt_pliku()
{
 myFile = SD.open(nazwa);
 if(myFile){Serial.println(nazwa);
 while(myFile.available())
 {
  Serial.write(myFile.read());
 }
  myFile.close();}else{
  Serial.println("error opening test.txt");}
 }
//-------------------------------
void nadanie_nazwy()
{
  Serial.println("nazwa...");
  zmienna=65000;
  x=(dec1);
  y=(dec2);
  Serial.println(x);
  Serial.println(y);
  nazwa2=String(x)+String(y);//lub dec1,dec2,
  // nazwa2="bb";
  nazwa1=String(zmienna);
  nazwa=(nazwa1+nazwa2)+".txt";;
  //myFile = SD.open(nazwa, FILE_WRITE);
  //myFile.close();
}


