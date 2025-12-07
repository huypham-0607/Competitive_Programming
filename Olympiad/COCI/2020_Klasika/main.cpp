/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LG = 30;
const int LGLCA = 20;
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
int n,q;
int tme[N];
int ans[N];
vector<pii> adj[N];
priority_queue<piii,vector<piii>,greater<piii>> query;

//Trie

struct Trie{
    struct Node{
        Node* child[2];
        int min_time;
        int sz;
        Node(){
            child[0] = child[1] = NULL;
            min_time = INF;
        }
    };

    Node* Root;
    int sz;
    int xr;
    Trie(){
        Root = new Node();
//        Root->min_time = 0;
        sz = xr = 0;
    }

    void Add(int x, int t){
        Node* cur = Root;
        for (int i=30; i>=0; i--){
            int idx = ((x>>i)&1);
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            cur = cur->child[idx];
            cur->min_time = min(t,cur->min_time);
        }
        ++sz;
    }
    void Merge(Trie* tr, Node* cur, int lg, int x){
        if (lg<0){
            tr->Add(x^xr^(tr->xr),cur->min_time);
            return;
        }
        if (cur->child[0]!=NULL){
            Merge(tr,cur->child[0],lg-1,x);
            delete cur->child[0];
        }
        if (cur->child[1]!=NULL){
            Merge(tr,cur->child[1],lg-1,x+(1<<lg));
            delete cur->child[1];
        }
    }

    int Get(int x, int t){
        Node* cur = Root;
        int res = 0;
        for (int i=30; i>=0; i--){
            int idx = ((x>>i)&1);
            idx = (idx+1)%2;
            if (cur->child[idx] == NULL || cur->child[idx]->min_time>t){
                res += (((idx+1)%2)<<i);
                cur = cur->child[(idx+1)%2];
            }
            else{
                res += (idx<<i);
                cur = cur->child[idx];
            }
        }
        return res;
    }
};

Trie* tr[N];

//LCA

int h[N];
int up[N][LGLCA], dist[N][LGLCA];

void dfs(int u, int p, int w){
    h[u] = h[p]+1;
    up[u][0] = p;
    dist[u][0] = w;
    for (int lg = 1; lg<LGLCA; lg++){
        int v = up[u][lg-1];
        up[u][lg] = up[v][lg-1];
        dist[u][lg] = (dist[u][lg-1]^dist[v][lg-1]);
    }

    for (auto in:adj[u]){
        int v = in.fi;
        int x = in.se;

        dfs(v,u,x);
    }
}

int GetDist(int u, int v){
    int res = 0;
    if (h[u] > h[v]) swap(u,v);
    int delta = h[v]-h[u];
    for (int lg = 0; lg<LGLCA; lg++){
        if ((delta>>lg)&1){
            res = (res^dist[v][lg]);
            v = up[v][lg];
        }
    }
    if (u==v) return res;
    for (int lg=LGLCA-1; lg>=0; lg--){
        if (up[u][lg]!=up[v][lg]){
            res = (res^dist[u][lg]^dist[v][lg]);
            u = up[u][lg];
            v = up[v][lg];
        }
    }
    return (res^dist[u][0]^dist[v][0]);
}

/*Solution*/
void solve(){
    cin >> q;
    string s;
    int n=1;
    int x,y;
    for (int tmp = 1; tmp<=q; tmp++){
        ans[tmp] = -1;
        cin >> s >> x >> y;
        if (s == "Add"){
            ++n;
            tme[n] = tmp;
            adj[x].push_back({n,y});
        }
        else{
            query.push({{-y,tmp},x});
        }
    }
    query.push({{0,0},0});
    dfs(1,0,0);
    for (int u=n; u>0; u--){
        if (adj[u].size() == 0){
            tr[u] = new Trie();
            tr[u]->Add(0,tme[u]);
        }
        else{
            tr[u] = new Trie();
            tr[u]->Add(0,tme[u]);
            Trie* lgst = tr[u];
            for (auto in:adj[u]){
                int v = in.fi;
                int w = in.se;
                tr[v]->xr = (tr[v]->xr^w);

                if (lgst->sz < tr[v]->sz) lgst = tr[v];
            }

            if (lgst!=tr[u]){
                tr[u]->Merge(lgst,tr[u]->Root,30,0);
                delete tr[u];
                tr[u] = lgst;
            }
            for (auto in:adj[u]){
                int v = in.fi;
//                int w = in.se;
                if (tr[u]!=tr[v]){
                    tr[v]->Merge(tr[u],tr[v]->Root,30,0);
                    delete tr[v];
                    tr[v] = NULL;
                }
            }
        }
        while (-query.top().fi.fi==u){
            int v = query.top().se;
            int t = query.top().fi.se;
            query.pop();
            int rawr = GetDist(u,v);
            rawr = (rawr^(tr[u]->xr));

            int mn = tr[u]->Get(rawr,t);
            ans[t] = (rawr^mn);
        }
    }
    for (int i=1; i<=q; i++){
        if (ans[i]!=-1){
            cout << ans[i] << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
