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


// Função para converter a posição do matriz para uma posição do vetor.
int getIndex(int x, int y) {
    // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
    // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
    if (y % 2 == 0) {
        return 24-(y * 5 + x); // Linha par (esquerda para direita).
    } else {
        return 24-(y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
    }
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

void animacao_tecla_8(){

    int matriz[5][5][3] = {
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};
        // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz[coluna][linha][0], matriz[coluna][linha][1], matriz[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_2[5][5][3] = {
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};  
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_2[coluna][linha][0], matriz_2[coluna][linha][1], matriz_2[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_3[5][5][3] = {
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_3[coluna][linha][0], matriz_3[coluna][linha][1], matriz_3[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_4[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_4[coluna][linha][0], matriz_4[coluna][linha][1], matriz_4[coluna][linha][2]);
        }
        }    

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_5[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_5[coluna][linha][0], matriz_5[coluna][linha][1], matriz_5[coluna][linha][2]);
        }
        }  

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_6[5][5][3] = {
    {{69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_6[coluna][linha][0], matriz_6[coluna][linha][1], matriz_6[coluna][linha][2]);
        }
        }  

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_7[5][5][3] = {
    {{69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_7[coluna][linha][0], matriz_7[coluna][linha][1], matriz_7[coluna][linha][2]);
        }
        }  

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_8[5][5][3] =  {
    {{69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};  

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_8[coluna][linha][0], matriz_8[coluna][linha][1], matriz_8[coluna][linha][2]);
        }
        }  

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_9[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_9[coluna][linha][0], matriz_9[coluna][linha][1], matriz_9[coluna][linha][2]);
        }
        }  

    npWrite();
    sleep_ms(2000);
    npClear();

    int matriz_10[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_10[coluna][linha][0], matriz_10[coluna][linha][1], matriz_10[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_11[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_11[coluna][linha][0], matriz_11[coluna][linha][1], matriz_11[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();

    
    int matriz_12[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};


        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_12[coluna][linha][0], matriz_12[coluna][linha][1], matriz_12[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_13[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_13[coluna][linha][0], matriz_13[coluna][linha][1], matriz_13[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_14[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_14[coluna][linha][0], matriz_14[coluna][linha][1], matriz_14[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_15[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_15[coluna][linha][0], matriz_15[coluna][linha][1], matriz_15[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_16[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_16[coluna][linha][0], matriz_16[coluna][linha][1], matriz_16[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_17[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_17[coluna][linha][0], matriz_17[coluna][linha][1], matriz_17[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_18[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_18[coluna][linha][0], matriz_18[coluna][linha][1], matriz_18[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_19[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_19[coluna][linha][0], matriz_19[coluna][linha][1], matriz_19[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_20[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_20[coluna][linha][0], matriz_20[coluna][linha][1], matriz_20[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_21[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {69, 212, 0}, {69, 212, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {0, 0, 0}, {0, 0, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_21[coluna][linha][0], matriz_21[coluna][linha][1], matriz_21[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_22[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}},
    {{69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}, {69, 212, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_22[coluna][linha][0], matriz_22[coluna][linha][1], matriz_22[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_23[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 98, 255}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_23[coluna][linha][0], matriz_23[coluna][linha][1], matriz_23[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_24[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 98, 255}, {0, 0, 0}, {0, 98, 255}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 98, 255}, {0, 0, 0}, {0, 98, 255}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_24[coluna][linha][0], matriz_24[coluna][linha][1], matriz_24[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();


    int matriz_25[5][5][3] = {
    {{0, 98, 255}, {0, 0, 0}, {0, 98, 255}, {0, 0, 0}, {0, 98, 255}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 98, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 98, 255}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 98, 255}, {0, 0, 0}, {0, 98, 255}, {0, 0, 0}, {0, 98, 255}}
};

        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_25[coluna][linha][0], matriz_25[coluna][linha][1], matriz_25[coluna][linha][2]);
        }
        } 

    npWrite();
    sleep_ms(2000);
    npClear();
        

}

void animacao_tecla_9(){

int matriz_31[5][5][3] = {
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}}
};


    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_31[coluna][linha][0], matriz_31[coluna][linha][1], matriz_31[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_32[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}}
};


    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_32[coluna][linha][0], matriz_32[coluna][linha][1], matriz_32[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_33[5][5][3] =  {
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}}
};


    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_33[coluna][linha][0], matriz_33[coluna][linha][1], matriz_33[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_34[5][5][3] = {
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_34[coluna][linha][0], matriz_34[coluna][linha][1], matriz_34[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_35[5][5][3] = {
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_35[coluna][linha][0], matriz_35[coluna][linha][1], matriz_35[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_36[5][5][3] = {
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_36[coluna][linha][0], matriz_36[coluna][linha][1], matriz_36[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_37[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_37[coluna][linha][0], matriz_37[coluna][linha][1], matriz_37[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_38[5][5][3] = {
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_38[coluna][linha][0], matriz_38[coluna][linha][1], matriz_38[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_39[5][5][3] = {
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_39[coluna][linha][0], matriz_39[coluna][linha][1], matriz_39[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_40[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_40[coluna][linha][0], matriz_40[coluna][linha][1], matriz_40[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_41[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_41[coluna][linha][0], matriz_41[coluna][linha][1], matriz_41[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_42[5][5][3] = {
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_42[coluna][linha][0], matriz_42[coluna][linha][1], matriz_42[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_43[5][5][3] = {
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_43[coluna][linha][0], matriz_43[coluna][linha][1], matriz_43[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_44[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_44[coluna][linha][0], matriz_44[coluna][linha][1], matriz_44[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_45[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_45[coluna][linha][0], matriz_45[coluna][linha][1], matriz_45[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_46[5][5][3] =  {
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_46[coluna][linha][0], matriz_46[coluna][linha][1], matriz_46[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_47[5][5][3] = {
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_47[coluna][linha][0], matriz_47[coluna][linha][1], matriz_47[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_48[5][5][3] =  {
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_48[coluna][linha][0], matriz_48[coluna][linha][1], matriz_48[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_49[5][5][3] =  {
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_49[coluna][linha][0], matriz_49[coluna][linha][1], matriz_49[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_50[5][5][3] = {
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_50[coluna][linha][0], matriz_50[coluna][linha][1], matriz_50[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_51[5][5][3] = {
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}}
};


    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_51[coluna][linha][0], matriz_51[coluna][linha][1], matriz_51[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_52[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_52[coluna][linha][0], matriz_52[coluna][linha][1], matriz_52[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_53[5][5][3] = {
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_53[coluna][linha][0], matriz_53[coluna][linha][1], matriz_53[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_54[5][5][3] =  {
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_54[coluna][linha][0], matriz_54[coluna][linha][1], matriz_54[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_55[5][5][3] =  {
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}},
    {{0, 0, 0}, {37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_55[coluna][linha][0], matriz_55[coluna][linha][1], matriz_55[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();




int matriz_56[5][5][3] =  {
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {37, 24, 247}, {37, 24, 247}, {0, 0, 0}},
    {{37, 24, 247}, {0, 0, 0}, {0, 0, 0}, {37, 24, 247}, {0, 0, 0}}
};

    // Desenhando Sprite contido na matriz.c
        for(int linha = 0; linha < 5; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        npSetLED(posicao, matriz_56[coluna][linha][0], matriz_56[coluna][linha][1], matriz_56[coluna][linha][2]);
        }
        }

    npWrite();
    sleep_ms(2000);
    npClear();

    
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