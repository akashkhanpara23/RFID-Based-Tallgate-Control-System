#ifndef DELAY_H
#define DELAY_H

void delay(unsigned int time){
    unsigned int i, j;
    for(i = 0; i < time; i++){
        for(j = 0; j < 1275; j++); // Approximate delay loop
    }
}

#endif
