# Atividade (Obrigatória): Geração de animações em uma matriz de LEDs 5x5

## **Líder da Equipe**
Hugo S. Dias

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

1. **Líder da equipe** - `Hugo S. Dias`
2. **Inicialização e preparação codigo base - inicial**. - `JACKSON SILVA DOS SANTOS` 
3. **Configuração e integração do teclado matricial (4x4).** - `HUGO S. DIAS`  
4. **Controle e animação dos LEDs para tecla "0".** - `JACKSON SILVA DOS SANTOS`
5. **Controle e animação dos LEDs para tecla "1".** - `ALINNE DE SOUZA SANTOS CASTRO`
6. **Controle e animação dos LEDs para tecla "2".** - `ALINNE DE SOUZA SANTOS CASTRO`
7. **Controle e animação dos LEDs para tecla "3".** - `JOÃO VITOR SOARES AMORIM`
8. **Controle e animação dos LEDs para tecla "4".** - `JOÃO VITOR SOARES AMORIM`
9. **Controle e animação dos LEDs para tecla "5".** - `HUGO S. DIAS`
10. **Controle e animação dos LEDs para tecla "6".** - `SÉRGIO EMÍLIO DA CUNHA MEIRA SANTOS`
11. **Controle e animação dos LEDs para tecla "7".** - `SÉRGIO EMÍLIO DA CUNHA MEIRA SANTOS`
12. **Controle e animação dos LEDs para tecla "8".** - `GABRIEL SANTOS DE LACERDA`
13. **Controle e animação dos LEDs para tecla "9".** - `GABRIEL SANTOS DE LACERDA`
14. **Configuração e execução das funcionalidades das teclas A, B, C, D e #** - `A definir`
15. **Implementação da tecla \* (modo gravação via software).** - `A definir`
16. **Configuração do buzzer (opcional) e participação nos testes.** - `ARTHUR ALENCAR LOPES TRINDADE`
17. **Documentação, usabilidade e IHM - Interface Home Maquina no README.md** - `A definir`
---

## **Diagrama de Conexões**

1. **Teclado Matricial (4x4):**
   - Linhas -> GPIOs 18, 19, 20, 4
   - Colunas -> GPIOs 16, 17, 9, 8

2. **Matriz de LEDs RGB 5x5 (WS2812):**
   - Conectada ao GPIO 7

3. **Buzzer (opcional):**
   - Conectado ao GPIO 21
   
4. **Botões A e B - BitDogLab - Adicional**
   - Conectado ao GPIO 5 e 6
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
