#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;
const int maxlog = 20;

int test;
int n,m;
int timedfs = 0;
int up[maxlog+2][maxn];
int h[maxn],tin[maxn],tout[maxn];
vector<int> a[maxn];

void DFS(int u, int p,int height){
    tin[u] = ++timedfs;
    h[u] = height;
    up[0][u] = p;
    for (int lg=1; lg<=maxlog; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }

    for (auto v:a[u]){
        if (v == p) continue;
        DFS(v,u,height+1);
    }

    tout[u] = ++timedfs;
}

bool Isanc(int u, int v){
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    tin[0] = 0;
    tout[0] = INF;
    DFS(1,0,1);
    vector<pii> v;
    for (int i=1; i<=m; i++){
        v.clear();
        int k;
        cin >> k;
        for (int j=1; j<=k; j++){
            int x;
            cin >> x;
            if (x!=1) x = up[0][x];
            v.push_back({h[x],x});
        }
        sort(v.begin(),v.end());
        bool ver = true;
        for (int i=0; i<int(v.size())-1; i++){
            if (!Isanc(v[i].se,v[i+1].se)) ver = false;
        }

        if (ver) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
