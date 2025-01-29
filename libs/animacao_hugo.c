
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#include "definicoes.h"




// Animação basica feita para testes dos LEDs 

int animacaoBasica(){
  
     npClear();
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    for (uint i = 0; i < LED_COUNT; i++){
        npSetLED(i, 60, 0, 0);
        sleep_ms(200);
        npWrite();
        }

}



// Estrutura para cores GRB
typedef struct {
    int green;
    int red;
    int blue;
} LED;

// Matriz de LEDs 5x5
#define ROWS 5
#define COLS 5
LED ledMatrix[ROWS][COLS];


// Função para converter a posição do matriz para uma posição do vetor.
int getIndexMatriz(int x, int y) {
    // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
    // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
    if (y % 2 == 0) {
        return 24-(y * 5 + x); // Linha par (esquerda para direita).
    } else {
        return 24-(y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
    }
}

// Inicializa a matriz de LEDs
void initializeMatrix(LED matrix[ROWS][COLS], int green, int red, int blue) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j].green = green;
            matrix[i][j].red = red;
            matrix[i][j].blue = blue;
        }
    }
}


// Função para aplicar os valores da matriz no controlador NeoPixel
void applyMatrixToNeoPixel(LED matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int index = getIndexMatriz(j, i);
            npSetLED(index, matrix[i][j].green, matrix[i][j].red, matrix[i][j].blue);
        }
    }
    npWrite(); // Atualiza os LEDs
}

// Animação de rotação de cores na matriz
void animateMatrix(LED matrix[ROWS][COLS], int cycles) {
    for (int c = 0; c < cycles; c++) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                // Alterna as cores GRB
                int temp = matrix[i][j].green;
                matrix[i][j].green = matrix[i][j].red;
                matrix[i][j].red = matrix[i][j].blue;
                matrix[i][j].blue = temp;
            }
        }
        applyMatrixToNeoPixel(matrix); // Atualiza a matriz no controlador NeoPixel
        sleep_ms(500); // Aguarda 500ms antes de continuar
    }
}

