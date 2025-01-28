
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#include "definicoes.h"



int animacaoBasica(){
  
     npClear();
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    for (uint i = 0; i < LED_COUNT; i++){
        npSetLED(i, 128, 0, 0);
        sleep_ms(200);
        npWrite();
        }

}
