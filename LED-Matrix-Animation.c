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





//implementação do teclado 
int main() {
    // Inicialização do sistema (UART para debug e outros periféricos)
    stdio_init_all();

    // Inicializa a matriz de LEDs neoPixel
    npInit(MATRIX_LED_PIN);
    // Limpa a matriz de LEDs
    npClear();

    gpio_init(BUTTON_PIN_A);
    gpio_set_dir(BUTTON_PIN_A, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_A);

    gpio_init(BUTTON_PIN_B);
    gpio_set_dir(BUTTON_PIN_B, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_B);

    // Criação do objeto MatrixKeypad
    MatrixKeypad_t *keypad = MatrixKeypad_create((char *)keyMap, rowPins, colPins, ROWSPIN, COLSPIN);
    if (keypad == NULL) {
        printf("Erro: Falha ao inicializar o teclado matricial!\n");
        return 1;
    }

    printf("Teclado matricial iniciado. Pressione uma tecla:\n");

    while (true) {
        // Verifica se os botões foram pressionados
        if (!gpio_get(BUTTON_PIN_A)) { // Botão pressionado (nível baixo)
            printf("Botão A pressionado! Executando ação...\n");
            tocarMusicaCurta();
        }

        if (!gpio_get(BUTTON_PIN_B)) { // Botão pressionado (nível baixo)
            printf("Botão B pressionado! Executando ação...\n");
            tocarMusicaCurta();
        }

        // Escaneia o teclado
        MatrixKeypad_scan(keypad);

        // Verifica se uma tecla foi pressionada
        if (MatrixKeypad_hasKey(keypad)) {
            char key = MatrixKeypad_getKey(keypad);  // Obtém a tecla pressionada
            printf("Tecla pressionada: %c\n", key);

            // Adiciona o switch case para tratar as opções 'A', 'B' e 'C'
            switch (key) {
                 case 'A':
                printf("Ação para a tecla A\n");
                animacaoTeclaA();
                sleep_ms(200);     
                break;
           case 'B':
                printf("Ação para a tecla B\n");
                sleep_ms(200);   
                break;
            case 'C':
                printf("Ação para a tecla C\n");
                sleep_ms(200);     
                break;
            case 'D':
                printf("Ação para a tecla D\n");
                sleep_ms(200);     
                break;

            case '#':
                printf("Ação para a tecla_#\n");
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
                initializeMatrix(ledMatrix, 0, 255, 0);
                animateMatrix(ledMatrix, 10); // Executa a anima
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
                 animacao_tecla_8();
                printf("Executando animação tecla 8\n");
                sleep_ms(300);     // Tempo de teste
                break;
            
            case '9':
                 animacao_tecla_9();
                printf("Executando animação tecla 9\n");
                sleep_ms(300);     // Tempo de teste
                break;
                default:
                    printf("Tecla '%c' não possui ação configurada.\n", key);
                    break;
            }
        }

        // Delay para evitar leituras repetidas
        sleep_ms(100);
    }

    return 0;
}

