/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
//#define int long long
#define ld long double
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct Line{
    ll m,n;

    Line(ll _m=0, ll _n=0): m(_m), n(_n) {};

    ll operator()(ll x){ return m*x+n;}

    friend ld intersect(Line a, Line b){ return (ld)(b.n-a.n)/(ld)(a.m-b.m);}
};

/*Global Variables*/
int n,m;
//stack<Line> tmpline;
int dist[N];
ll dp[N];
vector<pii> adj[N];
int s[N],v[N];

Line dq[N];
int sz = 0;

int GetPos(Line line){
    int ans = sz;
    int l = 1, r = sz-1;
    while (l<=r){
        int mid = (l+r)/2;
        if (intersect(dq[mid-1],dq[mid]) > intersect(dq[mid-1],line)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

//int AddLine (Line u){
//    int pos = GetPos(u);
//    while (dq.size() > 1 && intersect(dq[dq.size()-1],dq[dq.size()-2])>intersect(dq[dq.size()-1],u)){
//        ++cnt;
//        tmpline.push(dq.back());
//        dq.pop_back();
//    }
//    dq.push_back(u);
//    return cnt;
//}

//void DeleteLine(int cnt){
//    dq.pop_back();
//    while (cnt){
//        --cnt;
//        dq.push_back(tmpline.top());
//        tmpline.pop();
//    }
//}

int Query(ll x){
    int ans = 0;
    int l = 1, r = sz-1;
    while (l<=r){
        int mid = (l+r)/2;
        if (intersect(dq[mid-1],dq[mid])<x){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}

void DFS(int u, int p=0){
//    cout << "in: " << u << endl;
    if (u!=1){
        int pos = Query(v[u]);
        dp[u] = (ll)v[u]*dq[pos].m + dq[pos].n + s[u] + (ll)dist[u]*v[u];
    }
    Line line((ll)-dist[u],dp[u]);
    int pos = GetPos(line);
    Line saveline = dq[pos];
    int savesz = sz;
    dq[pos] = line;
    sz = pos+1;
//    cout << tmpline.size() << " " << cnt << endl;
    for (auto in:adj[u]){
        int v = in.fi;
        int w = in.se;
        if (v==p) continue;
        dist[v] = dist[u] + w;
        DFS(v,u);
    }
    dq[pos] = saveline;
    sz = savesz;
//    cout << "out: " << u << endl;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=2; i<=n; i++){
        cin >> s[i] >> v[i];
    }

    DFS(1);

    for (int i=2; i<=n; i++){
        cout << dp[i] << " ";
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
