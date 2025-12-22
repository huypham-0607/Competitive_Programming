#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;
vector<int> a[maxn];
int l[maxn],r[maxn],dpl[maxn],dpr[maxn];

void dfs(int u, int p){
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
        dpl[u]+=max(abs(l[u]-l[v])+dpl[v],abs(l[u]-r[v])+dpr[v]);
        dpr[u]+=max(abs(r[u]-l[v])+dpl[v],abs(r[u]-r[v])+dpr[v]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=1; i<=n; i++){
            a[i].clear();
            dpl[i] = 0;
            dpr[i] = 0;
            cin >> l[i] >> r[i];
        }
        for (int i=1; i<n; i++){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,0);
        cout << max(dpr[1],dpl[1]) << endl;
//        for (int i=1; i<=n; i++){
//            cout << dpl[i] << " " << dpr[i] << endl;
//        }
    }
    return 0;
}
