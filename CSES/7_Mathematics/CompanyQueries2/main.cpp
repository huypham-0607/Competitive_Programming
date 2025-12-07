#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+100;

vector<vector<ii>> st(30,vector<ii> (maxn*3,{0,0}));
vector<int> a[maxn],e,h(maxn,0),l(maxn,0);
int n,q,lg;

void dfs(int u,int p, int lvl){
    h[u] = e.size();
    e.push_back(u);
    l[u] = lvl;
    for (auto v:a[u]){
        dfs(v,u,lvl+1);
        e.push_back(u);
    }
}

int main(){
    //freopen("meh.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    //int lg = 18;
    dfs(1,0,0);
    for (int i=0; i<int(e.size()); i++){
        st[0][i] = {l[e[i]],e[i]};
    }
    //cout << "meow" << "\n";
    for (int i=1; i<=18; i++){
        for (int j=0; j<int(e.size()); j++){
            st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    int x,k;
    while (q--){
        cin >> x >> k;
        if (h[x] > h[k]) swap(k,x);
        int i = (h[k]-h[x]+1) ? __builtin_clzll(1) - __builtin_clzll(h[k]-h[x]+1) : -1;
        if (i==-1) cout << x << "\n";
        cout << min(st[i][h[x]],st[i][h[k]-(1 << i)+1]).se << "\n";
    }
    return 0;
}
