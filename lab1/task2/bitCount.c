int bitCount(int x);
int bitCount_standard(int x);

int bitCount(int x){
    int mask = 0x11111111;
    int s = x & mask;
    s += (x >> 1) & mask;
    s += (x >> 2) & mask;
    s += (x >> 3) & mask;

    s = s + (s >> 16);

    mask = 0x0F0F;
    s = (s + (s >> 4)) & mask;

    return (s + (s >> 8)) & 0x3F;
}
