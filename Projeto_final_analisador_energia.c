#include "includes.h"


//Prototipagem das funções
void gpio_irq_handler(uint gpio, uint32_t events);
void setup_pwm(uint gpio, float duty_cycle);
void setup(),desenha_tela(),desenha_log(),medicao(),calibracao(),detecta_contigencia(),alerta_vermelho(),alerta_amarelo(),situacao_nominal();
bool repeating_timer_callback(struct repeating_timer *t);
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);


int main() {
    setup();//Realiza todas as configurações dos LEDs,botões,joystick,temporizador,interrupções e etc 
    while (true) {
        adc_select_input(1); 
        vrx = adc_read(); 
        adc_select_input(0); 
        vry = adc_read();

        if(selecao_modo||selecao_log){
            medicao();//Mede os valores de V e I
            detecta_contigencia(); 
        }else{
            calibracao();//Altera os valores nominais de R, X e Z          
        }
        desenha_tela();
        //printf("MODO: %d, LOG: %d", selecao_modo,selecao_log);     
        //printf("VRX: %u, VRY: %u,\n", vrx, vry);
        sleep_ms(100);
  }
  return 0;
}








