/*
 * i2c_master.h
 *
 *  Created on: 2017Äê2ÔÂ17ÈÕ
 *      Author: Administrator
 */


#ifndef APP_INCLUDE_I2C_MASTER_H_
#define APP_INCLUDE_I2C_MASTER_H_
#include <STC15F2K60S2.H>

#define FALSE 0
#define TRUE 1

extern unsigned char I2CMutex;

extern unsigned char I2C_WIDTH;

typedef unsigned char uint8;
typedef char sint8;

sbit SDA_PIN = P1^1;
sbit SCL_PIN = P1^0;

#define I2C_MASTER_SDA_HIGH_SCL_HIGH()  \
		SDA_PIN = 1;SCL_PIN = 1;

#define I2C_MASTER_SDA_HIGH_SCL_LOW()  \
    SDA_PIN = 1;SCL_PIN = 0;

#define I2C_MASTER_SDA_LOW_SCL_HIGH()  \
    SDA_PIN = 0;SCL_PIN = 1;

#define I2C_MASTER_SDA_LOW_SCL_LOW()  \
		SDA_PIN = 0;SCL_PIN = 0;



void i2c_master_gpio_init(void);
void i2c_master_init(void);


void i2c_master_stop(void);
unsigned char i2c_master_start(void);
void i2c_master_setAck(uint8 level);
uint8 i2c_master_getAck(void);
uint8 i2c_master_readByte(void);
void i2c_master_writeByte(uint8 wrdata);

unsigned char i2c_master_checkAck(void);
void i2c_master_waitAck(void);
void i2c_master_send_ack(void);
void i2c_master_send_nack(void);
#endif /* APP_INCLUDE_I2C_MASTER_H_ */