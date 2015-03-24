#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "IRremote2.h"
#include <SoftwareSerial.h>

#define MAX_DG 15
LiquidCrystal_I2C lcd(0x27, 16, 2);
IRrecv irrecv(11); // Указываем пин, к которому подключен приемник
decode_results results;

String num; 
byte pos;

#define rxPin 2
#define txPin 3

#define RingPin 4

SoftwareSerial mySerial(rxPin, txPin); // RX, TX

String stringOne = "ATD=";
String answ;
 
void setup()
{
  
  lcd.begin();
  Serial.begin(9600); // Выставляем скорость COM порта
  irrecv.enableIRIn(); // Запускаем прием
  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(RingPin, INPUT);
  
  
  mySerial.begin(9600);
  
  Serial.println("Start program");
  
  delay(300);
	// initialize the LCD
	

	// Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.clear();
  lcd.print("Hello!");

  
}
 
void loop() {
  if (irrecv.decode(&results)) // Если данные пришли 
  {
    #ifdef DEBUG
  Serial.println(results.value, HEX); // Отправляем полученную данную в консоль
    #endif
    
    pos = num.length();
    switch (results.value) {
      case 0xFF9867 : // button 100+
        mySerial.println("AT"); 
        
       #ifdef DEBUG
         Serial.print("AT");
       #endif  
        
        Serial.println("Answer=");
        delay(800);
        while(mySerial.available())
        {
         
          Serial.print((char)(mySerial.read()));
        
        } 
        Serial.println(" "); 
        break;
      case 0xFFB04F :  // button 200+
        #ifdef DEBUG
          Serial.println("AT+CREG?");  // Chaeck status module
        #endif  
        
        mySerial.println("AT+CREG?");
      
        Serial.println("Answer=");
        delay(800);
        while(mySerial.available())
        {
          //mySerial.read(answ);
          Serial.print((char)(mySerial.read()));
       //   Serial.print(" ");
        } 
        Serial.println(" "); 
        break;

      
      
      case  0xFF6897 :
        //Serial.println("button 0");
        if(pos<MAX_DG) num+='0'; 
        break;
       case 0xFF30CF : 
        //Serial.println("button 1");
        if(pos<MAX_DG) num+='1'; 
        break;
      case 0xFF18E7 :
        //Serial.println("button 2");
        if(pos<MAX_DG) num+='2';
        break;
      case 0xFF7A85 :
        //Serial.println("button 3");
        if(pos<MAX_DG) num+='3';
        break;
      case 0xFF10EF :
        //Serial.println("button 4");
        if(pos<MAX_DG) num+='4';
        break;
      case 0xFF38C7 : 
        //Serial.println("button 5");
        if(pos<MAX_DG) num+='5';
        break;
      case 0xFF5AA5 :
        //Serial.println("button 6");
        if(pos<MAX_DG) num+='6';
        break;
      case 0xFF42BD :
        //Serial.println("button 7");
        if(pos<MAX_DG) num+='7';
        break;
      case 0xFF4AB5 :
        //Serial.println("button 8");
        if(pos<MAX_DG) num+='8';
        break;
      case 0xFF52AD :
        //Serial.println("button 9");
        if(pos<MAX_DG) num+='9';
        break;
      case 0xFFC23D : // button PLAY
       {
        Serial.println("Calling...");
        stringOne = "ATD"+num+";";
        Serial.println(stringOne);
      //  Serial.print('"');
      //  Serial.print(num);
      //  Serial.print('"');
      //  Serial.println(';');
        lcd.setCursor(0,1);
        lcd.print("Calling...!");
      
        mySerial.println(stringOne);
        Serial.println("Answer=");
        delay(500);
        while(mySerial.available())
        {
          //mySerial.read(answ);
          Serial.print((char)(mySerial.read()));
       //   Serial.print(" ");
        } 
        Serial.println(" "); 
        break;
        
        
        
        
       } 
      case 0xFF906F :
       { if(pos>=0) num.remove(pos-1);
        
        //Serial.println("buton EQ");
        break;
       } 
      case 0xFFA857 :
        if(pos<MAX_DG) num+='+';
        break;
      case 0xFFE21D :
        Serial.println("Cancel");
        Serial.println("ATH");
        mySerial.println("ATH");
        
        lcd.setCursor(0,1);
        lcd.print("Cancel     ");
        break;
    }
    //lcd.clear(); 
    lcd.home();
    lcd.print("                ");
    lcd.home();
    lcd.print(num);
    Serial.print("number=");
    Serial.println(num);
    
    irrecv.resume(); // Принимаем следующую команду
    delay(300);
  }
 // val = digitalRead(RingPin);
  if (digitalRead(RingPin)==0)
  {
    int i; 
    for(i=0;i<5;i++)
    {
      lcd.noBacklight();
      delay(70);
      lcd.backlight();
      delay(70);
    } 
    delay(400); 
  }  
}
