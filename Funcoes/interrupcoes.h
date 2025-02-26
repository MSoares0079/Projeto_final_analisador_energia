void gpio_irq_handler(uint gpio, uint32_t events){
    uint32_t current_time = to_us_since_boot(get_absolute_time());// Obtém o tempo atual em microssegundos;
    if (current_time - last_time > 200000){ // Verifica se passou tempo suficiente desde o último evento com 200 ms de debouncing 
        last_time = current_time; // Atualiza o tempo do último evento
        if(gpio == botão_A){
            estado_LED = !estado_LED;
        }
        else if(gpio == botão_B){
            estado_buzzer = !estado_buzzer;
        }
        else if(gpio == botão_JOY){
            selecao_modo = !selecao_modo;
            selecao_log = false;
            uint32_t press_start_time = to_us_since_boot(get_absolute_time());
            if(current_time - press_start_time > 1000000){
                selecao_log = true;
            }
        }
    }
}
bool repeating_timer_callback(struct repeating_timer *t) {
    sobre_tensao = 0;
    sub_tensao = 0;
    sobre_corrente = 0;
    temporizador = to_us_since_boot(get_absolute_time());
}