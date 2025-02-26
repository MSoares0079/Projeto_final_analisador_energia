#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <math.h>                 
#include "pico/stdlib.h"       
#include "hardware/adc.h"      
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "Funcoes/ssd1306.c"

#define VRX_PIN 26   
#define VRY_PIN 27     
#define LED_VERDE 11  
#define LED_AZUL 12  
#define LED_VERMELHO 13  
#define botão_A 5
#define botão_B 6
#define botão_JOY 22
#define BUZZER_1 21
#define MATRIZ_LED 7
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C
#define dead_angle 100
#define intensidade_luminosa 0.05

ssd1306_t ssd;
bool cor = true;
static volatile uint32_t last_time = 0,temporizador=0;
static volatile bool estado_LED = true,estado_buzzer=true, selecao_modo = true,selecao_log = false,flag_contigencia=true;
static uint16_t valor_led,sm,vrx,vry,sobre_tensao=0,sub_tensao=0,sobre_corrente=0;
static float v,i,r=7.5,x=0.0,z=7.5,fp=1.0;
static char buffer1[50], buffer2[50], buffer3[50],buffer4[50],buffer5[50];

static PIO pio = pio0;


#include "Funcoes/LED.pio.h"
#include "Funcoes/mudar_LED.c"
#include "Funcoes/desenhar_tela.h"
#include "Funcoes/interrupcoes.h"
#include "Funcoes/setup.h"
#include "Funcoes/alertas.h"
#include "Funcoes/medicao.h"
#include "Funcoes/calibracao.h"
#include "Funcoes/contigencias.h"




#endif // INCLUDES_H