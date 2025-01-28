
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#include "definicoes.h"

//Animação para a tecla A - Arthur Alencar
void animacaoTeclaA() {
    const uint leds[][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24}
    };

    const uint rows = sizeof(leds) / sizeof(leds[0]);    // Número de fileiras
    const uint cols = sizeof(leds[0]) / sizeof(leds[0][0]); // Número de colunas

    // Percorre cada fileira
    for (uint r = 0; r < rows; r++) {
        for (uint color = 0; color < 3; color++) {
            for (uint c = 0; c < cols; c++) {
                uint led_id = leds[r][c]; // LED atual na fileira
                uint8_t red = (color == 0) ? 50 : 0;  // Intensidade do vermelho
                uint8_t green = (color == 1) ? 50 : 0; // Intensidade do verde
                uint8_t blue = (color == 2) ? 50 : 0;  // Intensidade do azul
                sleep_ms(50);
                npSetLED(led_id, red, green, blue);
            }

            npWrite();
            sleep_ms(100);
        }
    }

    for (uint r = 0; r < rows; r++) {
        for (uint c = 0; c < cols; c++) {
            npSetLED(leds[r][c], 0, 0, 0);
        }
    }
    npWrite();
}
