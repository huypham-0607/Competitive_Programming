#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

int n,q,t=0;
int val[maxn],s[maxn],e[maxn],fw[maxn],init[maxn];
vector<int> a[maxn];

//Euler Tour

void dfs(int u, int p){
    t++;
    s[u] = t;
    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
    }
    e[u] = t;
}

//Fenwick

void update(int u, int v){
    v = v - val[u];
    for (int i = s[u]; i<=n; i+=(i & (-i))){
        fw[i]+=v;
    }
}

int query(int u){
    int t=0;
    for (int i=u; i>0; i-=(i & (-i))){
        t+=fw[i];
    }
    return t;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> init[i];
    }
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    for (int i=1; i<=n; i++){
        update(i,init[i]);
        val[i] = init[i];
    }
//    for (int i=1; i<=n; i++){
//        cout << query(i) << " ";
//    }
    while (q--){
        int cmd;
        cin >> cmd;
        if (cmd == 1){
            int x,y;
            cin >> x >> y;
            update(x,y);
            val[x] = y;
        }
        else{
            int x;
            cin >> x;
            cout << query(e[x]) - query(s[x]-1) << "\n";
//            for (int i=1; i<=n; i++){
//                cout << query(i) << " ";
//            }
//            cout << "\n";
        }
    }
    return 0;
}
