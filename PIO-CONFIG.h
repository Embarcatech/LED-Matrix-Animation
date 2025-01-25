#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#define LED_COUNT 25

// Definição de pixel GRB
struct pixel_t{
    uint8_t G,R,B; // Três valores de 8 bits para cada cor
};

typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome para facilitar a leitura

// Buffer de pixels que será enviado para o controlador
npLED_t leds [LED_COUNT]; 


// Função para converter cores em formato RGB para o protocolo da matriz de LEDs
uint32_t matriz_rgb(uint8_t b, uint8_t r, uint8_t g) {
    unsigned char R, G, B;
    R = (unsigned char)r;
    G = (unsigned char)g;
    B = (unsigned char)b;
    return (G << 24) | (R << 16) | (B << 8);
}

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
    ws2818b_program_init(np_pio, sm, offset, pin);

    // Limpa o buffer de LEDs
    for(uint i = 0; i < LED_COUNT; i++){
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

// Função para atribuar uma cor a um LED
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b){
    leds[index].G = g;
    leds[index].R = r;
    leds[index].B = b;
}

// Limpa o buffer de LEDs
void npClear(){
    for(uint i = 0;i < LED_COUNT; i++){
        npSetLED(i, 0, 0, 0);
    }
}
// Escreve o buffer de LEDs no controlador
void npWrite(){
    // Escreve cada dado de 8 bits dos pixels no buffer da máquina PIO
    for (uint i = 0; i < LED_COUNT; i++){
        uint32_t valor_led = matriz_rgb(leds[i].B, leds[i].R, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, valor_led);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}