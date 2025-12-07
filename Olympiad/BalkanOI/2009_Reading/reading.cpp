/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "reading"

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

const int N = 26;
const int M = 6;
const int INF = 1e9+7;
const int LG = 30;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;

struct Matrix{
    int n,m;
    vector<vector<int>> val;

    Matrix(int n=0, int m=0){
        this->n = n;
        this->m = m;
        val.resize(n,vector<int>(m,0));
    }

    Matrix operator * (Matrix other){
        if (m!=other.n) return Matrix();
        Matrix res(n,other.m);
        for (int i=0; i<n; i++){
            for (int j=0; j<other.m; j++){
                for (int k=0; k<m; k++){
                    res.val[i][j] = (res.val[i][j] + (val[i][k]*other.val[k][j])%MD)%MD;
                }
            }
        }
        return res;
    }
};

Matrix matrixExp(Matrix a, int b){
    Matrix res(a.n,a.m);
    for (int i=0; i<a.n; i++){
        res.val[i][i] = 1;
    }

    for (int lg=LG-1; lg>=0; lg--){
        res = res*res;
        if ((1LL<<lg)&b) res = res*a;
    }
    return res;
}

vector<vector<int>> diff(N,vector<int>(N,1));

void solve(){
    cin >> n >> m;
    Matrix mat(N*M,N*M);
    for (int i=0; i<N; i++){
        for (int j=1; j<M-1; j++){
            mat.val[i*M+j-1][i*M+j] += 1;
        }
        mat.val[i*M][i*M+5] += 1;
        mat.val[i*M+5][i*M+5] += 1;
    }

//    for (int i=0; i<N; i++){
//        mat.val[i*M][i*M] += 1;
//    }
    for (int idx=1; idx<=m; idx++){
        char u,v; int w;
        cin >> u >> v >> w;
        int i1 = u-'a';
        int i2 = v-'a';
//        cout << i1 << " " << i2 << endl;
        diff[i1][i2] = w;
        diff[i2][i1] = w;

    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int w = diff[i][j];
            mat.val[i*M+w-1][j*M] += 1;
//            mat.val[j*M+w-1][i*M] += 1;
        }
    }

    mat = matrixExp(mat,n+1);

    Matrix start(N*M,N*M);
    for (int i=0; i<N; i++){
        start.val[i*M][i*M] = 1;
    }

//    for (int i=0; i<N*M; i++){
//        for (int j=0; j<N*M; j++){
//            cout << mat.val[i][j] << " ";
//        }
//        cout << endl;
//    }
    mat = start*mat;

//    for (int i=0; i<N; i++){
//        for (int j=0; j<N*5; j++){
//            cout << M.val[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            int tmp = 0;
            for (int idx=0; idx<N*M; idx++){
                tmp = (tmp+mat.val[idx][i*M+j])%MD;
            }
//            cout << tmp << " ";
        }
//        cout << endl;
    }

    long long ans = 0;
    for (int i=0; i<N; i++){
        for (int idx=0; idx<N*M; idx++){
//            ans = (ans+mat.val[idx][i*M])%MD;
            ans = (ans+mat.val[idx][i*M+5])%MD;
        }
    }
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

