int byteSwap(int target, int m, int n);
int byteSwap_standard(int target, int m, int n);


int byteSwap(int target, int m, int n){
    int m3 = m << 3;
    int n3 = n << 3;
    int mMask = 0xff << m3;
    int nMask = 0xff << n3;

    int mByte = (mMask & target) >> m3;
    int nByte = (nMask & target) >> n3;

    target = (target & ~mMask) & ~nMask;

    return target | mByte << m3 | nByte << n3;
}

int byteSwap_standard(int target, int m, int n){
    unsigned int mMask, nMask;

    switch(m){
        case 0:
            mMask = target & 0xFF;
            target &= 0xFFFFFF00;
            break;
        case 1:
            mMask = (target & 0xFF00) >> 8;
            target &= 0xFFFF00FF;
            break;
        case 2:
            mMask = (target & 0xFF0000) >> 16;
            target &= 0xFF00FFFF;
            break;
        case 3:
            mMask = ((unsigned int)(target & 0xFF000000)) >> 24;
            target &= 0x00FFFFFF;
            break;
    }

    switch(n){
        case 0:
            nMask = target & 0xFF;
            target &= 0xFFFFFF00;
            break;
        case 1:
            nMask = (target & 0xFF00) >> 8;
            target &= 0xFFFF00FF;
            break;
        case 2:
            nMask = (target & 0xFF0000) >> 16;
            target &= 0xFF00FFFF;
            break;
        case 3:
            nMask = ((unsigned int)(target & 0xFF000000)) >> 24;
            target &= 0x00FFFFFF;
            break;
    }

    mMask <<= 8 * m;
    nMask <<= 8 * n;
    return target | mMask | nMask;
}
