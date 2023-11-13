sbit pos = P2^0;
sbit neg = P2^1;

void gate_open(){
    pos = 1;
    neg = 0;
    delay(500);

    pos = 0;
    neg = 0;
    delay(5000);
}

void gate_close(){
    pos = 0;
    neg = 1;
    delay(500);

    pos = 0;
    neg = 0;
    delay(5000);
}