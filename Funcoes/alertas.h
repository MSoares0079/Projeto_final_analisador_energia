void setup_pwm(uint gpio, float duty_cycle) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);// Configura GPIO para PWM
    uint slice = pwm_gpio_to_slice_num(gpio);// Obtém o slice associado ao pino GPIO
    pwm_set_clkdiv(slice, 28.0f);// Configura divisor de clock para 250 (clock base de 500kHz    
    pwm_set_wrap(slice, 1000);// Define o contador máximo (wrap) para 10.000    
    pwm_set_gpio_level(gpio, (uint16_t)(1000 * (duty_cycle / 100.0)));// Define o nível do duty cycle (0,12% de 10.000 -> 12)
    pwm_set_enabled(slice, true);// Ativa o PWM
}
double matriz[25] = 
    { 
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0
    };

void alerta_vermelho(){
    gpio_put(LED_VERMELHO,1);
    gpio_put(LED_VERDE,0);
    gpio_put(LED_AZUL,0);
    setup_pwm(BUZZER_1, estado_buzzer*100);
    desenho_pio(matriz, valor_led, pio, sm, estado_LED*intensidade_luminosa * 1.0,//A cor do número é definido por outro contador (lista_de_cores[cor])
                                                estado_LED*intensidade_luminosa * 0.0 ,//As cores estão na ordem RGB
                                                estado_LED*intensidade_luminosa * 0.0);//Além disso existe a váriavel intensidade que define o brilho
}
void alerta_amarelo(){
    gpio_put(LED_VERMELHO,1);
    gpio_put(LED_VERDE,1);
    gpio_put(LED_AZUL,0);
    setup_pwm(BUZZER_1, estado_buzzer*50);
    desenho_pio(matriz, valor_led, pio, sm, estado_LED*intensidade_luminosa * 1.0,//A cor do número é definido por outro contador (lista_de_cores[cor])
                                                estado_LED*intensidade_luminosa * 1.0 ,//As cores estão na ordem RGB
                                                estado_LED*intensidade_luminosa * 0.0);//Além disso existe a váriavel intensidade que define o brilho
}
void situacao_nominal(){
    gpio_put(LED_VERMELHO,0);
    gpio_put(LED_VERDE,1);
    gpio_put(LED_AZUL,0);
    setup_pwm(BUZZER_1, 0);
    desenho_pio(matriz, valor_led, pio, sm, estado_LED*intensidade_luminosa * 0.0,//A cor do número é definido por outro contador (lista_de_cores[cor])
                                                estado_LED*intensidade_luminosa * 1.0 ,//As cores estão na ordem RGB
                                                estado_LED*intensidade_luminosa * 0.0);//Além disso existe a váriavel intensidade que define o brilho
}
