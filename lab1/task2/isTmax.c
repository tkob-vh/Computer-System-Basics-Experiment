int isTmax(int x){
    int minusX = ~x + 1;
    int xp2 = x + 2;
    return !(xp2 ^ minusX);
}

int isTmax_standard(int x){
    return x == 0x7FFFFFFF;
}
