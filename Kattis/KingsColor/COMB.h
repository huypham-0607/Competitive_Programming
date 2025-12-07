namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 2e5;
    const int LG = 30;

    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invMod(fac[k])%MD*invMod(fac[n-k])%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (int)(1LL*fac[i-1]*i%MD);
            }
        }
    } _init;
}
