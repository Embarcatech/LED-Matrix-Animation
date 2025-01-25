#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"

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



// Definição de pixel GRB
struct pixel_t{
    uint8_t G,R,B; // Três valores de 8 bits para cada cor
};

typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome para facilitar a leitura

// Buffer de pixels que será enviado para o controlador
npLED_t leds [LED_COUNT]; 

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
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

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
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}




void animacaoQuadradoCentro(){
    //Definir as bordas do quadrado (5X5)
    uint borda[16]={0,1,2,3,4,     //base
                    5,9,        
                    10,14,
                    15,19,
                    20,21,22,23,24}; //Fundo 
    npClear();

    //Acender as bordas do quadrado com cor vermelha
    for (int i = 0; i<16;i++){
        npSetLED(borda[i],128,0,0);
    }

    //Acender o centro do quadrado com a cor verde
    npSetLED(12,0,128,0);

    //Atualiza os LEDs
    npWrite();
}

void animacaoQuadradoPulsante(){
    //Define as posições dos LEDs que formarão o quadrado
    const uint led_sequence[] = {0,9,10,19,20,21,22,23,24,15,14,5,4,3,2,1,0,12};
    const uint led_count = sizeof(led_sequence)/ sizeof(led_sequence[0]);

    for(int i = 0; i<led_count; i++){
        if(led_sequence[i]==12){
            npSetLED(led_sequence[i],0,128,0);
        }else{
        npSetLED(led_sequence[i],128,0,0);
        }
    }
        npWrite();
        sleep_ms(10);
    

    for (uint i =0; i<led_count; i++){
        npSetLED(led_sequence[i],0,0,0);
        npWrite();
        sleep_ms(200);
    }


}
int main () {
    stdio_init_all();

    // Iicializa a matriz de LEDs neoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();
    
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    //animacaoBasica();
    //npSetLED(0, 128, 0, 0); // A título de teste, atribui a cor vermelha ao primeiro LED com 50% de intensidade
    //animacaoCorrida();
    //animacaoQuadradoCentro();
    animacaoQuadradoPulsante();
    // Escreve o buffer de LEDs no controlador
//    npWrite();

    while(true){
        sleep_ms(1000);
    }
    
}