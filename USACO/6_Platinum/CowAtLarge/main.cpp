/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
int f[N],g[N],flen[N],glen[N];
int cnt[N], ans[N];
vector<int> adj[N];
vector<pii> faux[N];
vector<pii> gulag[N];

//BIT
int BIT[N];

void updateBIT(int idx, int val){
    ++idx;
    while (idx<=n+1){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int getPointBIT(int idx){
    ++idx;
    int res = 0;
    while (idx>0){
        res+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return res;
}

int getValBIT(int l, int r){
    return (getPointBIT(r)-getPointBIT(l-1));
}

//Centroid
int sz[N];
int vis[N];

int findSize(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u] += findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        if (sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

void calcf(int u, int p){
//    cout << u << endl;
    f[u] = 0;
    flen[u] = INF;
    faux[u].clear();
    if (adj[u].size() == 1){
        f[u] = 1;
        flen[u] = 0;
        return;
    }

    int childcnt = 0;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        calcf(v,u);
        if (!f[v]) continue;
        ++childcnt;
        f[u]+=f[v];
        for (auto [x,val]:faux[v]){
            --x;
            if (!x){
                f[u]-=val;
            }
            else{
                faux[u].push_back({x,val});
            }
        }
        flen[u] = min(flen[u],flen[v]+1);
    }

    int w = childcnt-1;
    sort(all(faux[u]));
    if (w){
        while (!faux[u].empty() && faux[u].back().fi>=flen[u]){
            w+=faux[u].back().se;
            faux[u].pop_back();
        }
        faux[u].push_back({flen[u],w});
    }
}

void dfscompute(int u, int org, int depth = 1, int p=0){
    cout << u << " " << org << " " << depth << " " << getValBIT(0,depth) << endl;
    ans[u]+=org-getValBIT(0,depth);
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfscompute(v,org,depth+1,u);
    }
}

void buildCentroid(int s){
    findSize(s);
    int u = findCentroid(s,sz[s]);
    vis[u] = true;
    f[u] = 0;
    flen[u] = INF;
    faux[u].clear();

    cout << u << endl;

    int childcnt = 0;
    pii mnlen{INF,INF};
    int nxt = 0;
    for (auto v:adj[u]){
        if (vis[v]) continue;
        calcf(v,u);
        if (!f[v]) continue;
        ++childcnt;
        if (flen[v]+1 < mnlen.fi){
            mnlen.se = mnlen.fi;
            mnlen.fi = flen[v]+1;
            nxt = v;
        }
        else if (flen[v] < mnlen.se){
            mnlen.se = flen[v]+1;
        }
        f[u]+=f[v];
        for (auto [x,val]:faux[v]){
            --x;
            faux[u].push_back({x,val});
        }
    }

    for (int i=1; i<=n; i++){
        cout << i << " " << f[i] << " " << flen[i] << ": ";
        for (auto [x,val]:faux[i]){
            cout << "{" << x << "," << val << "} ";
        }
        cout << endl;
    }

    int t = childcnt-2;
    for (auto v:adj[u]){
        if (vis[v]) continue;
        for (auto [x,val]:faux[v]){
            --x;
            if (x<mnlen.fi){
                updateBIT(x,val);
            }
            else t+=val;
        }
    }
    updateBIT(mnlen.fi,t);

    ans[u]+=f[u]-getValBIT(0,0);
    for (auto v:adj[u]){
        if (vis[v]) continue;
        if (v!=nxt){
            for (auto [x,val]:faux[v]){
                --x;
                if (x<mnlen.fi){
                    updateBIT(x,-val);
                }
            }
            dfscompute(v,f[u] - f[v]);
            for (auto [x,val]:faux[v]){
                --x;
                if (x<mnlen.fi){
                    updateBIT(x,val);
                }
            }
        }
    }
    updateBIT(mnlen.fi,-t);

    for (auto v:adj[u]){
        if (vis[v]) continue;
        for (auto [x,val]:faux[v]){
            --x;
            if (mnlen.fi<=x && x<mnlen.se){
                t-=val;
                updateBIT(x,val);
            }
        }
    }
    updateBIT(mnlen.se,t);

    if (nxt){
        for (auto [x,val]:faux[nxt]){
            --x;
            if (x<mnlen.fi){
                updateBIT(x,-val);
            }
        }
        dfscompute(nxt,f[u] - f[nxt]);
        for (auto [x,val]:faux[nxt]){
            --x;
            if (x<mnlen.fi){
                updateBIT(x,val);
            }
        }

    }

    updateBIT(mnlen.se,-t);

    for (auto v:adj[u]){
        if (vis[v]) continue;
        for (auto [x,val]:faux[v]){
            --x;
            if (x<mnlen.se){
                updateBIT(x,-val);
            }
        }
    }

    cout << endl;
    for (auto v:adj[u]){
        if (vis[v]) continue;
        buildCentroid(v);
    }
}


/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s = 1;
    if (adj[1].size() == 1){
        s = adj[s][0];
    }

    buildCentroid(s);

//    calcf(s,0);

//    for (int i=1; i<=n; i++){
//        cout << i << " " << f[i] << " " << flen[i] << ": ";
//        for (auto [x,val]:faux[i]){
//            cout << "{" << x << "," << val << "} ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    for (int i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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
