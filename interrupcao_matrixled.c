#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "interrupcao_matrixled.h"

// Definição dos pinos dos LEDs e botões
const uint LED_RED = 13;
const uint LED_BLUE = 12;
const uint LED_GREEN = 11;
const uint BUTTON_A = 5;
const uint BUTTON_B = 6;

#define TEMPO_DEBOUNCE 200 // Tempo de debounce para evitar múltiplos acionamentos rápidos
static volatile uint a = 0; // Variável para armazenar o contador de botões pressionados
static volatile uint32_t last_time = 0; // Armazena o tempo da última interrupção

// Função para inicializar os GPIOs
void init_gpios(){
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT); // Define LED como saída

    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A); // Ativa pull-up para evitar leituras flutuantes

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B); // Ativa pull-up para evitar leituras flutuantes
}

// Declaração da função de interrupção
void gpio_irq_handler(uint gpio, uint32_t events);

int main() {
    init_gpios(); // Inicializa os GPIOs
    initNeoPixel(); // Inicializa a matriz de LEDs (provavelmente via NeoPixel)
    stdio_init_all(); // Inicializa entrada/saída padrão (USB para printf)

    // Configura as interrupções nos botões para detectar borda de descida (pressionamento)
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (true) {
        // Faz o LED vermelho piscar a cada 200ms para indicar que o sistema está rodando
        gpio_put(LED_RED, true);
        sleep_ms(200);
        gpio_put(LED_RED, false);
        sleep_ms(200);
    }
}

// Função de interrupção chamada quando um botão é pressionado
void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_us_since_boot(get_absolute_time()); // Obtém o tempo atual
  
    if (current_time - last_time > 200000) { // Verifica debounce (200ms)
        last_time = current_time; // Atualiza o tempo da última interrupção

        if (gpio == BUTTON_A) { 
            printf("Incrementando = %d\n", a);
            a++;  // Incrementa o valor de `a`
        }

        if (gpio == BUTTON_B) { 
            printf("Decrementando = %d\n", a);
            a--;   // Decrementa o valor de `a`
        }

        // Atualiza a matriz de LEDs conforme o valor de `a`
        switch (a) {
            case 0:
            case 1:
                A_0();
                break;
            case 2:
                A_1();
                break;
            case 3:
                A_2();
                break;
            case 4:
                A_3();
                break;
            case 5:
                A_4();
                break;
            case 6:
                A_5();
                break;
            case 7:
                A_6();
                break;
            case 8:
                A_7();
                break;
            case 9:
                A_8();
                break;
            case 10:
                A_9();
                break;
            default:
                default_(); // Exibição padrão caso `a` esteja fora do intervalo esperado
                break;
        }
    }
}
