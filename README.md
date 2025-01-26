# Atividade (Obrigatória): Geração de animações em uma matriz de LEDs 5x5

## **Líder da Equipe**
Hugo S. Dias

## **Sub-Líder**
`A definir`

---

## **Descrição Geral**
Este projeto utiliza um Raspberry Pi Pico W na plataforma de apredizagem BitDogLab, um teclado matricial 4x4 e uma matriz de LEDs RGB 5x5 (WS2812). Ao pressionar teclas específicas no teclado, diferentes animações de LED são exibidas. Além disso, funcionalidades adicionais como ajuste de cores e luminosidade foram implementadas para ampliar a interação.

---

## **Funcionalidades**
1. **Animações para teclas de 0 a 9:**  
   Cada tecla exibe uma animação diferente na matriz de LEDs.

2. **Funções específicas para teclas especiais:**  
   - **A:** Desliga todos os LEDs.  
   - **B:** Liga todos os LEDs na cor azul (100% luminosidade).  
   - **C:** Liga todos os LEDs na cor vermelha (80% luminosidade).  
   - **D:** Liga todos os LEDs na cor verde (50% luminosidade).  
   - **#:** Liga todos os LEDs na cor branca (20% luminosidade).

3. **Modo de gravação via tecla \*:**  
   Habilita o modo de gravação (reboot do sistema).

4. **Sinal sonoro opcional:**  
   Um buzzer pode ser configurado para emitir sons.

---

## **Colaboradores e Proposta para Divisão das Tarefas**

1. **Líder da equipe** - Hugo S. Dias
2. **Inicialização e preparação codigo base - inicial**. - `A definir` 
3. **Configuração e integração do teclado matricial (4x4).** - `A definir`  
4. **Controle e animação dos LEDs para tecla "0".** - `A definir`
5. **Controle e animação dos LEDs para tecla "1".** - `A definir`
6. **Controle e animação dos LEDs para tecla "2".** - `A definir`
7. **Controle e animação dos LEDs para tecla "3".** - `A definir`
8. **Controle e animação dos LEDs para tecla "4".** - `A definir`
9. **Controle e animação dos LEDs para tecla "5".** - `A definir`
10. **Controle e animação dos LEDs para tecla "6".** - `A definir`
11. **Controle e animação dos LEDs para tecla "7".** - `A definir`
12. **Controle e animação dos LEDs para tecla "8".** - `Gabriel Santos de Lacerda`
13. **Controle e animação dos LEDs para tecla "9".** - `Gabriel Santos de Lacerda`
14. **Configuração e execução das funcionalidades das teclas A, B, C, D e #** - `A definir`
15. **Implementação da tecla \* (modo gravação via software).** - `A definir`
16. **Configuração do buzzer (opcional) e participação nos testes.** - `A definir`

---

## **Diagrama de Conexões**

1. **Teclado Matricial (4x4):**
   - Linhas -> GPIOs 18, 19, 20, 4
   - Colunas -> GPIOs 16, 17, 9, 8

2. **Matriz de LEDs RGB 5x5 (WS2812):**
   - Conectada ao GPIO 7

3. **Buzzer (opcional):**
   - Conectado ao GPIO 21

---

## **Configuração do Ambiente**

1. **Instale o SDK do Raspberry Pi Pico:**  
   Siga o guia oficial de instalação do [Pico SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html).

2. **Clone o repositório:**  
   ```bash
   git clone https://github.com/Embarcatech/LED-Matrix-Animation.git
   cd LED-Matrix-Animation
   ```

3. **Compile o código:**  
   Utilize o Visual Studio Code com o CMake e o Pico SDK instalados.

---

## **Como Usar**

1. Conecte os componentes conforme o diagrama de conexões.  
2. Carregue o firmware no Raspberry Pi Pico W.  
3. Interaja com o teclado para observar as animações e funcionalidades implementadas.  

---

## **Vídeo de Apresentação**
