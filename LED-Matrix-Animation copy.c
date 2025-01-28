#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "pio_config.h"
#include "hardware/pwm.h"
#include "pico/bootrom.h"

// Biblioteca gerada pelo arquivo ws2818b.pio 
#include "ws2818b.pio.h"


//Biblioteca para implementação do teclado 4x4 
#include "MatrixKeypad.h"

//Codigo Teclado 4x4 
#include "teclado.h"

//Codigo Arthut Alencar
// Codigo pwm buzzer
#include "libs/local_pwm.c"

//Animações Hugo S. Dias
#include "libs/animacao_hugo.c"

//Animações Gabriel
#include "libs/animacao_gabriel.c"

//Jackson S. dos Santos
#include "libs/animacao_jackson.c"

//Alinne
#include "libs/animacao_aline.c"

//João Vitor S. Amorim
#include "libs/animacao_joao.c"

//Codigo Arthur Alencar
#include "libs/animacao_arthur.c"

//Codigo Sergio
#include "libs/animacao_sergio.c"

// Definições gerais do projeto
#include "libs/definicoes.h"


int reboot_loader()
{
    // Reinicia o microcontrolador
    printf("Reiniciando o microcontrolador\n");
    reset_usb_boot(0, 0);
}
//codigo teste


int main () {
    stdio_init_all();

    // Iicializa a matriz de LEDs neoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();

    gpio_init(BUTTON_PIN_A);
    gpio_set_dir(BUTTON_PIN_A, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_A);

    gpio_init(BUTTON_PIN_B);
    gpio_set_dir(BUTTON_PIN_B, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_B);


    iniciar_teclado();    
    


    while(true){
//  sleep_ms(1000); // Tempo de teste
 // Verifica se o botão foi pressionado
        if (!gpio_get(BUTTON_PIN_A)) { // Botão pressionado (nível baixo)
            printf("Botão pressionado! Executando ação...\n");
            tocarMusicaCurta();
        }

        if (!gpio_get(BUTTON_PIN_B)) { // Botão pressionado (nível baixo)
            printf("Botão pressionado! Executando ação...\n");
            tocarMusicaCurta();
        }
        // Leitura do teclado
       char tecla = leitura_teclado();
        printf("Tecla pressionada: %c\n", tecla);
               
        // Configuração dos LEDs com base na tecla pressionada
        switch (tecla) {
            case 'A':
                printf("Impresso o letra A\n");
                animacaoTeclaA();
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
            //jackson
                animacaoTecla0();
                printf("Executando animação tecla 0\n");
                sleep_ms(300);     
      
                break;

            case '1':
            //alinne             
                animacaoQuadradoPulsante();
                printf("Executando animação tecla 1\n");
                sleep_ms(300);     
         
                break; 

            case '2':
            //alinne
                animacaoOnda();
                printf("Executando animação tecla 2\n");
                sleep_ms(300);     // Tempo de teste
                break;

            case '3':
            //joao vitor
                animacaoEspiral();
                printf("Executando animação tecla 3\n");
                sleep_ms(300);     // Tempo de teste
                break;
            
            case '4':
            //joao vitor
                animacaoCoracaoPulsante();
                printf("Executando animação tecla 4\n");
                sleep_ms(300);     // Tempo de teste
                break;
            case '5':
            //hugo
                initializeMatrix(ledMatrix, 0, 255, 0);
                animateMatrix(ledMatrix, 15); // Executa a animação
                printf("Executando animação tecla 5\n");
                sleep_ms(300);     // Tempo de teste
                break;
            case '6':
            //funçao de teste
                animacaoBasica();
                printf("Executando animação tecla 6\n");
                sleep_ms(300);     // Tempo de teste
                break;
            case '7':
            //sergio 
                animacao_tecla_7();
                printf("Executando animação tecla 7\n");
                sleep_ms(300);     // Tempo de teste
                break;

            case '8':
            //gabriel
                 animacao_tecla_8();
                printf("Executando animação tecla 8\n");
                sleep_ms(300);     // Tempo de teste
                break;
            
            case '9':
            //gabriel
                 animacao_tecla_9();
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