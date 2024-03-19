int negate(int x);
int negate_standard(int x);

int negate(int x){
    return ~x + 1;
}

int negate_standard(int x){
    return -x;
}
