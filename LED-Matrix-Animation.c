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

// Variváveis para o controle do PIO
PIO np_pio;
uint sm;

// Inicializa a máquina PIO
void npInit(uint pin){
    // Cria programa PIO
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;

    // Aloca uma máquina PIO
    sm = pio_claim_unused_sm(np_pio, false);
    if(sm < 0){
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true); // Se nenhuma máquina estiver disponível, panic
    }

    // Inicializa o programa na máquina PIO
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    // Limpa o buffer de LEDs
    for(uint i = 0; i < LED_COUNT; i++){
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

int main () {

    printf("Hello, Pico!\n");
    
}