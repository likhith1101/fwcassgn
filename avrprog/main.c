#include<avr/io.h>
#include<stdbool.h>
int main(void){

bool p,q,r,s,y;
DDRB = 0b00001111; //8&9&10&11 as inputs
PORTB= 0b11110000;
DDRD = 0b00000100; //2as output


while(1)
   {
	   p = (PINB & (1<<PINB0)) == (0<<PINB0);	
	   q = (PINB & (1<<PINB1)) == (0<<PINB1);
	   r = (PINB & (1<<PINB2)) == (0<<PINB2);
	   s = (PINB & (1<<PINB3)) == (1<<PINB3);
	   y=(q&&(!r))||(s);
	   PORTD |= (y<<2);

   }

	return 0;
}
