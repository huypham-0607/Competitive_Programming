#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "PERTREE"

using namespace std;

/*Constants*/
const int N = 5010;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
vector<int> adj[N];
int parent[N];
int val[N];
vector<int> order;

/*Inititalization*/
void Init(){
    cin >> n;
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        parent[u] = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
}

/*Subtask1*/
bool CheckSub1(){
    return (true);
}

int ans[N];
bool vis[N];

bool check(){
    for (int i=0; i<=n; i++){
        vis[i] = false;
    }
    vis[0] = true;
    for (auto u:order){
        if (!vis[parent[u]]) return false;
        vis[u] = true;
    }
//    for (auto u:order){
//        cout << u << " ";
//    }
//    cout << endl;
    return true;
}

void SolveSub1(){
    for (int i=1; i<=n; i++){
        order.push_back(i);
    }
    do{
        if (check()){
            for (int i=1; i<=n; i++){
                ans[order[i-1]] = (ans[order[i-1]] + val[i])%MD;
            }
        }
    }while (next_permutation(all(order)));
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*Subtask2*/
bool CheckSub2(){
    return false;
}

void SolveSub2(){

}

/*Subtask3*/
bool CheckSub3(){
    return false;
}

void SolveSub3(){

}

/*Subtask4*/
bool CheckSub4(){
    return false;
}

void SolveSub4(){

}

/*Driver Code*/
signed main(){
//    freopen(NAME".inp","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;

    return 0;
}
