#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t,cnt;
vector<int> a[maxn];

void dfs(int u, int p){
    if (a[u].size() == 1) cnt++;
    for (auto v:a[u]){
        if (v == p) continue;
        dfs(v,u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        cnt = 0;
        for (int i=1; i<=n; i++){
            a[i].clear();
        }
        for (int i=1; i<n; i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1,0);
        cout << (cnt/2)+(cnt%2) << endl;
    }
    return 0;
}
