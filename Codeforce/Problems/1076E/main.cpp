#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,piii>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5+10;
const int INF = 2e9;

int n,q,timedfs = 0;
int tin[maxn],tout[maxn],height[maxn];
vector<int> a[maxn];
vector<pii> update[maxn];



void dfs(int u, int p, int h){
    height[u] = h;
    tin[u] = ++timedfs;
    for (int v:a[u]){
        if (v == p) continue;
        dfs(v,u,h+1);
    }
    tout[u] = ++timedfs;
}

void

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0,0);
    cin >> q;
    for (int i=1; i<=q; i++){
        int v,d,x;
        cin >> v >> d >> x;
        update[v] = {d,x};
    }
    return 0;
}
