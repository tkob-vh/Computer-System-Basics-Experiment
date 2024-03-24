int bitCount(int x){
    int mask = 0x11111111;
    int s = x & mask;
    s += (x >> 1) & mask;
    s += (x >> 2) & mask;
    s += (x >> 3) & mask;

    s = (s & 0xFFFF) + ((s >> 16) & 0xFFFF);

    mask = 0x0F0F;
    s = (s + (s >> 4)) & mask;

    return (s + (s >> 8)) & 0x3F;
}

int bitCount_standard(int x){
    int result = 0;
    for(int i = 0; i < 32; i++){
        result += (x >> i) & 0x1;
    }
    return result;
}
