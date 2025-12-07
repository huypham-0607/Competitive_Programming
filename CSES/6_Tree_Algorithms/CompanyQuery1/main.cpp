#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

vector<vector<int>> up(maxn,vector<int> (20,0));
vector<int> a[maxn];
int n,q,lg;

void dfs(int u,int p){
    up[u][0] = p;
    for (int i=1; i<=lg; i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (auto v:a[u]){
        dfs(v,u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    lg = ceil(log2(n));
    dfs(1,0);
    int x,k;
    while (q--){
        cin >> x >> k;
        int cur = x;
        for (int i=0; i<=lg; i++){
            if (k&(1<<i)) cur = up[cur][i];
        }
        if (!cur) cout << -1 << "\n";
        else cout << cur << "\n";
    }
    return 0;
}
