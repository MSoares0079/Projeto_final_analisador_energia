void desenha_medicao(){
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 0, 0, 128, 64, cor, !cor);
    ssd1306_draw_string(&ssd, "Modo medicao", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "Tensao ", 10, 35); // Desenha uma string
    ssd1306_draw_string(&ssd, "Corrente  ", 10, 45); // Desenha uma string
    ssd1306_draw_string(&ssd, "Fp  ", 10, 55); // Desenha uma string
    sprintf(buffer1,"%.2f",v);
    sprintf(buffer2,"%.2f",i);
    sprintf(buffer3,"%.2f",fp);
    ssd1306_draw_string(&ssd, buffer1, 75, 35); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer2, 83, 45); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer3, 91, 55); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer5, 20, 20); // Desenha uma string   
    ssd1306_send_data(&ssd);
}
void desenha_calibracao(){
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 0, 0, 128, 64, cor, !cor);
    ssd1306_draw_string(&ssd, "Modo calibracao", 4, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "R ", 10, 35); // Desenha uma string
    ssd1306_draw_string(&ssd, "X  ", 10, 45); // Desenha uma string
    ssd1306_draw_string(&ssd, "Z  ", 10, 55); // Desenha uma string
    sprintf(buffer1,"%.2f",r);
    sprintf(buffer2,"%.2f",x);
    sprintf(buffer3,"%.2f",z);
    ssd1306_draw_string(&ssd, buffer1, 80, 35); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer2, 80, 45); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer3, 80, 55); // Desenha uma string
    ssd1306_send_data(&ssd);

}
void desenha_log(){
    ssd1306_fill(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 0, 0, 128, 64, cor, !cor);
    ssd1306_draw_string(&ssd, "Log de eventos", 8, 10); // Desenha uma string
    ssd1306_draw_string(&ssd, "SobTensao ", 5, 35); // Desenha uma string
    ssd1306_draw_string(&ssd, "SubTesao ", 5, 45); // Desenha uma string
    ssd1306_draw_string(&ssd, "SobCorrente ", 5, 55); // Desenha uma string
    uint tempo = 60-( to_us_since_boot(get_absolute_time()) - temporizador)/1000000;
    sprintf(buffer1,"%d s",tempo);
    sprintf(buffer2,"%d",sobre_tensao);
    sprintf(buffer3,"%d",sub_tensao);
    sprintf(buffer4,"%d",sobre_corrente);
    ssd1306_draw_string(&ssd, buffer1, 50, 20); // Desenha uma string    
    ssd1306_draw_string(&ssd, buffer2, 110, 35); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer3, 110, 45); // Desenha uma string
    ssd1306_draw_string(&ssd, buffer4, 110, 55); // Desenha uma string
    ssd1306_send_data(&ssd);
}

void desenha_tela(){
    if(selecao_log){
        desenha_log();
    }else{
        if(selecao_modo){
            desenha_medicao();
        }else{
            desenha_calibracao();
        }
    }
    
}