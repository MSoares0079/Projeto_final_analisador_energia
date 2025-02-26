void medicao(){
    if((vrx-2047)>dead_angle) {
        i = 220/z *(1+ 0.2*(vrx-2047)/2047.0);
    }else if((2047-vrx)>dead_angle){
        i = 220/z *(1- 0.2*(2047-vrx)/2047.0);    
    }else{
        i = 220/z;
    }
    if ((vry-2047)>dead_angle) {
        v = 220+22*(vry-2047)/2047.0;
    }else if((2047-vry)>dead_angle) {
        v = 220-22*(2047-vry)/2047.0;
    }else{
        v=220; 
    }
}