#include <bits/stdc++.h>
#define pii pair<int,int>
#define pdd pair<double,double>
#define fi first
#define se second

using namespace std;

const int N = 110;

int n,m,s,v;
pdd pos[N];
vector<int> a[N],mt;
vector<bool> vis;

double calcdist(pdd x, pdd y){
    double d1 = x.fi - y.fi;
    double d2 = x.se - y.se;
    return sqrt(d1*d1+d2*d2);
}

//BIPARTITE MATCHING

bool match(int u){
    if (vis[u]) return false;
    vis[u] = true;
    for (auto v:a[u]){
        if (!mt[v] || match(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("CHUOTCHUI.inp","r",stdin);
    freopen("CHUOTCHUI.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> v;
    for (int i=1; i<=n; i++){
        double x,y;
        cin >> x >> y;
        pos[i] = {x,y};
    }
    for (int i=1; i<=m; i++){
        double x,y;
        cin >> x >> y;
        for (int j=1; j<=n; j++){
            double dist = calcdist(pos[j],{x,y});
            double meow = s*v;
            //cout << dist << "\n";
            if (dist <= meow) a[j].push_back(i);
        }
    }
//    for (int i=1; i<=m; i++){
//        for (auto j:a[i]){
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    int c=0;
    mt.assign(n+10,0);
    for (int i=1; i<=m; i++){
        vis.assign(m+10,false);
        if (match(i)) ++c;
    }
    cout << n-c;
    return 0;
}
