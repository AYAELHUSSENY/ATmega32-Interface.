/*
 * Macros.h
 *
 * Created: 9/25/2021 9:50:34 PM
 *  Author: Dell
 */ 


#ifndef MACROS_H_
#define MACROS_H_
					//Bit Manipulation functions like macro 
#define CLEAR_BIT(Reg,Bit_no)	((Reg) &= ~(1U << (Bit_no))) 
#define SET_BIT(Reg,Bit_no)		((Reg) |= (1U <<  (Bit_no)))
#define TOGGLE_BIT(Reg, Bit_no) ((Reg) ^=(1U <<  (Bit_no)))
#define READ_BIT(Reg,Bit_no)    (((Reg) &= (1U << (Bit_no)))>> (Bit_no) )




#endif /* MACROS_H_ */