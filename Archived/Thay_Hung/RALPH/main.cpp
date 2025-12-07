#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,m,t;
vector<int> a[maxn];
vector<pii> path(maxn);
vector<bool> vis;
vector<int> mt;


double calcdist(pii x, pii y){
    int d1 = (x.fi - y.fi)*(x.fi - y.fi);
    int d2 = (x.se - y.se)*(x.se - y.se);
    return (sqrt(d1+d2));
}

bool match(int u){
    if (vis[u]) return false;
    vis[u] = true;
    for (int v:a[u]){
        if (!mt[v] || match(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int main(){
    //freopen("RALPH.inp","r",stdin);
    //freopen("RALPH.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        a[i].clear();
        int x,y;
        cin >> x >> y;
        path[i] = {x,y};
    }
    for (int i=1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        for (int j=1; j<n; j++){
            if (calcdist(path[j], path[j+1])*2 >= calcdist(path[j],{x,y}) + calcdist(path[j+1],{x,y})){
                a[j].push_back(i);
            }
        }
    }
    int c=0;
    mt.assign(m+10,0);
    for (int i=1; i<n; i++){
        vis.assign(n+10,false);
        if (match(i)){
            c++;
        }
    }
    cout << c + n << "\n";
    return 0;
}
