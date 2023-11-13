#define lcd P0

sbit rs = P3^4;
sbit rw = P3^5;
sbit en = P3^6;

void lcd_init();
void lcd_cmd(unsigned char);
void lcd_date(unsigned char);
void lcd_str(unsigned char *);
void lcd_num(long unsigned int);

void pro_name(void){
    unsigned char l = strlen("RFID BASED TALLGATE CONTROL SYSTEM");
    unsigned char c = 0x80;
    //lcd_int();
    while(c < 0x90){
        lcd_cmd(0x01);
        lcd_cmd(c);
        lcd_str("RFID BASED TALLGATE CONTROL SYSTEM");

        if(c > (0x90 - l)){
            lcd_cmd(0x80);
            lcd_str("RFID BASED TALLGATE CONTROL SYSTEM" + (0x90 - c));
        }
        delay(500);
        c++;
    }
}

void lcd_init(){
    lcd_cmd(0x01);
    lcd_cmd(0x02);
    lcd_cmd(0x0c);
    lcd_cmd(0x38);
    lcd_cmd(0x80);
}

void lcd_cmd(unsigned char x){
    lcd = x;
    rs = 0;
    rw = 0;
    en = 1;
    delay(2);
    en = 0;
}

void lcd_data(unsigned char x){
    lcd = x;
    rs = 1;
    rw = 0;
    en = 1;
    delay(2);
    en = 0;
}

void lcd_str(unsigned char *s){
    while(*s){
        lcd_data(*s++);
    }
}

void lcd_num(long unsigned int n){
    char num[11];
    int i = 0;
    while(n != 0){
        num[i] = n % 10;
        i++;
        n = n / 10;
    }
    for(--i; i>=0; i--)
    lcd_data(num[i] + 48);
}