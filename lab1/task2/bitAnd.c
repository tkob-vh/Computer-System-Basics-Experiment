int bitAnd(int x, int y){
    return ~(~x | ~y);
}


int bitAnd_standard(int x, int y){
    return x & y;
}
