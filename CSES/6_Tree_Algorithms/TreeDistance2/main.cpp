#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

int child[maxn],down[maxn],up[maxn],parent[maxn],parent2[maxn];
vector<int> a[maxn];
int n;

void childcalc(int u, int p){
    int x = 1;
    for (auto v:a[u]){
        if (v==p) continue;
        childcalc(v,u);
        x+=child[v];
    }
    child[u] = x;
}

void parentcalc(int u, int p){
    parent[u] = child[p] - child[u];
    parent2[u] = n-child[u];
    for (auto v:a[u]){
        if (v==p) continue;
        parentcalc(v,u);
    }
}

void downcalc(int u, int p){
    int x=0;
    for (auto v:a[u]){
        if (v==p) continue;
        downcalc(v,u);
        x+=down[v]+child[v];
    }
    down[u] = x;
}

void upcalc(int u, int p){
    int x=0;
    if (u!=1){
        x+=up[p] + parent2[p];
        x+= down[p] - down[u] - child[u] + parent[u];
    }
    up[u] = x;
    for (auto v:a[u]){
        if (v==p) continue;
        upcalc(v,u);
    }
}

using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    child[0] = n;
    up[0] = 0;
    parent[0] = 0;
    childcalc(1,0);
    parentcalc(1,0);
    downcalc(1,0);
    upcalc(1,0);
//    for (int i=1; i<=n; i++){
//        cout << child[i] << " ";
//    }
//    cout << "\n";
//    for (int i=1; i<=n; i++){
//        cout << parent[i] << " ";
//    }
//    cout << "\n";
//    for (int i=1; i<=n; i++){
//        cout << down[i] << " ";
//    }
//    cout << "\n";
//    for (int i=1; i<=n; i++){
//        cout << up[i] << " ";
//    }
//    cout << "\n";
    for (int i=1; i<=n; i++){
        cout << up[i] + down[i] << " ";
    }
    return 0;
}
