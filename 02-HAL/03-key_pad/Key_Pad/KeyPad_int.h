/************************************************/
/* Title       : KeyPad Interface file          */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 17, 2021                   */
/************************************************/

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

/* Connect pull up resistor or not */
void KeyPad_voidInit(void);

/*This function shall return 16 bit variable
		indicating the status of each key */
u8 KeyPad_u8GetButton(void);

#endif /* KEYPAD_INT_H_ */
