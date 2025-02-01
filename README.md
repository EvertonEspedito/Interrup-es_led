
Configuração do Temporizador:

Utiliza um temporizador para gerar interrupções em intervalos regulares.
A cada interrupção, o código atualiza o estado da matriz de LEDs para criar a animação desejada.
Loop Principal:

O loop principal do programa permanece em execução, enquanto as atualizações da matriz são gerenciadas pelas interrupções do temporizador.
Como Executar o Projeto
Clone o repositório:

bash
Copiar
Editar
git clone https://github.com/LuizEduardo-cyber/Luiz-Eduardo-CEPEDI-tarefa1-27-01.git
Navegue até o diretório do projeto:

bash
Copiar
Editar
cd Luiz-Eduardo-CEPEDI-tarefa1-27-01
Configure o ambiente de desenvolvimento:

Certifique-se de ter o SDK do Raspberry Pi Pico instalado.
Configure as variáveis de ambiente conforme necessário.
Compile o projeto:

bash
Copiar
Editar
mkdir build
cd build
cmake ..
make
Carregue o firmware:

Conecte o Raspberry Pi Pico ao computador em modo de armazenamento USB.
Copie o arquivo .uf2 gerado para o dispositivo.
Execute o projeto:

Após o carregamento, o código será executado automaticamente no Raspberry Pi Pico, controlando a matriz de LEDs conforme programado.
Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests. Por favor, siga as diretrizes de contribuição antes de fazer alterações.

Licença
Este projeto está licenciado sob a [Nome da Licença]. Consulte o arquivo LICENSE para obter mais informações.

Contato
Para dúvidas ou sugestões, entre em contato através do e-mail: [seu-email@example.com].

Vídeo Demonstrativo
Para uma demonstração visual do projeto, assista ao vídeo abaixo:
