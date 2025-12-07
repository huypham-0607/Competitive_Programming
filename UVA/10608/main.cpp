#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 50000

using namespace std;

int t,n,m;
int parent[lim],sum[lim];

void InitSet(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        sum[i] = 1;
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
        sum[FindSet(y)]+=sum[FindSet(x)];
        parent[FindSet(x)] = FindSet(y);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m;
        InitSet(n);
        while (m--){
            int x,y;
            cin >> x >> y;
            UnionSet(x,y);
        }
        int mx = 0;
        for (int i=1; i<=n; i++){
            mx = max(mx,sum[i]);
        }
        cout << mx << "\n";
    }
    return 0;
}
