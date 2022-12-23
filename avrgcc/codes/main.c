
#include <avr/io.h>
#include <stdbool.h>
#include<util/delay.h>
int main (void)
{
    int p,q,r,s;
    bool y; 
 //set pin 2,3,4,5 of arduino as input
  DDRD    |=0b00000000 ;
  PORTD=0xFC;

DDRB = 0b00100000 ; // 13 pin as ouput


while(1)
{           
          p = (PIND & (1 << PIND2)) == (1 << PIND2);

                q = (PIND & (1 << PIND3)) == (1 << PIND3);

                r = (PIND & (1 << PIND4)) == (1 << PIND4);

                s = (PIND & (1 << PIND5)) == (1 << PIND5);
                
                y=(q&&(!r))||(s);
         
           PORTB = (y<<5);

}
         return 0;
}
