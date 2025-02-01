# Interrupções com LED no Raspberry Pi Pico

Este projeto demonstra o uso de interrupções no Raspberry Pi Pico para controlar LEDs com botões físicos. Ele utiliza a biblioteca `pico/stdlib.h` e manipula GPIOs para detecção de eventos nos botões.

## 📌 Funcionalidades
- Pisca um LED vermelho para indicar funcionamento.
- Usa interrupções para detectar pressionamentos nos botões.
- Incrementa e decrementa um contador com os botões `BUTTON_A` e `BUTTON_B`.
- Atualiza uma matriz de LEDs conforme o valor do contador.

## 🎥 Video
- Assistir()[]


## 🛠️ Configuração do Hardware
| Componente  | Pino GPIO |
|------------|----------|
| LED Vermelho  | 13 |
| LED Azul  | 12 |
| LED Verde  | 11 |
| Botão A  | 5 |
| Botão B  | 6 |

Os botões utilizam `pull-up` interno para evitar leituras flutuantes.

## 📜 Como funciona o código
1. **Inicializa os GPIOs** para LEDs e botões.
2. **Configura interrupções** para acionar eventos ao pressionar os botões.
3. **A função `gpio_irq_handler`** incrementa ou decrementa um contador ao pressionar os botões.
4. **O valor do contador** é usado para modificar a matriz de LEDs.
5. **O LED vermelho pisca** continuamente para indicar que o sistema está ativo.

## 🚀 Como compilar e executar
1. Instale o **Raspberry Pi Pico SDK**.
2. Clone este repositório:
   ```sh
   git clone https://github.com/EvertonEspedito/Interrup-es_led.git
   ```
3. Compile o código usando CMake e GCC para ARM.
4. Copie o arquivo `.uf2` gerado para o Pico.
5. Abra um terminal para visualizar a saída com `minicom` ou `screen`.

## 🏗️ Dependências
- Raspberry Pi Pico SDK
- Biblioteca `hardware/timer.h`
- Biblioteca `pico/stdlib.h`

## 📝 Licença
Este projeto está sob a licença MIT.

## 📩 Contato
Criado por **Everton Espedito**. Para dúvidas ou sugestões, entre em contato!

