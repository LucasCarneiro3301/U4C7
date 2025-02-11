/*
    Aluno: Lucas Carneiro de Araújo Lima
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Pinagem dos componentes
#define SERVO 22 
#define BLUE 12  

// Parâmetros do PWM 
/*
    fpwm = fckl / (di * (wrap + 1))
    di = 125, 50Hz = 125Mhz/(125*(wrap + 1))
    50Hz = 1Mhz/(wrap + 1)
    50Hz*wrap + 50hz = 1Mhz
    wrap = (1Mhz - 50Hz)/50Hz
    wrap = 19999
*/
#define DI 125      // DIVISOR INTEIRO
#define WRAP 19999  // WRAP 

// Posições do servomotor
uint16_t pos_180 = 2400; // APROX 12% de WRAP
uint16_t pos_90 = 1470; // APROX 7.35% de WRAP
uint16_t pos_0 = 500; // APROX 2.5% de WRAP

// Variação do duty cycle (5us)
#define STEP 5 // APROX 0.025% (5us/20ms) de WRAP 

void pwm_setup(); // Prototipação da função que inicializa e configura os pinos 22 e 12 como PWM
void set_pwm_level(uint16_t level); // Prototipação da função que define o nível do PWM para os pinos 22 e 12

int main() {
    uint16_t level = pos_0;
    bool isIncreasing = true;

    stdio_init_all();
    pwm_setup();

    // Servomotor para a posição 180°
    set_pwm_level(pos_180);
    sleep_ms(5e3);

    // Servomotor para a posição 90°
    set_pwm_level(pos_90);
    sleep_ms(5e3);

    // Servomotor para a posição 0°
    set_pwm_level(pos_0);
    sleep_ms(5e3);

    while(true) {
        level = (isIncreasing) ? level + STEP : level - STEP; // Se está crescendo, soma mais o passo, caso contrário, é diminuído pelo passo

        set_pwm_level(level); // Servomotor para a posição atual

        isIncreasing = ((level + STEP) > pos_180) ? false : ((level - STEP) < pos_0) ? true : isIncreasing; // Se a próxima soma ou subtração pelo passo ultrapassar os limites, altera a operação atual

        sleep_ms(10);
    }
}

// Define o nível do PWM para os pinos 22 e 12
void set_pwm_level(uint16_t level) {
    pwm_set_gpio_level(SERVO, level);
    pwm_set_gpio_level(BLUE, level);
}

// Inicializa e configura os pinos 22 e 12 como PWM
void pwm_setup() {
    gpio_set_function(SERVO, GPIO_FUNC_PWM); // Define o pino como PWM
    gpio_set_function(BLUE, GPIO_FUNC_PWM); // Define o pino como PWM

    uint slice_servo = pwm_gpio_to_slice_num(SERVO); // Obtém o slice
    uint slice_led = pwm_gpio_to_slice_num(BLUE); // Obtém o slice

    pwm_set_clkdiv(slice_servo, DI); // Define o divisor inteiro de clock
    pwm_set_wrap(slice_servo, WRAP); // Define o wrap
    pwm_set_enabled(slice_servo, true);

    pwm_set_clkdiv(slice_led, DI); // Define o divisor inteiro de clock
    pwm_set_wrap(slice_led, WRAP); // Define o wrap
    pwm_set_enabled(slice_led, true); 
}