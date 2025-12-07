#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;
const int mod = 1e9+7;

int n;

int prefix(int i, int j){
    int t = 0;
    if (j%2 == 0){
        int n = j;
        t = (t+(((n/2)%mod)*((n+1)%mod)-1)%mod)%mod;
    }
    else{
        int n = j;
        t = (t+((n%mod)*(((n+1)/2)%mod)-1)%mod)%mod;
    }
    if (i%2 == 0){
        int n = i;
        t = t-(((n/2)%mod)*((n+1)%mod)-1)%mod;
    }
    else{
        int n = i;
        t = t-((n%mod)*(((n+1)/2)%mod)-1)%mod;
    }
    if (t < 0) t+=mod;
    return t;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int t = 0;
    if (n == 1) cout << 1;
    else {
        t = (t+n)%mod;
        t = (t+prefix(1,n))%mod;
        for (int i=2; i*i<=n; i++){
            t = (t+i)%mod;
            int j = n/i;
            t = (t+(i*(j-i)%mod))%mod;
            t = (t+prefix(i,j))%mod;
        }
        cout << t;
    }
    return 0;
}
