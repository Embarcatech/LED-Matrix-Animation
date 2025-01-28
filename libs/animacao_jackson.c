
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


#include "definicoes.h"






// INÍCIO DA ANIMAÇÃO 0 - Jackson S. dos Santos

// Função para configurar um LED e esperar
void configurarLED(uint posicao, uint8_t red, uint8_t blue, uint8_t green, uint tempoDeEspera){
    npSetLED(posicao, red, blue, green);
    npWrite();
    sleep_ms(tempoDeEspera);
}

// Função para configurar vários LEDs e esperar
void configurarLEDs(uint *posicoes, uint tamanho, uint8_t red, uint8_t green, uint8_t blue, uint tempoDeEspera){
    npSetManyLEDs(posicoes, tamanho, red, green, blue);
    npWrite();
    sleep_ms(tempoDeEspera);
}

//ok implementado
void animacaoTecla0(){
    // Define as posições dos LEDs que formarão o quadrado
    uint posicaoCentral = 12; 
    uint posicoesInterno[8] = {6, 7, 8, 11, 13, 16, 17, 18};
    uint posicoesBorda[16] = {0, 1, 2, 3, 4, 9, 14, 19, 24, 23, 22, 21, 20, 15, 10, 5};
    uint tempoDeEspera = 200; 
    
    // Acende o LED 12 em vermelho e apaga em seguida
    configurarLED(posicaoCentral, 255, 0, 0, tempoDeEspera);
    configurarLED(posicaoCentral, 0, 0, 0, tempoDeEspera);

    // Acende LEDs internos em azul e apaga em seguida
    configurarLEDs(posicoesInterno, 8, 0, 0, 255, tempoDeEspera);
    npClear();
    sleep_ms(tempoDeEspera);

    // Pisca a borda em vermelho e azul
    configurarLEDs(posicoesBorda, 16, 255, 0, 0, tempoDeEspera);
    npClear();
    sleep_ms(tempoDeEspera);
    configurarLEDs(posicoesBorda, 16, 0, 0, 255, tempoDeEspera);
    npClear();
    sleep_ms(tempoDeEspera);

    // Acende LEDs internos em vermelho e apaga
    configurarLEDs(posicoesInterno, 8, 255, 0, 0, tempoDeEspera);
    npClear();
    sleep_ms(tempoDeEspera);

    // Finaliza com LED 12 em azul
    configurarLED(posicaoCentral, 0, 0, 255, tempoDeEspera);

}
// FIM DA ANIMAÇÃO 0

// INICIO DA AÇÃO DA TECLA A

// Todos os leds devem ser apagados
void acaoTeclaA(){
    npClear(); // Limpa o buffer de LEDs
    npWrite(); // Escreve o buffer de LEDs no controlador
}

// FIM DA AÇÃO DA TECLA A

// INICIO DA AÇÃO DA TECLA B
// Aciona todos os leds em azul na intensidade máxima
void acaoTeclaB(){
    for(int i = 0; i < LED_COUNT; i++){
        npSetLED(i, 0, 0, 255);
    }
    npWrite();
}
// FIM DA AÇÃO DA TECLA B