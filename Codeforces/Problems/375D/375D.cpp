/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("O3")
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
//#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+10;
const int BLOCK = 230;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q,bcnt=0,block;
int c[N];
int c_freq[N];
int c_big[N];

vector<int> adj[N];
int freq[N][BLOCK+1];
int cnt[N];
vector<pii> query[N];
int ans[N];

void predfs(int u, int p) {
    cnt[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        cnt[u] += cnt[v];
    }
}

void ins(int u, map<int,int>* mp, vector<int>* big, pair<int,int> in) {
    auto itmp = mp->find(in.fi);
    if (itmp == mp->end()) {
        itmp = (mp->insert({in.fi,0})).fi;
    }
    if (c_big[in.fi]) {
        (*big)[c_big[in.fi]] += in.se;
    }
    else {
        if (itmp->se != 0) {
            freq[u][itmp->se]--;
        }
        freq[u][itmp->se + in.se]++;
    }
    itmp->se += in.se;
}

pair<map<int,int>*,vector<int>*> dfs(int u, int p) {
    cnt[u] = 1;
    int nxt = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (!nxt || cnt[nxt]<cnt[v]) nxt = v;
    }

    map<int,int> *mp;
    vector<int> *big;

    if (nxt) {
        auto res = dfs(nxt,u);
        mp = res.fi;
        big = res.se;
        for (int i=1; i<=block; i++){
            freq[u][i] = freq[nxt][i];
        }
        for (int i=1; i<=bcnt; i++){
            big[u][i] = big[nxt][i];
        }

        for (auto v:adj[u]) {
            if (v==p || v==nxt) continue;
            auto mp2 = dfs(v,u).fi;
            for (auto it=mp2->begin(); it!=mp2->end(); it++){
                ins(u,mp,big,{it->fi,it->se});
            }
        }
    }
    else {
        mp = new map<int,int>;
        big = new vector<int>;
        big->resize(bcnt+1,0);
    }
    ins(u,mp,big,{c[u],1});

    for (auto [idx,val]:query[u]) {
        for (int i=val; i<=block; i++){
            ans[idx] += freq[u][i];
        }
        for (int i=1; i<=bcnt; i++){
            if ((*big)[i] >= val) ++ans[idx];
        }
    }
    return {mp,big};
}

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> c[i];
        ++c_freq[c[i]];
    }
    block = min((int)ceil(sqrt(n)),BLOCK);
    ffor(i,1,(int)1e5){
        if (c_freq[i] > block) {
            c_big[i] = ++bcnt;
        }
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=q; i++){
        int u,val; cin >> u >> val;
        query[u].push_back({i,val});
    }

    predfs(1,0);
    dfs(1,0);
    // cout << block << endl;
    // cout << "big: " << endl;
    // for (int i=1; i<=n; i++){
    //     cout << c_big[i] << " ";
    // }
    // cout << endl;
    // for (int u=1; u<=n; u++){
    //     cout << "u: " << u << endl;
    //     for (int i=1; i<=block; i++){
    //         cout << freq[u][i] << " ";
    //     }
    //     cout << endl;
    //     ffor(i,1,bcnt) cout << big[u][i] << " ";
    //     cout << endl;
    // }

    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
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

