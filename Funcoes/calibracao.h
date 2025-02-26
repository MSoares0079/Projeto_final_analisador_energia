void calibracao(){
    if((vrx-2047)>dead_angle) {
        r = 7.5+7.5*(vrx-2047)/2047.0;
    }else if((2047-vrx)>dead_angle){
        r = 7.5-6.5*(2047-vrx)/2047.0;
    }else{
        r=7.5;
    }
    if ((vry-2047)>dead_angle) {
        x = 0 + 5*(vry-2047)/2047.0;
    }else if((2047-vry)>dead_angle) {
        x = 0 - 5*(2047-vry)/2047.0;
    }else{
        x = 0;
    }
    z = sqrt(r*r+x*x);
    fp = r/z;
}