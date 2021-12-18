# Biblioteca Serial Debug para Arduino Due
[![platform badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://github.com/arduino)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/SciCoBot/serial_debug/blob/main/LICENSE)


## Contents

- [Sobre](#sobre)
- [Comandos Básicos](#comandos-básicos)
- [Como Utilizar](#como-utilizar)
- [Possíveis Atualizações](#possíveis-atualizações)
- [Anotações de Desenvolvimento](#anotações-de-desenvolvimento)


## Sobre

A IDE oficial do Arduino não possui depurador. Por isso, geralmente usa-se mensagens Serial como forma de depuração no Arduino, como *Serial.print(...)*.

Neste aspecto, serial_debug é uma biblioteca que fornece macros e funções de classe para auxiliar na depuração serial para Arduino, sem a necessidade de hardware extra para isso.

Para a criação desta bibliote baseou-se em [library tutorial](https://www.arduino.cc/en/Hacking/libraryTutorial) e [API style guide](https://www.arduino.cc/en/Reference/APIStyleGuide).

## Comandos Básicos

### Macros:
- **Debug::DEBUG:** funciona como *Serial.print*. Envia uma mensagem serial que pode ser visualizada em serial monitor.
- **Debug::DEBUGLN:** funciona como Serial.println. Envia uma mensagem serial seguida de uma linha em branco, que pode ser visualizada em serial monitor. 
- **Debug::SEPARATOR():** Usado para imprimir na tela vários "-", a fim de separar visualmente conteúdos de mensagens.
- **DEBUG_PRINT_FILE(Debug):** mostra o nome do arquivo no qual o código que está sendo executado no momento pertence.
- **DEBUG_PRINT_LINE(Debug):** mostra a linha do arquivo no qual o código que está sendo executado no momento pertence.
- **DEBUG_PRINT_PRETTY_FUNCTION(Debug):** mostra o nome da função no qual o código que está sendo executado no momento pertence.
- **PRINTVARIABLE:** mostra o nome e o valor de uma variável.

### Funções:
- **Debug::debugTime:** mostra o tempo de execução no momento de execução, no formato: horas:minutos:segundos:milissegundo  
- **Debug::debugTimeBreak:** espera (por default 5 segundos) receber uma mensagem serial e, ao receber, envia a mensagem via serial, que por sua vez, pode ser visualizada em serial monitor.

## Como Utilizar

- Baixe.

<p align="center"> 
<img src="https://github.com/SciCoBot/serial_debug/blob/main/images/telaRespositorioBaixar.png" alt="Repositório Baixar" width="650"/>
</p>

- Adicione a partir da IDE arduino: Sketch -> Include Library -> Add .ZIP Library... -> selecione o arquivo baixado na etapa anterior.

<p align="center"> 
<img src="https://github.com/SciCoBot/serial_debug/blob/main/images/telaArduino.png" alt="Tela Aruino" width="500"/>
</p>

- Teste o exemplo.

Obseervação: A biblioteca pode inutilizada caso a definição de SERIAL_DEBUG_ENABLE seja retirada, evitando sobrecarga de memória para quando o uso não é necessário.

## Possíveis Atualizações

- Avisar quando uma determinada variável é alterada;
- Executar funções via monitor serial;
- Alterar valor de variáveis via monitor serial;

## Anotações de Desenvolvimento

- Avaliar alteração de _serial para público, colocando como "constante" apenas para leitura;
- Avaliar a implementação de printf;
- Colocar diferentes níveis de mensagem, como: detalhado, aviso e erro.
