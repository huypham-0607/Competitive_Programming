#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e6+10;
const int INF = 2e9;

int ans=0;
int n;
int suc[maxn];
vector<int> a[maxn];
bool vis[maxn];

bool dfs(int u, int p){
    bool watch = true;
    vis[u] = true;
    for (auto v:a[u]){
        if (v == p) continue;
        if (dfs(v,u) && watch){
            watch = false;
        }
    }
    if (!watch) ++ans;
//    cout << "DFS: " << u << " " << ((watch)? "True" : "False") << " " << ans << endl;
    return watch;
}

void FindCycle(int s){
    int x = suc[s];
    int y = suc[suc[s]];
    while (x!=y){
        x = suc[x];
        y = suc[suc[y]];
    }
//    cout << x << endl;
    bool watch = 0;
    int l = 0;
    int sus = 0;
    do{
        vis[x] = true;
        x = suc[x];
//        cout << "meow " << x << " " << ans << endl;
        ++l;
        int ver = 0;
        for (auto z:a[x]){
            if (!vis[z]){
                bool temp = dfs(z,x);
                ver = (ver || temp);
            }
        }
        if (ver){
            ++ans;
            watch = 0;
        }
        else{
            if (watch){
                ++ans;
                watch = 0;
            }
            else watch = 1;
        }
        if (x == suc[y]) sus = watch;
    } while (x!=y);
    if (watch && sus) ++ans;
//    cout << l << " ";
//    ans+=l/2;
//    cout << ans << " " << watch << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        suc[i] = x;
        a[x].push_back(i);
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
//            cout << "Bruh " << i << endl;
            FindCycle(i);
        }
    }
    cout << ans;
    return 0;
}
