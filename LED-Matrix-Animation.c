#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "pio_config.h"

// Biblioteca gerada pelo arquivo ws2818b.pio 
#include "ws2818b.pio.h"

// Definição da quantidade de LEDs e o pino de controle
#define LED_COUNT 25

#define MATRIX_LED_PIN 7 // PINO DA MATRIZ DE LEDS ws2818b
#define BUZZER_PIN 21 // PINO DO BUZZER

// Matrizes com nomes de colunas e linhas - GPIO - BitDogLab
//Portas GPIO sem função específica definida
const uint LINHAS[4] = {18, 19, 20, 4}; 
const uint COLUNAS[4] = {16, 17, 9, 8};

int animacaoBasica(){
  
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    for (uint i = 0; i < LED_COUNT; i++){
        npSetLED(i, 128, 0, 0);
        sleep_ms(200);
        npWrite();
        }
}

void animacaoTecla0(){
    // Acende o LED 12 por 200ms
    npSetLED(12, 255, 0, 0); // LED 12 com cor vermelha
    npWrite();
    sleep_ms(200);

    // Apaga o LED 12
    npSetLED(12, 0, 0, 0);
    npWrite();
    sleep_ms(200);

    // LEDs 6, 7, 8, 11, 13, 16, 18 com cor azul
    uint posicoes[8] = {6, 7, 8, 11, 13, 16, 17, 18};
    npSetManyLEDs(posicoes,8, 0, 0, 255); 
    npWrite();
    sleep_ms(200); 

    npClear(); // Apaga todos os LEDs
    sleep_ms(200);
    uint posicoesBorda[] = {0, 1, 2, 3, 4, 9, 14, 19, 24, 23, 22, 21, 20, 15, 10, 5};
    npSetManyLEDs(posicoesBorda, 16, 255, 0, 0);
    npWrite();
    sleep_ms(200);

    npClear();
    sleep_ms(200);
    npSetManyLEDs(posicoesBorda, 16, 0, 0, 255);
    npWrite();
    sleep_ms(200); 

    npClear();
    sleep_ms(200);
    npSetManyLEDs(posicoes,8,255, 0, 0);
    npWrite();
    sleep_ms(200);

    npClear();
    sleep_ms(200);
    npSetLED(12, 0, 0, 255);
    npWrite();
    sleep_ms(200);
}


int main () {
    stdio_init_all();

    // Iicializa a matriz de LEDs neoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();
    
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    animacaoBasica();
    //npSetLED(0, 128, 0, 0); // A título de teste, atribui a cor vermelha ao primeiro LED com 50% de intensidade

    // Escreve o buffer de LEDs no controlador
   //npWrite();

    while(true){
        sleep_ms(1000);
    }
    
}