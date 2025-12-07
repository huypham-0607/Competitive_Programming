int bin_pow(int a, int b){
    int res = 1;
    for (int lg = LG-1; lg>=0; lg--){
        res = res*res%MD;
        if ((1<<lg)&b) res = res*a%MD;
    }
    return res;
}
