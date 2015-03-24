/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int i;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.begin(9600); 
  i=0;
  
}

// the loop function runs over and over again forever
void loop() {
 /* 
  if (Serial.available() )
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    char in = Serial.read();
    if (in=='B')  digitalWrite(13, HIGH);
    if (in=='G')  digitalWrite(12, HIGH);
    if (in=='R')  digitalWrite(11, HIGH);
    if (in=='W')  
      {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
      }
   */   
    
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second
  
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(200); 
  
  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(300); 
  
  Serial.print(i++);
  Serial.println("Hello"); 
 
}
