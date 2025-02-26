struct repeating_timer timer;

void LED_iniciacao(uint LED){
    //Inciailizando e configurando os pinos dos LEDs
    gpio_init(LED);;//Inicializa o pino do LED
    gpio_set_dir(LED, GPIO_OUT);// Configura o pino como saída
    gpio_put(LED, false); //Coloca em nível baixo
}
void Botao_iniciacao(uint botao){
    //Inciailizando e configurando os pinos dos botões 
    gpio_init(botao);//Inicializa o pino do botão 
    gpio_set_dir(botao, GPIO_IN);// Configura o pino como entrada
    gpio_pull_up(botao);// Habilita o pull-up interno
}

void setup(){
    stdio_init_all();
    adc_init();
    adc_gpio_init(VRX_PIN); 
    adc_gpio_init(VRY_PIN); 
 
    LED_iniciacao(LED_VERDE);
    LED_iniciacao(LED_AZUL);
    LED_iniciacao(LED_VERMELHO);
    
    Botao_iniciacao(botão_A);
    Botao_iniciacao(botão_B);
    Botao_iniciacao(botão_JOY);


    //Configurando PIO
    
    uint offset = pio_add_program(pio, &pio_matrix_program);
    sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, MATRIZ_LED);
  
    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
    gpio_pull_up(I2C_SDA); // Pull up the data line
    gpio_pull_up(I2C_SCL); // Pull up the clock line
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
    ssd1306_config(&ssd); // Configura o display
    ssd1306_send_data(&ssd); // Envia os dados para o display

    //Habilitando interrupção para os botões
    gpio_set_irq_enabled_with_callback(botão_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled(botão_JOY, GPIO_IRQ_EDGE_FALL,true);
    gpio_set_irq_enabled(botão_B, GPIO_IRQ_EDGE_FALL,true);

    //Habilitando temporizador periódico
    
    add_repeating_timer_ms(60000, repeating_timer_callback, NULL, &timer);
}