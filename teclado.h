
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
//#include "pio_config.h"

// Biblioteca gerada pelo arquivo ws2818b.pio 
//#include "ws2818b.pio.h"
// Configuração do teclado matricial
#define ROWSPIN 4
#define COLSPIN 4

// Definição dos pinos GPIO conectados às linhas e colunas do teclado
uint8_t rowPins[ROWSPIN] = {18, 19, 20, 4};  // GPIOs para as linhas
uint8_t colPins[COLSPIN] ={16, 17, 9, 8};  // GPIOs para as colunas

// Mapeamento das teclas (4x4)
char keyMap[ROWSPIN][COLSPIN] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
