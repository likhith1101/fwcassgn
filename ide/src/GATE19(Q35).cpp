#include <Arduino.h>
int Y,P,Q,R,S;
void setup()
{
	pinMode(10, OUTPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
}
void loop(){
 	P = digitalRead(2);
	Q = digitalRead(3);
	R = digitalRead(4);
	S = digitalRead(5);
	Y =(S||(!R&&Q));
	digitalWrite(10, Y);
	
}
