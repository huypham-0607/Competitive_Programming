#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e6+10;
const int INF = 2e9;

int ans = 0;
int n;
int succ[maxn],in[maxn];
bool watch[maxn];

void dfs(int u){
    in[u] = -1;
    int v = succ[u];
    if(watch[u]){
        watch[v] = false;
    }
    else ++ans;
    --in[v];
    if (!in[v]){
        dfs(v);
    }
}

void process(int s){
    int meow = 0;
    int u = s;
    int cur = s;
    int cnt = 0;
    do{
//        if (in[u] >=2) cout << in[u] << " AAAAAA WHY?" << endl;
        if (!in[u]) return;
        in[u] = 0;
        if (!watch[u]){
            ++ans;
            if (cur == s){
                meow = cnt;
            }
            else ans+=cnt/2;
            cur = succ[u];
            cnt = 0;
        }
        else ++cnt;
//        cout << "process: " << u << " " << meow << " " << cnt << " " << watch[u] << endl;
        u = succ[u];
    } while (u!=s);
    ans+=(meow+cnt)/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i=1; i<=n; i++){
        watch[i] = true;
        cin >> x;
        succ[i] = x;
        ++in[x];
    }
    for (int i=1; i<=n; i++){
        if (in[i] == 0){
            dfs(i);
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << in[i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        if (in[i] == 0){
//            dfs(i);
//        }
//    }
//    for (int i=1; i<=n; i++){
//        cout << in[i] << " ";
//    }
//    cout << endl;
    for (int i=1; i<=n; i++){
        if (in[i]>0){
            process(i);
        }
    }
    cout << ans;
//    cout << endl;
    return 0;
}
