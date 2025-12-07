#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

vector<vector<int>> st(20,vector<int>(maxn,0));
vector<int> tin(maxn,0),tout(maxn,0),lvl(maxn,0),a[maxn];
int t = 0;
int n,q,lg;

void dfs(int u, int p, int l){
    tin[u] = ++t;
    lvl[u] = l;

    st[0][u] = p;
    for (int i=1; i<=lg; i++){
        st[i][u] = st[i-1][st[i-1][u]];
    }
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u,l+1);
    }
    tout[u] = ++t;
}

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int x,int y){
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    //cout << y << " ";
    for (int i=lg; i>=0; i--){
        if (!is_ancestor(st[i][y],x)){
            y = st[i][y];
            //cout << y << " ";
        }
    }
    //cout << "\n";
    return st[0][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    lg = ceil(log2(n));
    tout[0] = maxn*3;
    dfs(1,0,0);
    int x,y;
    while (q--){
        cin >> x >> y;
        int z = lca(x,y);
        cout << lvl[x] + lvl[y] - lvl[z]*2 << "\n";
    }
//    for (int i=0; i<=n; i++){
//        cout << tin[i] <<  " ";
//    }
//    cout << "\n";
//    for (int i=0; i<=n; i++){
//        cout << tout[i] << " ";
//    }
//    cout << "\n";
    return 0;
}
