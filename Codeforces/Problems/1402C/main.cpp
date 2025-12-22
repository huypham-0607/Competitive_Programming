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
const int LG = 60;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct Node{
    int state, cnt;
    vector<int> crit;
    int critF;

    Node() {
        state = 0;
        crit = {0,0};
        critF = 0;
        cnt = 0;
    }

    Node(int _cnt, int _critL, int _critW) {
        cnt = _cnt;
        crit = {_critL, _critW};
        state = (cnt ? 1 : 0);
        if (cnt > 1) {
            critF = 0;
        }
        else critF = crit[state];
    }

    friend Node Comb(Node u, Node v){
        u.cnt += ((!v.state)? 1 : 0);
        u.crit[v.state^1] += v.critF;
        u.state = (u.cnt ? 1 : 0);
        u.critF = (u.cnt > 1) ? 0 : u.crit[u.state];
        return u;
    }

    void db () {
        cout << state << " " << cnt << endl;
        cout << crit[0] << " " << crit[1] << " " << critF << endl;
    }
};

struct Matrix{
    vector<vector<int>> val;

    Matrix() {
        val = vector<vector<int>> (2,vector<int>(2,0));
    }

    Matrix operator *(Matrix a) {
        Matrix res = Matrix();
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                for (int k=0; k<2; k++){
                    res.val[i][j] = (res.val[i][j] + val[i][k]*a.val[k][j]%MD)%MD;
                }
            }
        }
        return res;
    }
};

Matrix matrixExp(Matrix a, int b) {
    Matrix res = Matrix();
    res.val[0][0] = 1;
    res.val[1][1] = 1;
    for (int lg = LG-1; lg>=0; lg--){
        res = res*res;
        if ((1LL<<lg)&b) res = res * a;
    }
    return res;
}

int n,d;
vector<int> adj[N];
//int critL[N],state[N];
Node f[N],g[N];

void dfs(int u, int p) {
    f[u] = Node(0,1,0);
    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u);
        f[u] = Comb(f[u],f[v]);
    }
}

void reroot(int u, int p) {
    int m = adj[u].size()+2;
    vector<vector<int>> cnt(2,vector<int>(m,0));
    vector<vector<int>> critL(2,vector<int>(m,0));
    vector<vector<int>> critW(2,vector<int>(m,0));
    int idx = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++idx;
        if (!(f[v].state)) cnt[0][idx] = cnt[1][idx] = 1;
        if (f[v].state) critL[0][idx] = critL[1][idx] = f[v].critF;
        else critW[0][idx] = critW[1][idx] = f[v].critF;
    }
    for (int i=1; i<=idx; i++){
        cnt[0][i] += cnt[0][i-1];
        critL[0][i] += critL[0][i-1];
        critW[0][i] += critW[0][i-1];
    }
    for (int i=idx; i > 0; i--){
        cnt[1][i] += cnt[1][i+1];
        critL[1][i] += critL[1][i+1];
        critW[1][i] += critW[1][i+1];
    }

    idx = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
//        cout << "v: " << v << endl;
        ++idx;

        int cL = critL[0][idx-1] + critL[1][idx+1] + ((g[u].state)? g[u].critF : 0);
        int cW = critW[0][idx-1] + critW[1][idx+1] + (!(g[u].state)? g[u].critF : 0);
        int cntv = cnt[0][idx-1] + cnt[1][idx+1] + (!(g[u].state)? 1 : 0);

        Node tmp(cntv,cL+1,cW);
        g[v] = tmp;
        reroot(v,u);
    }
}



void solve(){
    cin >> n >> d;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    g[1] = Node(1,0,0);
    dfs(1,0);
    reroot(1,0);
//    cout << endl;
    Matrix mat = Matrix();

    int wcnt = 0;
    int lcnt = 0;
    for (int i=1; i<=n; i++){
        Node tmp = Comb(f[i],g[i]);

        if (tmp.state){
            mat.val[0][1] = (mat.val[0][1] + n-tmp.critF)%MD;
            mat.val[1][1] = (mat.val[1][1] + n)%MD;
            mat.val[0][0] = (mat.val[0][0] + tmp.critF)%MD;
            ++wcnt;
        }
        else {
            mat.val[0][1] = (mat.val[0][1] + tmp.critF)%MD;
            mat.val[0][0] = (mat.val[0][0] + n-tmp.critF)%MD;
            mat.val[1][0] = (mat.val[1][0] + n)%MD;
            ++lcnt;
        }
    }

//    for (int i=1; i<=n; i++){
//        cout << f[i].state << " " << f[i].cnt << endl;
//        cout << f[i].crit[0] << " " << f[i].crit[1] << " " << f[i].critF << endl;
//    }
//    cout << endl;
//
//    for (int i=1; i<=n; i++){
//        cout << g[i].state << " " << g[i].cnt << endl;
//        cout << g[i].crit[0] << " " << g[i].crit[1] << " " << g[i].critF << endl;
//    }
//    cout << endl;
//
//    for (int i=1; i<=n; i++){
//        Node tmp = Comb(f[i],g[i]);
//        cout << tmp.state << " " << tmp.cnt << endl;
//        cout << tmp.crit[0] << " " << tmp.crit[1] << " " << tmp.critF << endl;
//    }
//    cout << endl;

//    for (int i=0; i<2; i++){
//        for (int j=0; j<2; j++){
//            cout << mat.val[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    mat = matrixExp(mat,d-1);
    Matrix imat = Matrix();

//    for (int i=0; i<2; i++){
//        for (int j=0; j<2; j++){
//            cout << mat.val[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    imat.val[0][0] = lcnt;
    imat.val[1][1] = wcnt;
    mat = imat*mat;

//    for (int i=0; i<2; i++){
//        for (int j=0; j<2; j++){
//            cout << mat.val[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    int ans = 0;

    if (f[1].state) {
        ans = (ans+(mat.val[0][1] + mat.val[1][1])%MD*n%MD)%MD;
        ans = (ans+(mat.val[0][0] + mat.val[1][0])%MD*(n-f[1].critF)%MD)%MD;
    }
    else {
        ans = (ans+(mat.val[0][0] + mat.val[1][0])%MD*f[1].critF%MD)%MD;
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
