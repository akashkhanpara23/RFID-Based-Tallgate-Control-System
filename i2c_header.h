#include<intrins.h>
#include"delay.h"

sbit scl = P2^2;
sbit sda = P2^3;

void i2c_start(void){
    scl = 1;
    sda = 1;
    sda = 0;
}

void i2c_stop(void){
    sda = 0;
    scl = 1;
    sda = 1;
}

void i2c_bytewrite(unsigned char d){
    unsigned char j;
    for(j = 0; j < 8; j++){
        scl = 0;
        sda = d & (0x80 >> j)? 1 : 0;
        scl = 1;
    }
}

unsigned char i2c_byteread(void){
    unsigned char j, buf = 0;
    for(j = 0; j < 8; j++){
        scl = 0;
        scl = 1;
        
        if(sda)
        buf |= (0x80 >> j);
    }
    return buf;
}

void i2c_ack(void){
    scl = 0;
    sda = 1;
    scl = 1;
    //while(sda == 1);
    scl = 0;
}

void i2c_noack(void){
    scl = 0;
    sda = 1;
    scl = 1;
    scl = 0;
}

void i2c_slave_write(unsigned char sa, unsigned char r_addr, unsigned char dat){
    i2c_start();
    
    i2c_bytewrite(sa);
    i2c_ack();
    
    i2c_bytewrite(r_addr);
    i2c_ack();

    i2c_bytewrite(dat);
    i2c_ack();

    i2c_stop();
    delay(10);
}

unsigned char i2c_slave_read(unsigned char sa, unsigned char r_addr){
    unsigned char buff;
    i2c_start();

    i2c_bytewrite(sa);
    i2c_ack();

    i2c_bytewrite(r_addr);
    i2c_ack();

    i2c_bytewrite(sa | 1);
    i2c_ack();

    buff = i2c_byteread();
    i2c_noack();
    i2c_stop();
    //delay(10);
    return buff;
}