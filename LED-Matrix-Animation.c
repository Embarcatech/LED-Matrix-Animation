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


//função para inicializar o teclado

// Mapeamento das teclas em uma matriz 4x4
char teclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Inicializando os pinos de GPIO para o teclado
void iniciar_teclado() {

    // Definição das linhas como saídas e inicialização em nível baixo
    for (int i = 0; i < 4; i++) {
        gpio_init(LINHAS[i]);
        gpio_set_dir(LINHAS[i], GPIO_OUT);
        gpio_put(LINHAS[i], 0);
    }

    // Definição das colunas como entradas com resistores de pull-up
    for (int i = 0; i < 4; i++) {
        gpio_init(COLUNAS[i]);
        gpio_set_dir(COLUNAS[i], GPIO_IN);
        gpio_pull_up(COLUNAS[i]);
    }
}

// Varredura do teclado e retorno da tecla pressionada
char leitura_teclado() {
    for (int row = 0; row < 4; row++) {
        // Coloca a linha atual em nível baixo
        gpio_put(LINHAS[row], 0);

        for (int col = 0; col < 4; col++) {
            // Verifica se a tecla foi pressionada
            if (!gpio_get(COLUNAS[col])) {
                // Espera um tempo para estabilização da tecla pressionada
                sleep_ms(150);
                gpio_put(LINHAS[row], 1); // Reseta a linha atual
                return teclas[row][col];
            }
        }

        // Coloca a linha atual novamente para nível alto
        gpio_put(LINHAS[row], 1);
    }

    return 0; // Nenhuma tecla pressionada
}


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

    iniciar_teclado();
    // Iicializa a matriz de LEDs neoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();
    
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    animacaoBasica();
    //npSetLED(0, 128, 0, 0); // A título de teste, atribui a cor vermelha ao primeiro LED com 50% de intensidade

    // Escreve o buffer de LEDs no controlador
   //npWrite();

    while (true) {
        char tecla = leitura_teclado();
        printf("Tecla pressionada: %c\n", tecla);
               
        // Configuração dos LEDs com base na tecla pressionada
        switch (tecla) {
            case 'A':
              //  set_leds(1, 0, 0); // Botão A acende o LED vermelho
           //     printf("Liganado o LED vermelho\n");
               // set_buzzer(1);     // Liga o buzzer
                sleep_ms(200);     // Tempo do som do buzzer
                break;
           case 'B':
     //           set_leds(0, 0, 1); // Botão B acende o Led azul
      //          printf("Liganado o LED azul\n");

     //           set_buzzer(1);     // Liga o buzzer
                sleep_ms(200);     // Tempo do som do buzzer
                break;
            case 'C':
     //           set_leds(0, 1, 0); //Botão C acende o LED verde
    //            printf("Liganado o LED verde\n");
    //            set_buzzer(1);     // Liga o buzzer
                sleep_ms(200);     // Tempo do som do buzzer
                break;
            case 'D':
     //           set_leds (1,1,1); // Botão D acende todos os LEDS
    //            printf("Liganado todos os LEDs\n");
     //           set_buzzer(1);     // Liga o buzzer
                sleep_ms(200);     // Tempo do som do buzzer
                break;

            case '#':
     //           set_leds(0, 0, 0); // Desliga todos os LEDs
     //           printf("Desligando todos os LEDs\n");
     //           set_buzzer(1);     // Liga o buzzer
                sleep_ms(200);     // Tempo do som do buzzer
      //          set_buzzer(0);     // Desliga o buzzer
                break;

            case '0':
                animacaoTecla0();
                printf("Executando animação tecla 0\n");
                sleep_ms(300);     // Tempo do som do buzzer
     //           set_buzzer(0);     // Desliga o buzzer 
                break;

            default:
      //          set_leds(0, 0, 0); // Desliga todos os LEDs
     //           set_buzzer(0);     // Desliga o buzzer
                break;
    } 
    
    sleep_ms(100); // Estabilização

    }

    return 0;
}