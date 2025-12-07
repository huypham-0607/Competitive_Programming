/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

#define NAME "shortestpaths"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1000;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m;

mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(ll l, ll r){
    return mt()%(r-l+1)+l;
}

set<pii> lst;
vector<pii> adj[N];
int dist[N];
int parent[N];
vector<int> trace;
priority_queue<piii,vector<piii>,greater<piii>> pq;

void dijkstra(int s, bool sus){
    while (!pq.empty()) pq.pop();
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    pq.push({0,{s,0}});
    while (!pq.empty()){
        int d = pq.top().fi;
        int u = pq.top().se.fi;
        int p = pq.top().se.se;
        pq.pop();

        if (d>dist[u]) continue;

//        cout

        if (sus && !parent[u]){
            parent[u] = p;
        }
        for (auto in:adj[u]){
            int v = in.fi;
            int delta = in.se;

            if (d+delta < dist[v]){
                dist[v] = d+delta;
                pq.push({d+delta,{v,u}});
            }
        }
    }
}

void Gen(){
    ofstream cout(NAME".inp");

    n = rd(8,12);
    m = rd(n+3,n+8);
    int a = rd(1,n-1);
    int b = rd(a+1,n);
    cout << n << " " << m << " " << a << " " << b << endl;

    lst.clear();
    for (int i=1; i<=n; i++){
        parent[i] = 0;
        adj[i].clear();
    }

    for (int i=1; i<=m; i++){
        bool ver = 0;
        while (!ver){
            int u;
            if (i<n){
                u = n-i;
            }
            else u = rd(1,n-1);
            int v = rd(u+1,n);
            if (!lst.count(make_pair(u,v))){
                int val = rd(5,20);
                adj[u].push_back({v,val});
                adj[v].push_back({u,val});
                ver = true;
                lst.insert(make_pair(u,v));
                cout << u << " " << v << " " << val << endl;
            }
        }
    }
    dijkstra(a,1);
    trace.clear();
    int cur = b;
//    for (int i=1; i<=n; i++){
//        cout << parent[i] << endl;
//    }
    while (cur!=a){
//        cerr << cur << endl;
        trace.push_back(cur);
        cur = parent[cur];
    }
    trace.push_back(cur);
    cout << trace.size() << " ";
    while (!trace.empty()){
        cout << trace.back() << " ";
        trace.pop_back();
    }

    cout.close();
}

/*Solution*/
void solve(){
    Gen();

    system(NAME".exe");
    system(NAME"_brute.exe");
    if (system("fc " NAME ".out " NAME ".ans")){
        cerr << "WA" << endl;
        exit(0);
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    srand(time(NULL));
    TestCases(0);

    return 0;
}

