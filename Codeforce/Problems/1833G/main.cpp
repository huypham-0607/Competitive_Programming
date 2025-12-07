#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5;

vector<int> a[maxn];
ii edge[maxn];
vector<int> ans;
int t,n;
int level[maxn], idx[maxn];
int cnt[maxn];

void levelfind(int u, int p, int lvl){
    level[u] = lvl;
    for (auto v:a[u]){
        if (v==p) continue;
        levelfind(v,u,lvl+1);
    }
}

bool dfs(int u, int p){
    int t=0;
    bool v = true;
    for (auto ver:a[u]){
        if (ver==p) continue;
        v = (v && dfs(ver,u));
        t+=cnt[ver];
    }
    if (!v) return v;
    if (t>2) return false;
    else{
        if (t == 2 && u!=1) ans.push_back(idx[u]);
        cnt[u] = (t+1)%3;
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        ans.clear();

        for (int i = 1; i<=n; i++){
            a[i].clear();
        }
        for (int i=1; i<n; i++){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
            edge[i] = {x,y};
        }
        if (n%3){
            cout << -1 << "\n";
            continue;
        }
        levelfind(1,0,1);
        for (int i=1; i<n; i++){
            if (level[edge[i].fi] > level[edge[i].se]) idx[edge[i].fi] = i;
            else idx[edge[i].se] = i;
        }
        if (!dfs(1,0)) cout << -1 << "\n";
        else{
            cout << ans.size() << "\n";
            for (auto u:ans){
                cout << u << " ";
            }
            cout << "\n";
        }
//        for (int i=1; i<=n; i++){
//            cout << idx[i] << " ";
//        }
//        cout << "\n";
    }
    return 0;
}
