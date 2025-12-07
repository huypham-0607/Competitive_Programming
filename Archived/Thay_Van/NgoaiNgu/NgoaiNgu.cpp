#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 105;

int p[maxn];
int n,m;
unordered_set<int> a[maxn];

void init(int n){
    for (int i = 1; i <= n; i++) p[i] = -1;
}

int root(int u){
    return p[u] < 0 ? u : p[u] = root(p[u]);
}

void join(int u,int v){
    u = root(u);
    v = root(v);
    if (p[u] > p[v]) swap(u,v);
    p[u] += p[v];
    p[v] = u;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NgoaiNgu.inp","r",stdin);
    freopen("NgoaiNgu.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int t;
        cin >> t;
        while(t--){
            int x;
            cin >> x;
            a[i].insert(x);
        }
    }
    init(n);
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            for (int x : a[j]){
                if (a[i].count(x)){
                    join(i,j);
                    break;
                }
            }
        }
    }
    int res = 0;
    bool f = 0;
    for (int i = 1; i <= n; i++){
        res += (p[i] < 0);
        f |= (a[i].size() > 0);
    }
    res -= f;
    cout << res;
    return 0;
}
