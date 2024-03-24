int bitMask(int lowbit, int highbit){
    int all1 = ~0;
    int mask = all1 + (2 << highbit);
    return (mask >> lowbit) << lowbit;
}

int bitMask_standard(int lowbit, int highbit){
    int mask = 0;
    for(int i = lowbit; i <= highbit; i++){
        mask |= 1 << i;
    }
    return mask;
}
