#ifndef INCLUDE_MCAL_DIO_DIO_PRIVATE_H_
#define INCLUDE_MCAL_DIO_DIO_PRIVATE_H_

/* Hardware Registers */
#define PORTA_REG (*(volatile u8 *) 0x3B)
#define DDRA_REG  (*(volatile u8 *) 0x3A)
#define PINA_REG  (*(volatile u8 *) 0x39)

#define PORTB_REG (*(volatile u8 *) 0x38)
#define DDRB_REG  (*(volatile u8 *) 0x37)
#define PINB_REG  (*(volatile u8 *) 0x36)

#define PORTC_REG (*(volatile u8 *) 0x35)
#define DDRC_REG  (*(volatile u8 *) 0x34)
#define PINC_REG  (*(volatile u8 *) 0x33)

#define PORTD_REG (*(volatile u8 *) 0x32)
#define DDRD_REG  (*(volatile u8 *) 0x31)
#define PIND_REG  (*(volatile u8 *) 0x30)


#define DIO_CNF_INPUT       0
#define DIO_CNF_OUTPUT      1

#define DIO_CNF_LOW         0
#define DIO_CNF_HIGH        1
#define DIO_CNF_FLOATING    0
#define DIO_CNF_PULLUP      1


#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)         CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* INCLUDE_MCAL_DIO_DIO_PRIVATE_H_ */
