/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("Ofast")
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
const int BLOCK = 250;
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
vector<int> big[N];
int cnt[N];
vector<pii> query[N];
int ans[N];

void predfs(int u, int p) {
    cnt[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        predfs(v,u);
        cnt[u] += cnt[v];
    }
}

void ins(int u, map<int,int>* mp, pair<int,int> in) {
    auto itmp = mp->find(in.fi);
    if (itmp == mp->end()) {
        itmp = (mp->insert({in.fi,0})).fi;
    }
    if (c_big[in.fi]) {
        big[u][c_big[in.fi]] += in.se;
    }
    else {
        if (itmp->se != 0) {
            freq[u][itmp->se]--;
        }
        freq[u][itmp->se + in.se]++;
    }
    itmp->se += in.se;
}

map<int,int> *dfs(int u, int p) {
    cnt[u] = 1;
    int nxtidx = -1;
    int nxt = 0;
    vector<map<int,int>*> vmp;
    for (auto v:adj[u]) {
        if (v==p) continue;
        vmp.push_back(dfs(v,u));
        if (!nxt || vmp.back()->size()<vmp[nxtidx]->size()) {
            nxtidx = vmp.size()-1;
            nxt = v;
        }
    }

    map<int,int> *mp;

    if (nxt) {
        mp = vmp[nxtidx];
        for (int i=1; i<=block; i++){
            freq[u][i] = freq[nxt][i];
        }
        for (int i=1; i<=bcnt; i++){
            big[u][i] = big[nxt][i];
        }

        for (int idx=0; idx<vmp.size(); idx++) {
            if (idx==nxtidx) continue;
            map<int,int> *mp2 = vmp[idx];
            for (auto it=mp2->begin(); it!=mp2->end(); it++){
                ins(u,mp,{it->fi,it->se});
            }
            delete mp2;
        }
    }
    else {
        mp = new map<int,int>;
    }
    ins(u,mp,{c[u],1});

    for (auto [idx,val]:query[u]) {
        for (int i=val; i<=block; i++){
            ans[idx] += freq[u][i];
        }
        for (int i=1; i<=bcnt; i++){
            if (big[u][i] >= val) ++ans[idx];
        }
    }
    return mp;
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
    for (int i=1; i<=n; i++){
        big[i].resize(bcnt+1);
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

