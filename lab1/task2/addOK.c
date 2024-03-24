int addOK(int x, int y){
    int sum = x + y;

    int xMask = x >> 31;
    int yMask = y >> 31;
    int sumMask = sum >> 31;

    return !(~(xMask ^ yMask) & (xMask ^ sumMask));
}


int addOK_standard(int x, int y){
    long lsum = (long) x + y;
    return lsum == (int) lsum;
}
