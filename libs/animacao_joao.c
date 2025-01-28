
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#include "definicoes.h"





// Animação 3- João Vitor S. Amorim
// FIM DA 2 ANIMAÇÃO

void animacaoEspiral() {
    const uint led_sequence[] = {
        12, 7, 2, 1, 0, 5, 10, 15, 20, 21, 22, 23, 24, 19, 14, 9, 4, 3, 8, 13, 18, 17, 16, 11, 6
    };
    const uint led_count = sizeof(led_sequence) / sizeof(led_sequence[0]);

    for (int i = 0; i < 2; i++) { // Animação com 2 frames
        for (uint j = 0; j < led_count; j++) {
            npSetLED(led_sequence[j], 0, 51, 0); // Verde com 20% de brilho (intensidade baixa)
            npWrite();
            sleep_ms(50);
        }
        npClear();
        npWrite();
    }
}
// FIM DA 3 ANIMAÇÃO
    

// Animação 4- João Vitor S. Amorim
void animacaoCoracaoPulsante() {
    const uint led_sequence[] = {
        2, 3, 6, 8, 9, 10, 14, 15, 16, 17, 18, 22
    };
    const uint led_count = sizeof(led_sequence) / sizeof(led_sequence[0]);

    for (int i = 0; i < 1; i++) { // Animação com 1 ciclo de pulso
        for (uint8_t intensidade = 0; intensidade <= 51; intensidade += 15) { // Intensidade máxima reduzida (20% do brilho máximo)
            for (uint j = 0; j < led_count; j++) {
                npSetLED(led_sequence[j], intensidade, 0, 0); // Vermelho
            }
            npWrite();
            sleep_ms(50); // Menor tempo de espera
        }
        for (uint8_t intensidade = 51; intensidade > 0; intensidade -= 15) {
            for (uint j = 0; j < led_count; j++) {
                npSetLED(led_sequence[j], intensidade, 0, 0); // Vermelho
            }
            npWrite();
            sleep_ms(50); // Menor tempo de espera
        }
    }
}
// FIM DA 4 ANIMAÇÃO
