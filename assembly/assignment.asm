
.include "/home/likhith/m328Pdef.inc"

ldi r17,0b00100000 ; identifying input pins 10,11,12,13
out DDRB,r17      ; declaring pins as input
ldi r17,0b11111111 ;
out PORTB,r17     ; activating internal pullup for pins 10,11,12,13
in r17,PINB


ldi r16, 0b00000100 ;identifying output pins 2,3,4,5
out DDRD,r16 ;declaring pins as output


ldi r17,0b00000000 ;initializing P
ldi r16,0b00000000 ;initializing Q
ldi r18,0b00000000 ;initializing R
ldi r19,0b00000001 ;initializing S





ldi r25,0b00000001
eor r25,r18 ;R'

AND r16,r25 ;Q&&R'


OR r16,r19 ;(Q&&R')||(S)



;following code is for displaying output
;shifting LSB in r16 to 2nd position
ldi r20, 0b00000010 ;counter = 2

rcall loopw ;calling the loopw routine

out PORTD,r16 ;writing output to pin 2

Start:
rjmp Start

;loop for bit shifting
loopw: lsl r16 ;left shift
dec r20 ;counter --
brne loopw ;if counter != 0
ret
