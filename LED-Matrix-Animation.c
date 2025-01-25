#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"

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


// INICIO DA 1 ANIMAÇÃO
void animacaoQuadradoPulsante(){
    //Define as posições dos LEDs que formarão o quadrado
    const uint led_sequence[] = {0,9,10,19,20,21,22,23,24,15,14,5,4,3,2,1,0,12};
    const uint led_count = sizeof(led_sequence)/ sizeof(led_sequence[0]);

    for(int i = 0; i<led_count; i++){
        if(led_sequence[i]==12){
            npSetLED(led_sequence[i],255,0,255);
        }else{
        npSetLED(led_sequence[i],255,0,0);
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
// FIM DA 1 ANIMAÇÃO


//INICIO DA SEGUNDA ANIMAÇÃO

void animacaoOnda(){
   //Define as posiçoes dos LEDs que formarão a sequencia
   const uint led_sequence[] = {0,9,10,19,20,21,18,11,8,1,2,7,12,17,22,23,16,13,6,3,4,5,14,15,24};
    const uint led_count = sizeof(led_sequence) / sizeof(led_sequence[0]);

    //Define a velocidade do cometa e do rastro
    const uint tempo_rastro = 100;
    const uint tempo_cometa = 100;
    
    //Define as cores
    const uint8_t cometa_R = 255;
    const uint8_t cometa_G = 0;
    const uint8_t cometa_B = 0;
    const uint8_t rastro_R = 0;
    const uint8_t rastro_G = 0;
    const uint8_t rastro_B = 255;

    npClear();//Limpa os LEDs antes de iniciar a animação

    //Faz o movimento de onda
    for(uint i = 0; i<led_count;i++){
        npClear();

        //Acende o rastro até a posição atual
        for(uint j=0; j<=i; j++){
            npSetLED(led_sequence[j],rastro_R,rastro_G,rastro_B);//rastro azul
            }

            //Acende o cometa na posição atual
            npSetLED(led_sequence[i],cometa_R,cometa_G,cometa_B);//Cometa vermelho

            npWrite(); //Atualiza os LEDs
            sleep_ms(tempo_rastro);
    }
            npClear();
            npWrite();
}

// FIM DA SEGUNDA ANIMAÇÃO

int main () {
    stdio_init_all();
    int opcao;
    printf("Sistema iniciado\n");
    // Inicializa a matriz de LEDs NeoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();

    while (true) {
        printf("\nDigite:\n");
        printf(" 1 - quadrado\n");
        printf(" 2 - onda\n");
        printf(" 0 - Sair\n");
        printf("Digite o comando: ");

        // Lê a opção escolhida
        opcao = getchar() - '0'; // Converte o caractere para inteiro

        // Processa a opção
        if (opcao == 1) {
            animacaoQuadradoPulsante();
        } else if (opcao == 2) {
            animacaoOnda();
        } else if (opcao == 0) {
            break; // Encerra o programa
        } else {
            printf("\nComando inválido\n");
 }
}
}