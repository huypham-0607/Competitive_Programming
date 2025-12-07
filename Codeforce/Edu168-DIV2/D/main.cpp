/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+100;
const int INF = 1e9+7;
const long long LLINF = 1e15+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int a[N];
vector<int> adj[N];


bool DFS(int u, int p, int x){
    int rawr = 0;
    int ccnt = 0;
    if (a[u] < x) rawr=x-a[u];
    bool ver = true;
    for (auto v:adj[u]){
        if (v==p) continue;
        ++ccnt;
        ver = (DFS(v,u,min(x+rawr,LLINF))&&ver);
    }
    if (ccnt == 0){
        if (rawr) return false;
        else return true;
    }
    else return ver;
}

bool check(int x){
    bool ver = 1;
    for (auto v:adj[1]){
        ver = (DFS(v,1,x)&&ver);
    }
    return ver;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
//    if (n==1){
//        cout << a[1] << endl;
//        return;
//    }
    int res = 0;
    int l = 1;
    int r = INF;

    while (l<=r){
        int mid = (l+r)/2;
//        cout << mid << endl;
        if (check(mid)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    cout << res+a[1] << endl;

    for (int i=1; i<=n; i++){
        adj[i].clear();
        a[i] = 0;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
