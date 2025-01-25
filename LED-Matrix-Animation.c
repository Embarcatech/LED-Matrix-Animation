#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "PIO-CONFIG.h"

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
    
    while(true) char tecla = leitura_teclado();
        printf("Tecla pressionada: %c\n", tecla);
       
        switch (tecla) {

            case '0': animacao_0(); break;
            case '1': animacao_1(); break;
            case '2': animacao_2(); break;
            case '3': animacao_3(); break;
            case '4': animacao_4(); break;
            case '5': animacao_5(); break;
            case '6': animacao_6(); break;
            case '7': animacao_7(); break;
            case '8': animacao_8(); break;
            case '9': animacao_9(); break;
            case 'A': npClear(); npWrite(); break;
            case 'B': todas_azul(); break;
            case 'C': todas_vermelho(); break;
            case 'D': todas_verde(); break;
            case '#': todas_branco(); break;
            case '*': reset_usb_boot(0, 0); break;
            default: break;
        }

        sleep_ms(100); // Estabilização
    }
    return 0;
}