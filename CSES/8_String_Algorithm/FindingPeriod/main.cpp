/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}
//RNG
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*Global Variables*/
int n;
string s;

//Hash
int hsh[(int)1e6+10];


void gen(){
    int p = 331;
    int mod = INF;
    hsh[0] = 0;
//    cout << n << endl;
    for (int i=1; i<=n; i++){
//        cout << "meow" << endl;
        hsh[i] = ((hsh[i-1]*p)%mod + (s[i-1]-'a'+1))%mod;
//        cout << (hsh[i-1]*p) + (s[i-1]-'a'+1) << endl;
    }
}

int bin_exp(int x){
    int p = 331;
    int mod = INF;
    int res = 1;
    while (x>0){
        if (x&1) res = (res*p)%mod;
        p = (p*p)%mod;
        x = (x>>1);
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> s;
    n = (int)s.size();
    s = s;
//    cout << n << endl;
    gen();
    for (int i=1; i<=n; i++){
//        cout << hsh[i] << endl;
        int mod = INF;
        int j=i;
        int exp = bin_exp(i);
//        cout << exp << " " << i << endl;
        int tmp = hsh[i];
        while (j+i<=n){
            j+=i;
            tmp = ((tmp*exp)%mod + hsh[i])%mod;
//            cout << tmp << " " << hsh[j] << " " << j << endl;
        }
//        cout << n << " " << j << endl;
        int rawr = hsh[n]-(hsh[j]*bin_exp(n-j))%mod;
//        cout << rawr << endl;
        if (rawr<0) rawr+=mod;
        int woof = hsh[n-j];
        if (tmp==hsh[j] && rawr==woof) cout << i << endl;
//        cout << rawr << " " << woof << endl;
    }
}


/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);



    return 0;
}
