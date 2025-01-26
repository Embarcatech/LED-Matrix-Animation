#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "pio_config.h"

// Biblioteca gerada pelo arquivo ws2818b.pio 
#include "ws2818b.pio.h"

#include "teclado.h"
#include "animacoes.h"


// Definição da quantidade de LEDs e o pino de controle
#define LED_COUNT 25

#define MATRIX_LED_PIN 7 // PINO DA MATRIZ DE LEDS ws2818b
#define BUZZER_PIN 21 // PINO DO BUZZER


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