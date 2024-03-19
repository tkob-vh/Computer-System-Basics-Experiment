int bitXor(int x, int y);
int bitXor_standard(int x, int y);

int bitXor(int x, int y){
    return ~(~x & ~y) & ~(x & y);
}

int bitXor_standard(int x, int y){
    return x ^ y;
}
