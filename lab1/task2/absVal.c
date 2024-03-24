int absVal(int x){
    int mask = x >> 31; //the sign bit of x
    return (x ^ mask) + ~mask + 1;
}

int absVal_standard(int x){
    return (x > 0) ? x: -x;
}
