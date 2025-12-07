/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ex"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LIM = 31623;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,t;
vector<int> prime;
vector<int> v;

//Sieve

void Sieve(){
    bitset<LIM+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=LIM; i++){
        if (bs[i]){
            for (int j=i*i; j<=LIM; j+=i){
                bs[j] = 0;
            }
        }
    }
    for (int i=1; i<=LIM; i++){
        if (bs[i]) prime.push_back(i);
    }
}

/*Solution*/
void solve(){
    Sieve();
    cin >> t;
    int x;

    while (t--){
        cin >> x;
        int tmp = x;
        int rawr = 0;
        int gcd = 0;
        for (auto p:prime){
            int cnt = 0;
            while (tmp%p==0){
                tmp/=p;
                ++cnt;
            }
            if (cnt){
                if (gcd == 0){
                    gcd = cnt;
                    rawr = p;
                }
                else{
                    int new_gcd = __gcd(gcd,cnt);
                    int ttmp = 1;
                    for (int i=1; i<=(gcd/new_gcd); i++){
                        ttmp*=rawr;
                    }
                    rawr = ttmp;
                    ttmp = 1;
                    for (int i=1; i<=(cnt/new_gcd); i++){
                        rawr*=p;
                    }
                    gcd = new_gcd;
                }
            }
//            if (p<=10) cout << p << " " << tmp << " " << rawr << " " << gcd << " " << cnt << endl;
        }
        if (tmp!=1){
            int new_gcd = __gcd(gcd,(int)1);
            int ttmp = 1;
            for (int i=1; i<=(gcd/new_gcd); i++){
                ttmp*=rawr;
            }
            rawr = ttmp;
            ttmp = 1;
            for (int i=1; i<=(1/new_gcd); i++){
                rawr*=tmp;
            }
            gcd = new_gcd;
        }
        int val = 1;
        for (int i=1; i<=gcd; i++){
            val*=rawr;
        }
        val*=rawr;
        for (int i=gcd; i>0; i--){
            val/=rawr;
            if (gcd%i==0 && (gcd/i)%2==0){
                cout << -val << " " << gcd/i << endl;
            }
        }
        val = 1;
        for (int i=1; i<=gcd; i++){
            val*=rawr;
            if (gcd%i==0){
                cout << val << " " << gcd/i << "\n";
            }
        }
//        cout << rawr << " " << gcd << endl;
        if (t!=0) cout << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
