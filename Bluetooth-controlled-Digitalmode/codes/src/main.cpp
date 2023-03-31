#include<Arduino.h>
#include<esp32PWMUtilities.h>

#include<DabbleESP32.h>

void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(32, a); 
  digitalWrite(33, b); 
  digitalWrite(25, c); 
  digitalWrite(26, d); 
  digitalWrite(27, e); 
  digitalWrite(14, f);     
  digitalWrite(12, g); 
}
void _setup() 
{
   Serial.begin(115200);

    pinMode(32, OUTPUT);  
    pinMode(33, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(12, OUTPUT);            
      Dabble.begin("Esp32");

}


void _loop() {
  Dabble.processInput();
}

void setup() {
  _setup();
}
void loop() {
  _loop();
  if (GamePad.isPressed(0)) {
Serial.println("1");
  sevenseg(1,0,0,1,1,1,1);  //1
  }
  else {
    if (GamePad.isPressed(1)) {
        Serial.println("2");
		 sevenseg(0,0,1,0,0,1,0);  //2
        }
    else {
      if (GamePad.isPressed(2)) {
        Serial.println("3");
              sevenseg(0,0,0,0,1,1,0);   //3
      }
      else {
        if (GamePad.isPressed(3)) {
                Serial.println("4");
                        sevenseg(1,0,0,1,1,0,0);  //4
        }
        else {
                if (GamePad.isPressed(4)) {
                        Serial.println("0");
                        sevenseg(0,0,0,0,0,0,1);   //0
                }
                else {
                        sevenseg(1,1,1,1,1,1,1);
                        }
                }
        }
      }
    }
  }
