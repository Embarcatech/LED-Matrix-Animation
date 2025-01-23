#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo ws2818b.pio 
#include "ws2818b.pio.h"

// Definição da quantidade de LEDs e o pino de controle
#define LED_COUNT 25
#define LED_PIN 7

// Definição de pixel GRB
struct pixel_t{
    uint8_t G,R,B; // Três valores de 8 bits para cada cor
};

typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome para facilitar a leitura

// Buffer de pixels que será enviado para o controlador
npLED_t leds [LED_COUNT]; 


int main () {

    printf("Hello, Pico!\n");
    
}