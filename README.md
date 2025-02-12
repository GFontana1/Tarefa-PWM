# Tarefa PWM - Embarcatech

## Descrição do Projeto

O programa controla a flange de um servomotor ou a potência de um LED através do protocolo PWM (*Pulse Width Modulation*) ao utilizar:

- 1 LED Azul
- 1 Servomotor

## Funcionalidades

1. Ao utilizar o pino 22 como PWM
    - O sistema controla a flange do servomotor de maneira que:
        - Ao iniciar o programa, primeiro a flange vai para a posição 180 graus.
        - Após 5 segundos, ela fica a 90 graus.
        - Passados mais 5 segundos, a flange vai para 0 graus.
        - Depois de esperar mais 5 segundos, ela inicia um loop infinito em que vai de 180 a 0 graus a 180 novamente.

2. Ao utilizar o pino 12 como PWM
    - O sistema controla a LED azul, fazendo com que a mesma fique em um loop com seu brilho pulsando.

## Como rodar o código

1. *Necessário para compilar o código:*
    - Ter uma placa Raspberry Pi Pico W que contenha os componentes descritos na *Descrição do projeto*.
    - Ter o SDK do Raspberry Pi Pico W configurado.
    - Compilar o código utilizando CMake e GCC ARM.
    - Licença do simulador Wokwi

2. *Transferir para o Raspberry Pi Pico W*:
   - Conecte sua placa ao computador com ela no modo **Bootsel**.
   - Monte a unidade **RPI-RP2** no computador.
   - Copie o arquivo compilado `.uf2` para a unidade montada ou aperte em Run na interface do VSCode caso tenha configurado a placa com o Zadig.
  
## Vídeo de demonstração:
https://youtu.be/BjX6eHjX0N8
