#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

/*Inititalization*/
void Init(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

/*Subtask5*/
bool CheckSub5(){
    return (d==1);
}

pii f[N],g[N];

void DFS(int u, int p){
    f[u] = {0,1};
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
        if (!f[v].fi){
            if (!f[u].fi){
                f[u].fi = 1;
                f[u].se = f[v].se;
            }
            else f[u].se = 0;
        }
        else{
            if (!f[u].fi) f[u].se+=f[v].se;
        }
    }
}

void SolveSub5(){

}

/*Subtask8*/
bool CheckSub8(){
    return false;
}

void SolveSub8(){

}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub5()) return SolveSub5(),0;
    if (CheckSub8()) return SolveSub8(),0;


    return 0;
}
