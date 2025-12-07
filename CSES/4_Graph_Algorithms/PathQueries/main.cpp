#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

int m,n,timedfs=0;
int euler[2*maxn];
int tin[maxn],tout[maxn];
vector<int> a[maxn];
int val[maxn];

//Euler

void dfs(int u, int p){
    tin[u] = ++timedfs;

    for (auto v:a[u]){
        if (v==p) continue;
        dfs(v,u);
    }

    tout[u] = ++timedfs;
}

//Fenwick

void update(int pos, int x){
    while (pos<=n*2){
        euler[pos]+=x;
        pos+=(pos&(-pos));
    }
}

int query(int pos){
    int t=0;
    while (pos>0){
        t+=euler[pos];
        pos-=(pos&(-pos));
    }
    return t;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
//    cout << "\n";
//    for (int i=1; i<=n; i++){
//        cout << tin[i] << " " << tout[i] << "\n";
//    }
    for (int i=1; i<=n; i++){
        update(tin[i],val[i]);
        update(tout[i],-val[i]);
    }
//    cout << "meow" << "\n";
    while (m--){
        int type;
        cin >> type;
        if (type == 1){
            int x,s;
            cin >> s >> x;
            update(tin[s],x-val[s]);
            update(tout[s],-x+val[s]);
            val[s] = x;
        }
        else{
            int s;
            cin >> s;
            cout << query(tin[s]) << "\n";
        }
    }

    return 0;
}
