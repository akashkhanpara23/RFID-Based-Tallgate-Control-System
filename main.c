#include<reg51.h>
#include<string.h>
#include"i2c_header.h"
#include"LCD.h"
#include"uart.h"
#include"mtr_driver.h"

sbit sw1 = P3^7;

void tag();
void rtc_time();
void amount_paid(int, int);
long unsigned int atoi_fun(unsigned char *);
long unsigned int tag_ids[]={1243585271};
long unsigned int tag_id[5]={0,0,0,0,0};

void main(){
    lcd_init();
    lcd_str("hello");
    delay(500);

    uart_init();
    pos = 1;
    neg = 1;
    i2c_slav_write(0xd0,0x01,0x00);
    pro_name();

    while(1){
        lcd_cmd(0x01);
        lcd_cmd(0x02);
        lcd_cmd(0x80);
        lcd_str("Waiting for tag ID");
        tag();
    }
}

void tag(void){
    char id2[11];
    bit flag = 0;
    long unsigned int number;
    int count = 0, i = 0, j = 0, in_time = 0, out_time = 0, temp = 0;
    char x = 0, y = 0;

    strcpy(id2,(uart_rx_tag()));
    id2[10] = '\0';

    number = atoi_fun(id2);
    lcd_cmd(0x01);

    for(i = 0; i < 5; i++){
        if(number == tag_id[i])
        flag = 1;
    }

    if(flag != 1){
        lcd_cmd(0x01);
        lcd_str("Invalid tag ID");
        delay(2000);
        return;
    }

    for(i = 0; i < 5; i++){
        if(number == tag_id[i]){
            count++;
            break;
        }
    }

    if(count != 0){
        out_time = i2c_slave_read(0xd0,0x01);
        x = out_time / 16;
        y = out_time % 16;
        out_time = ((x * 10) + y);

        in_time = i2c_slave_read(0xa0, (0x00 + i));
        tag_id[i] = 0;
        lcd_str("Out Time:");
        delay(500);

        rtc_time();
        delay(1000);

        amount paid(in_time, out_time);
        lcd_cmd(0xc0);
        lcd_str("Wait...");
        
        while(sw1 == 1);

        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_cmd(0x01);
        lcd_str("Thank you for coming");

        lcd_cmd(0xc0);
        lcd_str("Gate open");
        gate_open();

        lcd_cmd(0xc0);
        lcd_str("Gate close");
        gate_close();
    }
    else if(count == 0){
        for(j = 0; j < 5; j++){
            if(tag_id[j] == 0){
                tag_id[j] = number;
                break;
            }
        }
        temp = i2c_slave_read(0xd0, 0x01);
        x = temp / 16;
        y = temp % 16;
        temp = (x * 10) + y;
        i2c_slave_write(0xa0, (0x00 + j), temp);
        lcd_cmd(0x01);

        lcd_cmd(0x80);
        lcd_str("welcome");

        lcd_cmd(0x80);
        lcd_str("In time:");
        delay(500);
        
        rtc_time();
        delay(500);

        lcd_cmd(0xc0);
        lcd_str("Gate open");
        gate_open();

        lcd_cmd(0xc0);
        lcd_str("Gate close");
        gate_close();
    }
    count = 0;
    flag = 0;
}

void amount_paid(int a, int b){
    int c = 0;
    c = b - a;

    if(c < 1){
        lcd_cmd(0x01);
        lcd_str("Pay:50/-");
    }
    else{
        lcd_cmd(0x01);
        lcd_cmd("Pay:");
        lcd_num(c * 50);
    }
}

long unsigned int atoi_fun(unsigned char *tag_id){
    long unsigned int num = 0;
    int l = 0;
    tag_id[0] = '1';
    tag_id[9] = '1';

    for(l = 0; tag_id[l]; l++){
        num = ((num * 10)+(tag_id[l] - 48));
    }
    return num;
}

void rtc_time(){
    unsigned int t[4];

    lcd_cmd(0x80);
    lcd_str("Time:");
    lcd_cmd(0x86);

    t[0] = i2c_slave_read(0xD0, 0x02);
    lcd_data(((t[0] >> 4) & 3) + 48);
    lcd_data((t[0] & 0x0f) + 48);
    lcd_data(':');

    t[1] = i2c_slave_read(0xD0, 0x01);
    lcd_data((t[1] >> 4) + 48);
    lcd_data((t[1] & 0x0f) + 48);
    lcd_data(':');

    t[2] = i2c_slave_read(0xD0, 0x00);
    lcd_data((t[2] >> 4) + 48);
}