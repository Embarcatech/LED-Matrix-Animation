
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#include "definicoes.h"



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
//Alinne de Souza Santos Castro
void musicabottonB(){

const uint16_t frequencia[] = {
    262,262,294,262,349,330,
    262,262,294,262,392,349,
    262,262,262,440,349,330,
    440,440,392,349,330,294
};

const uint16_t duty[] = {
    300, 300, 300, 300, 300, 300,  
    300, 300, 300, 300, 300, 300,  
    300, 300, 300, 300, 300, 300,  
    300, 300, 300, 300, 300, 300,  
};
const uint16_t duracao[] = {
    400, 400, 800, 400, 400, 800,  // Parabéns a você
    400, 400, 800, 400, 400, 800,  // Nesta data querida
    400, 200, 200, 400, 400, 400,800, // Muitas felicidades
    400, 360, 450, 400, 400, 350,800  // Muitos anos de vida
 };

const char* letras[] = {
        "Parabéns a você,",
        "Nesta data querida,",
        "Muitas felicidades,",
        "Muitos anos de vida."
    };
const uint16_t nota = sizeof(frequencia) / sizeof(frequencia[0]);
uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);

// Inicializa o PWM para o pino do buzzer
pwm_set_enabled(slice_num, true);
uint16_t letra_index = 0;

for (uint16_t i = 0; i < nota; i++) {
    // Configura a frequência e o duty cycle do buzzer
    set_pwm_pin(BUZZER_PIN, frequencia[i], duty[i]);
    
     // A cada mudança de parte da música, exibe a letra correspondente
        if (i == 0 || i == 6 || i == 12 || i == 18) {
            printf("%s\n", letras[letra_index]);
            letra_index++;
        }
    // Toca a nota pela duração especificada
    sleep_ms(duracao[i]);
    
    // Pausa entre as notas
    sleep_ms(50);
}

// Desativa o PWM ao final de todas as notas
pwm_set_enabled(slice_num,false);
}