#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/clocks.h"
#include "pio_config.h"
#include "hardware/pwm.h"
#include "pico/bootrom.h"


// Biblioteca gerada pelo arquivo ws2818b.pio 
#include "ws2818b.pio.h"

//Codigo Teclado 4x4 
#include "teclado.h"

//Animações Hugo S. Dias
#include "libs/animacao_hugo.c"

//Animações Gabriel
#include "libs/animacao_gabriel.c"

// Definições gerais do projeto
#include "libs/definicoes.h"



// Funcao auxiliar para utilização do buzzer de forma modular
void set_pwm_pin(uint pin, uint freq, uint duty_c) {
		gpio_set_function(pin, GPIO_FUNC_PWM);
		uint slice_num = pwm_gpio_to_slice_num(pin);
    		pwm_config config = pwm_get_default_config();
		float div = (float)clock_get_hz(clk_sys) / (freq * 10000);
		pwm_config_set_clkdiv(&config, div);
		pwm_config_set_wrap(&config, 10000); 
		pwm_init(slice_num, &config, true); 
		pwm_set_gpio_level(pin, duty_c); 
	};


// Musica simples buzzer - Arthur A L Trindade
void tocarMusicaCurta() {
    const uint16_t frequencias[] = {392, 392, 349, 330, 392, 392, 349, 330, 392, 440, 392,
                                    349, 330, 294, 294, 330, 349, 294,330, 349, 294, 330,
                                    349, 392, 440, 392, 349, 330, 294, 262}; // Notas: SOL, FA, MI, etc.
    const uint16_t duty[] =        {300, 300, 400, 400, 300, 300, 400, 400, 300, 300, 300,
                                    300, 300, 400, 300, 300, 300, 300, 300, 300, 300, 300,
                                    300, 300, 300, 300, 300, 300, 400, 600};     // Ciclo de trabalho em ms
    const uint16_t duracoes[] =    {350, 350, 300, 300, 350, 300, 300, 300, 300, 350, 300,
                                    300, 300, 350, 300, 300, 300, 300, 300, 300, 300, 300,
                                    300, 300, 300, 300, 350, 350, 350, 300};     // Durações em ms
    
    const uint16_t notas = sizeof(frequencias) / sizeof(frequencias[0]);    // Durações das notas em ms
    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

    for (uint16_t i = 0; i < notas; i++) {
        set_pwm_pin(BUZZER_PIN, frequencias[i], duty[i]);
        sleep_ms(duracoes[i]);
        pwm_set_enabled(slice_num, false);
        sleep_ms(50); // Pausa entre as notas
    }

    pwm_set_enabled(slice_num, false);

}

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
    printf("Reiniciando o microcontrolador\n");
    reset_usb_boot(0, 0);
}
//codigo teste


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
    
  // Inicializa a matriz de LEDs com cor inicial (verde)
  //  initializeMatrix(ledMatrix, 0, 255, 0);
    //exemplo de uso da função npSetLED para acender um LED de cada vez
    //animacaoBasica();
 //   tocarMusicaCurta(); //teste buzzer
 //    animateMatrix(ledMatrix, 10); // Executa a animação
    // Escreve o buffer de LEDs no controlador
//   npWrite();



    while(true){
//  sleep_ms(1000); // Tempo de teste
 // Verifica se o botão foi pressionado
        if (!gpio_get(BUTTON_PIN_A)) { // Botão pressionado (nível baixo)
            printf("Botão pressionado! Executando ação...\n");
            tocarMusicaCurta();
        }

        if (!gpio_get(BUTTON_PIN_B)) { // Botão pressionado (nível baixo)
            printf("Botão pressionado! Executando ação...\n");
            animacaoBasica();
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
      //          set_leds(0, 0, 0); // Desliga todos os LEDs
     
                break;
    } 
    
    sleep_ms(100); // Estabilização  
  
    }
    
}