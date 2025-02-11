//Bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Define o pino 22 como PWM
#define PWM_GPIO 22 // Para testar com um led altere esse valor para 12, como indicado no pdf da atividade

// Função para movimentar o servomotor
void move(uint16_t start, uint16_t end, int16_t time){
    uint16_t value = start;
    
    // Enquanto value for menor que end, incremeta value
    while (value < end){
        printf("Valor: %d\n", value);
        pwm_set_gpio_level(PWM_GPIO, (value * 65535) / 20000);
        value += time;

        sleep_ms(10);
    }

    value = end;
    sleep_ms(10);

    // Enquanto value for maior que start, decrementa value
    while (value > start){
        printf("Valor: %d\n", value);
        pwm_set_gpio_level(PWM_GPIO, (value * 65535) / 20000);
        value -= time;

        sleep_ms(10);
    }
}

int main() {
    stdio_init_all();

    // Seta a função de PWM e pega o respectivo slice do pino
    gpio_set_function(PWM_GPIO, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_GPIO);

    // Configuração para 50 Hz (20 ms)
    pwm_set_clkdiv(slice, 38.0f);   // Divisor de clock para ajustar a frequência
    pwm_set_wrap(slice, 65535);      // Valor máximo para wrap

    // Habilita o pwm no slice
    pwm_set_enabled(slice, true);

    // Tempo até as movimentações começarem
    sleep_ms(1000);

    // Posição de 180 graus (2.400 µs)
    pwm_set_gpio_level(PWM_GPIO, (2400 * 65535) / 20000);
    printf("Flange do servomotor na posição: 180 graus\n");
    sleep_ms(5000);

    // Posição de 90 graus (1.470 µs)
    pwm_set_gpio_level(PWM_GPIO, (1470 * 65535) / 20000);
    printf("Flange do servomotor na posição: 90 graus\n");
    sleep_ms(5000);

    // Posição de 0 graus (500 µs)
    pwm_set_gpio_level(PWM_GPIO, (500 * 65535) / 20000);
    printf("Flange do servomotor na posição: 0 graus\n");
    sleep_ms(5000);

    // Movimentação dos 180 aos 0 graus e vice-versa
    while (true) {
        move(500, 2400, 5);
        sleep_ms(10);
    }

}
