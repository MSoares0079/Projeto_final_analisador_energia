void detecta_contigencia(){
    if(v>220*1.05){
        alerta_vermelho();
        sprintf(buffer5,"Sobretensao");
        if(flag_contigencia){
            sobre_tensao++;
            flag_contigencia = false;
        }
    }else if(v<220*0.95){
        alerta_amarelo();
        sprintf(buffer5,"Subtensao");
        if(flag_contigencia){
            sub_tensao++;
            flag_contigencia = false;
        }
    }else if(i>220/z*1.15){
        alerta_amarelo();
        sprintf(buffer5,"Sobrecorrente");
        if(flag_contigencia){
            sobre_corrente++;
            flag_contigencia = false;
        }
    }else{
        situacao_nominal();
        sprintf(buffer5,"Nominal");
        flag_contigencia = true;
    }
}