/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here
const int M = 10004205361450474;

int calc_cap(int k, int q){
    k = min(k,(ll)10000);
    int res = 0;
    for (int i=1; i<=q; i++){
        int x = 1;
        for (int j=1; j<=i; j++){
            if (j == 1) x*=k;
            else x*=(k+1);
        }
        res += x;
    }
    return res;
}

int ask(int k, vector<int>&v) {
    cout << k << endl;
    for (auto x:v) {
        cout << x << " ";
    }
    cout << endl;
    cout.flush();
    int val; cin >> val; return val;
}

vector<int> v;

int dpm[10];

int recur(int l, int q, bool org) {
    if (q==1) {
        if (org) {
            for (int i=l; i<l+min((ll)10000,l); i++){
                v.push_back(i);
            }
        }
        return l+min((ll)10000,l)-1;
    }
    if (!org && l>=10000) {
        return l+dpm[q]-1;
    }
    int pos = l;
    for (int i=0; i<=min((ll)10000,l); i++){
        if (i!=0) ++pos;
        pos = recur(pos,q-1, false);
        if (i!=min((ll)10000,l)) {
            ++pos;
            if (org) v.push_back(pos);
        }
    }
    return pos;
}

void solve(){
    for (int i=1; i<5; i++){
        dpm[i] = calc_cap(10000,i);
        // cout << dpm[i] << " ";
    }

    int l = 1;
    for (int q=5; q>=1; q--){
        v.clear();
        recur(l,q,true);
        int res = ask(v.size(),v);
        if (res < 0) return;
        if (res != 0) {
            l = v[res-1]+1;
        }
    }

    // cout << recur(920648437,2,false) << endl;
}
//920648436
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

