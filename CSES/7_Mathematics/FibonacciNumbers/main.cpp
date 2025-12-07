/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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
const int LG = 60;
const long long LLINF = 1e18+3;

//Starts here

int n;

struct Matrix{
    array<array<ll,2>,2> a;

    Matrix(){
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                a[i][j] = 0;
            }
        }
    }

    Matrix operator *(Matrix other){
        Matrix res;
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                for (int k=0; k<2; k++){
                    res.a[i][j] = (res.a[i][j] + a[i][k]*other.a[k][j])%MD;
                }
            }
        }
        return res;
    }
};

Matrix bin_pow(Matrix a, int b){
    Matrix res;
    for (int i=0; i<2; i++){
        res.a[i][i] = 1;
    }
    for (int lg=LG-1; lg>=0; lg--){
        res = res*res;
        if ((1LL<<lg)&b) res = res*a;
//        cout << lg << endl;
//        for (int i=0; i<2; i++){
//            for (int j=0; j<2; j++){
//                cout << res.a[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
    return res;
}

void solve(){
    int x; cin >> x;
    Matrix trans;
    trans.a[0][0] = 1;
    trans.a[0][1] = 1;
    trans.a[1][0] = 1;
    trans.a[1][1] = 0;
    trans = bin_pow(trans,x);
    int ans = 1*trans.a[0][1]%MD;
//    for (int i=0; i<2; i++){
//        for (int j=0; j<2; j++){
//            cout << trans.a[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << ans << endl;
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
