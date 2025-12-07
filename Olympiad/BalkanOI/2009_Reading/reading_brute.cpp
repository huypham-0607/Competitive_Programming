#pragma GCC optimization "O2"
#pragma GCC optimization "unroll-loop"
#pragma GCC target ("avx2")

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
using namespace std;
const ll N = 1e5 + 9;
const ll Log2 = 20;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> LL;

ll n,m,w,x,y,fake = 26;
ll sz = 140;
struct Matrix{
    ll a[150][150];
    Matrix (){
        memset(a,0,sizeof(a));
    }
};
Matrix root;

Matrix operator * (Matrix A,Matrix B){
    Matrix C;
    for (ll i = 0;i < sz;i++){
        for (ll j = 0;j < sz;j++){
            ll now = 0;
            for (ll l = 0;l < sz;l++) now += (A.a[i][l]*B.a[l][j])%mod,now %= mod;
            C.a[i][j] = now;
        }
    }
    return C;
}

Matrix bpow(Matrix A,ll b){
    Matrix res;
    for (ll i = 0;i < sz;i++) res.a[i][i] = 1;
    while(b){
        if (b & 1) res = res*A;
        A = A*A; b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    #define task "reading"
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".ans", "w", stdout);
    }
    cin>>n>>m;
    /// sol : creat some fake node to deal with path > 1
    /// creat some source node that have edge to every another node (in this code soure = 0)
    for (ll i = 0;i <= 26;i++){
        for (ll j = 1;j <= 26;j++) root.a[i*5][j*5] = 1;
        for (ll j = 1;j < 5;j++) root.a[i*5 + j][i*5 + j - 1] = 1;
    }
    root.a[0][0] = 1;
    while(m--){
        char a,b;
        cin>>a>>b>>w; w--;
        x = a - 'a' + 1; y = b - 'a' + 1;
        x *= 5; y *= 5; root.a[x][y] = root.a[y][x] = 0;
        root.a[x][y + w] = root.a[y][x + w] = 1;
    }

    root = bpow(root,n + 1);
    ll ans = 0;
    for (ll i = 1;i <= 26;i++) ans = (ans + root.a[0][i*5])%mod;
    cout<<ans;
}
