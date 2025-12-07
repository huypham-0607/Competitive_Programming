#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int n,t,q;
vector<int> a[200100],b;

void DFS(ll u, ll parent){
    for (auto v:a[u]){
        if (v==parent) continue;
        DFS(v,u);
        b[u]+=b[v];
    }
    if (b[u] == 0) b[u]=1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        b.clear();
        for (ll i=1; i<=n; i++){
            a[i].clear();
            b.push_back(0);
        }
        b.push_back(0);
        for (ll i=1; i<n; i++){
            ll x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        DFS(1,0);
        cin >> q;
        while (q--){
            ll x,y;
            cin >> x >> y;
            ll total = b[x]*b[y];
            cout << total << "\n";
        }
    }
    return 0;
}
