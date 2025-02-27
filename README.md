# Projeto final: Analisador de energia elétrica
Este projeto tem como objetivo mostrar as funcionalidades do ADC do RP2040 utilizando um joystick como entrada na placa da BitDogLab, além da representação visual através de um display.

## Como baixar e executar o código
    1-Baixar ou utilizar git clone no repositório.
          git clone https://github.com/MSoares0079/Projeto_final_analisador_energia.git
    2-Ter o VS Code instalado e devidamente configurado.
    3-Ter a extensão do Raspberry Pi Pico instalada no VS Code.
    4-Compilar o arquivo "Projeto_final_analisador_energia.c" utilizando o compilador do Raspberry Pi Pico.
    5-O código pode ser tanto simulado pelo "diagram.json" apartir da extensão Wokwi quanto compilado na placa da BitDogLab.

## Estrutura do código

A função principal (int main) inicializa e configura os pinos que serão utilizados no código sendo eles: botões,LEDs,buzzer,joystick e o display, além de ativar interrupção para os botões e do temporizador.

    O temporizador foi programado para a cada 60 segundos zerar todos os contadores de contingência.
    
    E ao precionar o botão A da placa da BitDogLab a variavel (estado_LED) é alterado, ou seja desativando/ativando os LEDs da Matriz.
    
    O botão B da placa da BitDogLab é alterado a variavel (estado_buzzer) em que desativa/ativa o funcionamento do buzzer.
    
    Já o botão do joystick altera a variavel (selecao_modo) em que altera tanto o funcionamento do programa na função principal quanto o que o display mostra.

No loop infinito ocorre a multiplexação dos canais do ADC, em que é feita a conversão primeiro do eixo x e depois do eixo y, salvando os valores em variaveis.
Conforme o modo selecionado o display desenha as seguintes informações:

    No modo mediçao apresenta: tensão,corrente e fator de potência.
    
    No modo log de eventos mostra os contadores de contigência: subtensão, sobretensão e sobrecorrente.
    
    O modo calibração: Altera os valores de referência da resistência e reatância.


## Link do vídeo demonstrando o código funcionando na placa
https://drive.google.com/file/d/18MpZo8AQns1Uqrt_CDItLGce3UaG9jr_/view?usp=sharing
