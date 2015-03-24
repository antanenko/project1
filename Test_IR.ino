#include "IRremote2.h"


IRrecv irrecv(11); // Указываем пин, к которому подключен приемник
decode_results results;
 
void setup()
{
  Serial.begin(9600); // Выставляем скорость COM порта
  irrecv.enableIRIn(); // Запускаем прием
  
  Serial.println("Start program");
}
 
void loop() {
  if (irrecv.decode(&results)) // Если данные пришли 
  {
  //  Serial.println(results.value, HEX); // Отправляем полученную данную в консоль
    switch (results.value) {
      case  0xFF6897 :
        Serial.println("button 0");
        break;
       case 0xFF30CF : 
      Serial.println("button 1");
      break;
      
      case 0xFF18E7 :
      Serial.println("button 2");
      break;
      case 0xFF7A85 :
      Serial.println("button 3");
      break;
      

case 0xFF10EF :
Serial.println("button 4");
      break;


case 0xFF38C7 : 
Serial.println("button 5");
      break;

case 0xFF5AA5 :
Serial.println("button 6");
      break;

case 0xFF42BD :
Serial.println("button 7");
      break;

case 0xFF4AB5 :
Serial.println("button 8");
      break;

case 0xFF52AD :
Serial.println("button 9");
      break;

    } 
    
    
    irrecv.resume(); // Принимаем следующую команду
    delay(100);
  }
}
