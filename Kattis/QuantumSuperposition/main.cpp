/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e3+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n1,n2,m1,m2,q;
vector<int> adj1[N],adj2[N];
bool dp1[N][N],dp2[N][N];
int deg1[N],deg2[N];

/*Solution*/
void solve(){
    cin >> n1 >> n2 >> m1 >> m2;
    for (int i=1; i<=m1; i++){
        int u,v;
        cin >> u >> v;
        adj1[v].push_back(u);
        ++deg1[u];
    }
    for (int i=1; i<=m2; i++){
        int u,v;
        cin >> u >> v;
        adj2[v].push_back(u);
        ++deg2[u];
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=1; i<=n1; i++){
        if (!deg1[i]) pq.push(i);
    }
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();

        if (u==n1) dp1[u][0] = 1;
        for (auto v:adj1[u]){
            for (int i=1; i<=N-10; i++){
                dp1[v][i] = (dp1[v][i]||dp1[u][i-1]);
            }
            --deg1[v];
            if (!deg1[v]) pq.push(v);
        }
    }
    for (int i=1; i<=n2; i++){
        if (!deg2[i]) pq.push(i);
    }
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();

        if (u==n2) dp2[u][0] = 1;
        for (auto v:adj2[u]){
            for (int i=1; i<=N-10; i++){
                dp2[v][i] = (dp2[v][i]||dp2[u][i-1]);
            }
            --deg2[v];
            if (!deg2[v]) pq.push(v);
        }
    }
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        bool reachable = false;
        for (int val1=0; val1<=x; val1++){
            int val2 = x-val1;
            if(dp1[1][val1] && dp2[1][val2]) reachable = true;
        }
        if (reachable) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }
//    cout << n1 << " " << n2 << " " << m1 << " " << m2 << endl;
//    for (int i=1; i<=n1; i++){
//        for (int j=0; j<=m1; j++){
//            cout << dp1[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i=1; i<=n2; i++){
//        for (int j=0; j<=m2; j++){
//            cout << dp2[i][j] << " ";
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
