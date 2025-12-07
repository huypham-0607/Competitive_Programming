#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,q;
int parent[maxn],cnt[maxn],ans[maxn];
vector<piii> v,query;

//DSU

void Init(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        cnt[i] = 1;
    }
}

int Find(int i){
    return (parent[i] == i)? i : parent[i] = Find(parent[i]);
}

bool Same(int x, int y){
    return Find(x) == Find(y);
}

void Union(int x, int y){
    if (!Same(x,y)){
        int u = Find(x);
        int v = Find(y);
        cnt[u] += cnt[v];
        parent[v] = u;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    Init(n);
    for (int i=1; i<n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({z,{x,y}});
    }
    for (int i=1; i<=q; i++){
        int x,y;
        cin >> x >> y;
        query.push_back({x,{i,y}});
    }
    sort(v.begin(),v.end(),greater<piii>());
    sort(query.begin(),query.end(),greater<piii>());
    int j = 0;
    query.push_back({0,{1,1}});
    v.push_back({0,{1,1}});
    for (int i=0; i<n; i++){
        int u = v[i].se.fi;
        int ver = v[i].se.se;
        Union(u,ver);
        while (v[i+1].fi < query[j].fi){
            int idx = query[j].se.fi;
            int x = query[j].se.se;

            ans[idx] = cnt[Find(x)];
            ++j;
        }
    }
    for (int i=1; i<=q; i++){
        cout << ans[i]-1 << endl;
    }
//    for (piii in:v){
//        cout << in.fi << " " << in.se.fi << " " << in.se.se << endl;
//    }
    return 0;
}
