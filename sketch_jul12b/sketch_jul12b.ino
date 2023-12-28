
#include<Wire.h>
#include<SPI.h>
#include<SoftwareSerial.h>
#include<hd44780.h>
#include<hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008,7,6,5,4,3,2,1,HIGH);


int led=10;
int light=A3;
int temp=A2;
int pot=A1;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
pinMode(led,OUTPUT);
pinMode(temp,INPUT);
pinMode(pot,INPUT);
pinMode(light,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

float t= analogRead(temp);
t=((t*0.125)-22.0);
Serial.print("temperature: ");
Serial.println(t);
float p= analogRead(pot);
int pt=map(p,0,100,0,255);
analogWrite(led,pt);
p=((p/1025)*100.0);

Serial.print("potvalue: ");
Serial.println(p);

float l= analogRead(light);
Serial.print("light intensity: ");
Serial.println(l);

lcd.clear();
  lcd.print("p: "); lcd.print(p); lcd.print("%");
  lcd.setCursor(8, 0);
  lcd.print("L: "); lcd.print(l); lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("T: "); lcd.print(t); lcd.print((char)223); lcd.print("C");


}


  
