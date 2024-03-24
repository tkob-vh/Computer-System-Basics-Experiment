int bitOr(int x, int y){
    return ~(~x & ~y);
}

int bitOr_standard(int x, int y){
    return x | y;
}
