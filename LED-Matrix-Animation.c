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
  
     npClear();
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    for (uint i = 0; i < LED_COUNT; i++){
        npSetLED(i, 128, 0, 0);
        sleep_ms(200);
        npWrite();
        }

}

//ok implementado
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

//Codigo Alinne 

//ok implementado
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

int reboot_loader()
{
    // Reinicia o microcontrolador
    //reset_usb_boot
    printf("Reiniciando o microcontrolador\n");
}
//codigo teste


int main () {
    stdio_init_all();

    // Iicializa a matriz de LEDs neoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();

    iniciar_teclado();    

    //exemplo de uso da função npSetLED para acender um LED de cada vez
    //animacaoBasica();

    
    // Escreve o buffer de LEDs no controlador
//   npWrite();

    while(true){
//  sleep_ms(1000); // Tempo de teste

        // Leitura do teclado
       char tecla = leitura_teclado();
        printf("Tecla pressionada: %c\n", tecla);
               
        // Configuração dos LEDs com base na tecla pressionada
        switch (tecla) {
            case 'A':
              //  set_leds(1, 0, 0); // Botão A acende o LED vermelho
                printf("Impresso o letra A\n");
                sleep_ms(200);     
                break;
           case 'B':
                printf("Impresso o letra B\n");
                sleep_ms(200);   
                break;
            case 'C':
                printf("Impresso o letra C\n");
                sleep_ms(200);     
                break;
            case 'D':
                printf("Impresso o letra D\n");
                sleep_ms(200);     
                break;

            case '#':
                printf("tecla # pressionada\n");
                sleep_ms(200);     
                break;

            case '*':
                printf("Reiniciando o microcontrolador\n");
                reboot_loader(); // Reinicia o microcontrolador
                break;
            
            case '0':
                animacaoTecla0();
                printf("Executando animação tecla 0\n");
                sleep_ms(300);     
      
                break;

            case '1':             
                animacaoQuadradoPulsante();
                printf("Executando animação tecla 1\n");
                sleep_ms(300);     
         
                break; 

            case '2':
                animacaoOnda();
                printf("Executando animação tecla 2\n");
                sleep_ms(300);     // Tempo de teste
                break;

            case '3':
                animacaoEspiral();
                printf("Executando animação tecla 3\n");
                sleep_ms(300);     // Tempo de teste
                break;
            
            case '4':
                animacaoCoracaoPulsante();
                printf("Executando animação tecla 4\n");
                sleep_ms(300);     // Tempo de teste
                break;
            case '5':
                animacaoBasica();
                printf("Executando animação tecla 5\n");
                sleep_ms(300);     // Tempo de teste
                break;
            case '6':
                animacaoBasica();
                printf("Executando animação tecla 6\n");
                sleep_ms(300);     // Tempo de teste
                break;
            case '7':
                animacaoBasica();
                printf("Executando animação tecla 7\n");
                sleep_ms(300);     // Tempo de teste
                break;

            case '8':
                animacaoBasica();
                printf("Executando animação tecla 8\n");
                sleep_ms(300);     // Tempo de teste
                break;
            
            case '9':
                animacaoBasica();
                printf("Executando animação tecla 9\n");
                sleep_ms(300);     // Tempo de teste
                break;
            

            default:
      //          set_leds(0, 0, 0); // Desliga todos os LEDs
     
                break;
    } 
    
    sleep_ms(100); // Estabilização  
  
    }
    
}