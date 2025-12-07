#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,pair<ll,ll>>
#define fi first
#define se second
#define lim 10010
#define uplim 100010

using namespace std;

int parent[lim];
iii a[uplim];
int m,n;

void InitSet(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int FindSet(int x){
    return (x == parent[x]) ? x : FindSet(parent[x]);
}

bool SameSet(int x, int y){
    return (FindSet(x) == FindSet(y));
}

void UnionSet(int x, int y){
    if (FindSet(x) != FindSet(y)){
        parent[FindSet(x)] = FindSet(y);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    InitSet(n);
    for (int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        a[i] = {z,{x,y}};
    }
    sort(a,a+m);
    ll t =0;
    for (int i=0; i<m; i++){
        ll d = a[i].fi;
        int u = a[i].se.fi;
        int v = a[i].se.se;

        if (!SameSet(u,v)){
            t+=d;
            UnionSet(u,v);
        }
    }
    cout << t;
    return 0;
}
