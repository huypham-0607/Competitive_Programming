/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 55;
const int LIM = 50;
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
//int n;

vector<pii> adj[N];
vector<int> dist(N);
int a[N],b[N];

bool Dijkstra(int s, int e){
    for (int i=0; i<=50; i++){
        dist[i] = LLINF;
    }
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        if (d>dist[u]) continue;

        for (auto in:adj[u]){
            int v = in.fi;
            int delta = in.se;

            if (d+delta < dist[v]){
                dist[v] = d+delta;
                pq.push({d+delta,v});
            }
        }
    }
//    for (int i=0; i<=50; i++){
//        if (dist[i] == LLINF) cout << -1 << " ";
//        else cout << dist[i] << " ";
//    }
//    cout << endl;
    if (dist[e] == LLINF) return false;
    else return true;
}

bool Check(){
    for (int i=1; i<=n; i++){
        if (!Dijkstra(a[i],b[i])){
            return false;
        }
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }
    int ans = LLINF;
    int val = ((int)1<<(LIM+1))-2;
    for (int idx=LIM+1; idx>0; idx--){
//        cout << "idx: " << idx << endl;
        for (int i=0; i<=50; i++){
            adj[i].clear();
        }
        int tmp = val;
        if (idx!=LIM+1) tmp = tmp^((int)1<<idx);
        for (int i=1; i<=LIM; i++){
            if (!(tmp&((int)1<<i))){
//                cout << 0;
                continue;
            }
//            cout << 1;
            for (int u=i; u<=50; u++){
                int v = u%i;
                adj[u].push_back({v,((int)1<<i)});
            }
        }
//        cout << endl;

        if (Check()){
            ans = tmp;
            val = tmp;
        }
    }
    if (ans == LLINF) cout << -1 << endl;
    else cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
