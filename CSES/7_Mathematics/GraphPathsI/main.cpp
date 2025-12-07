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
const int LG = 30;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,k;

struct Matrix{
    int n,m;
    vector<vector<int>> val;

    Matrix(int _n=0, int _m=0){
        n = _n;
        m = _m;
        val.resize(n,vector<int>(m,0));
    }

    friend Matrix mul (Matrix a, Matrix b){
        if (a.m!=b.n) return Matrix();
        Matrix res(a.n,b.m);
        for (int i=0; i<a.n; i++){
            for (int j=0; j<b.m; j++){
                for (int k=0; k<a.m; k++){
                    res.val[i][j] = (res.val[i][j] + a.val[i][k]*b.val[k][j]%MD)%MD;
                }
            }
        }
        return res;
    }
};

Matrix matrixExp(Matrix a, int b){
    Matrix res(a.n,a.n);
    for (int i=0; i<a.n; i++){
        res.val[i][i] = 1;
    }
    for (int lg=LG-1; lg>=0; lg--){
        res = mul(res,res);
        if ((1LL<<lg)&b) res = mul(res,a);
    }
    return res;
}

void solve(){
    cin >> n >> m >> k;
    Matrix M(n,n);
    while (m--){
        int u,v; cin >> u >> v;
        --u; --v;
        M.val[u][v] += 1;
    }
    M = matrixExp(M,k);
    cout << M.val[0][n-1];
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
