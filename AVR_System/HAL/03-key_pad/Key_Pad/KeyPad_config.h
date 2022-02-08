/************************************************/
/* Title       : KeyPad Configuration file      */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 17, 2021                   */
/************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_u8_ROW1 		DIO_u8_PIN_4
#define KEYPAD_u8_ROW2		DIO_u8_PIN_5
#define KEYPAD_u8_ROW3		DIO_u8_PIN_6
#define KEYPAD_u8_ROW4		DIO_u8_PIN_7


#define KEYPAD_u8_COL1		DIO_u8_PIN_0
#define KEYPAD_u8_COL2		DIO_u8_PIN_1
#define KEYPAD_u8_COL3		DIO_u8_PIN_2
#define KEYPAD_u8_COL4		DIO_u8_PIN_3

#define KEYPAD_u8_R1C1      '7'
#define KEYPAD_u8_R1C2      '8'
#define KEYPAD_u8_R1C3      '9'
#define KEYPAD_u8_R1C4      '/'

#define KEYPAD_u8_R2C1      '4'
#define KEYPAD_u8_R2C2      '5'
#define KEYPAD_u8_R2C3      '6'
#define KEYPAD_u8_R2C4      '*'

#define KEYPAD_u8_R3C1      '1'
#define KEYPAD_u8_R3C2      '2'
#define KEYPAD_u8_R3C3      '3'
#define KEYPAD_u8_R3C4      '-'

#define KEYPAD_u8_R4C1      ' '
#define KEYPAD_u8_R4C2      '0'
#define KEYPAD_u8_R4C3      '='
#define KEYPAD_u8_R4C4      '+'

/*Keypad u8 internal or external */


#define KEYPAD_u8_PULLUP		KEYPAD_u8_INTERNAL

#endif /* KEYPAD_CONFIG_H_ */
