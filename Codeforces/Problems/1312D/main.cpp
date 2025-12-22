/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const int LG = 30;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
int fac[N];

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = res*res%MD;
        if ((1<<lg)&b) res = res*a%MD;
    }
    return res;
}

int inv_mod(int x){
    return bin_pow(x,MD-2);
}

int nCk (int n, int k){
    return fac[n]*inv_mod(fac[k]*fac[n-k]%MD)%MD;
}

/*Solution*/
void solve(){
    cin >> n >> m;
    fac[0] = 1;
    for (int i=1; i<=n; i++){

    }


}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
