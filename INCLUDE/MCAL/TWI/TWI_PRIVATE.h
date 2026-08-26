// TWI_PRIVATE.h


#ifndef INCLUDE_MCAL_TWI_TWI_PRIVATE_H_
#define INCLUDE_MCAL_TWI_TWI_PRIVATE_H_


#define TWBR    (*(volatile u8*)0x20)
#define TWSR    (*(volatile u8*)0x21)
#define TWAR    (*(volatile u8*)0x22)
#define TWDR    (*(volatile u8*)0x23)
#define TWCR    (*(volatile u8*)0x56)

// TWCR Bits
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

// Status Codes
#define START_ACK                0x08
#define REP_START_ACK            0x10
#define SLAVE_ADD_AND_WR_ACK     0x18
#define SLAVE_ADD_AND_RD_ACK     0x40
#define WR_BYTE_ACK              0x28
#define RD_BYTE_WITH_NACK        0x58
#define RD_BYTE_WITH_ACK         0x50

#endif /* INCLUDE_MCAL_TWI_TWI_PRIVATE_H_ */
