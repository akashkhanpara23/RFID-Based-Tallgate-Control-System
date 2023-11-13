unsigned char uart_rxd();
unsigned char *uart_rx_tag();

void uart_int(){
    SCON = 0x50;
    TMOD = 0x20;
    TH1 = TL1 = 253;
    TR1 = 1;
}

unsigned char uart_rxd(){
    while(RI == 0);
    RI = 0;
    return SBUF;
}

unsigned char *uart_rx_tag(){
    unsigned char tag[11];
    int i = 0;

    for(i = 0; i < 10; i++)
    tag[i] = uart_rxd();

    tag[i] = '\0';

    return tag;
}