/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int LG = 18;
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,q,curh = 0;
int elt[N*2];
int elt_size=0;
int tin[N],h[N];
int st[LG][N*2];
vector<int> a[N];
int Bruh[N*2];

void DFS(int u, int p){
    h[u] = h[p]+1;
    tin[u] = ++elt_size;
    elt[elt_size] = u;

    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        elt[++elt_size] = u;
    }
    --curh;
}

int GetLCA(int u, int v){
    if (tin[u]>tin[v]) swap(u,v);
    int lg = Bruh[(tin[v]-tin[u]+1)];
    return (h[st[lg][tin[u]]] < h[st[lg][tin[v]-(1<<lg)+1]])? st[lg][tin[u]]:st[lg][tin[v]-(1<<lg)+1];
}

/*Solution*/
void solve(){
    cin >> n >> q;
    int u,v;
    for (int i=1; i<n; i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    Bruh[1] = 0;
    for (int i=2; i<=n*2; i++){
        Bruh[i] = Bruh[i/2]+1;
    }

    DFS(1,0);

    for (int lg=0; lg<LG; lg++){
        for (int i=1; i<=n*2; i++){
            if (lg==0) st[0][i] = elt[i];
            else if (i+(1<<lg)-1>n*2) break;
            else st[lg][i] = (h[st[lg-1][i]] < h[st[lg-1][i+(1<<(lg-1))]])? st[lg-1][i]: st[lg-1][i+(1<<(lg-1))];
        }
    }
    int ju,jv,au,av,res=0;
    cin >> u >> v >> ju >> jv >> au >> av;
    while (q--){
        res ^= GetLCA(u,v);
        u = ((ll)u*ju+au)%n+1;
        v = ((ll)v*jv+av)%n+1;
    }
    cout << res;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
