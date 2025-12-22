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

using namespace std;

/*Constants*/
const int N = 110;
const int INF = 1e9+7;
const int NSIEVE = 2e5;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,k;
vector<piii> a;

bitset<NSIEVE+10> bs;
//Sieve

void Sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=NSIEVE; i++){
        if (bs[i]){
            for (int j=i*i; j<=NSIEVE; j+=i){
                bs[j] = false;
            }
        }
    }
}

//Dinitz
struct Node{
    int u,v,flow,cap;
    Node(int _u, int _v, int _cap): u(_u), v(_v), cap(_cap){
        flow = 0;
    }
};

int s,t,edgecnt;
vector<Node> edge;
vector<int> adj[N];
int level[N],ptr[N];

void AddEdge(int u, int v, int cap){
    edge.emplace_back(u,v,cap);
    edge.emplace_back(v,u,0);
    adj[u].push_back(edgecnt);
    adj[v].push_back(edgecnt+1);
    edgecnt+=2;
}

bool BFS(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[s] = 0;
    q.push(0);

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto id:adj[u]){
            int v = edge[id].v;
            if (level[v] == -1 && edge[id].flow!=edge[id].cap){
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }

    return (level[t]!=-1);
}

int DFS(int u, int pushed){
    if (pushed == 0) return 0;
    if (u==t) return pushed;

    int res = 0;

    for (int &pos = ptr[u]; pos<(int)adj[u].size(); pos++){
        int id = adj[u][pos];
        int v = edge[id].v;
        if (level[v] == level[u]+1 && edge[id].flow!=edge[id].cap){
            if ((res = DFS(v,min(pushed,edge[id].cap-edge[id].flow)))){
                edge[id].flow+=res;
                edge[id^1].flow-=res;
                return res;
            }
        }
    }

    return 0;
}

int Dinitz(){
    int max_flow = 0;
    while (BFS()){
        memset(ptr,0,sizeof(ptr));
        int flow;
        while ((flow = DFS(s,INF))){
            max_flow+=flow;
        }
    }
    return max_flow;
}

bool Check(int x){
    vector<pii> oddlist;
    int nodecnt = 0;
    int i = 0;
    int sp = 0;
    s = 0;
    int total = 0;
    while (i!=(int)a.size() && a[i].fi<=x){
        if (a[i].se.fi == 1) sp = max(sp,a[i].se.se);
        ++i;
    }
    if (sp!=0){
        nodecnt++;
        AddEdge(0,nodecnt,sp);
        oddlist.push_back({nodecnt,1});
        total+=sp;
    }
    i = 0;
    while (i!=(int)a.size() && a[i].fi<=x){
        if (a[i].se.fi != 1 && a[i].se.fi%2==1){
            nodecnt++;
            AddEdge(0,nodecnt,a[i].se.se);
            oddlist.push_back({nodecnt,a[i].se.fi});
            total+=a[i].se.se;
        }
        ++i;
    }
    i = 0;
    t = nodecnt;
    while (i!=(int)a.size() && a[i].fi<=x){
        if (a[i].se.fi != 1 && a[i].se.fi%2==0){
            ++t;
        }
        ++i;
    }
    ++t;
    i = 0;
    while (i!=(int)a.size() && a[i].fi<=x){
        if (a[i].se.fi != 1 && a[i].se.fi%2==0){
            nodecnt++;
            AddEdge(nodecnt,t,a[i].se.se);
            total+=a[i].se.se;
            for (auto in:oddlist){
                int id = in.fi, val = in.se;
                if (bs[a[i].se.fi+val]){
                    AddEdge(id,nodecnt,INF);
                }
            }
        }
        ++i;
    }
//    for (auto in:edge){
//        cout << in.u << " " << in.v << " " << in.cap << endl;
//    }
    int tmp = Dinitz();
    edgecnt = 0;
    edge.clear();
    for (int i=0; i<=t; i++){
        adj[i].clear();
    }
//    cout << tmp << endl;
    if (total-tmp>=k) return true;
    else return false;
}

/*Solution*/
void solve(){
    Sieve();
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int p,c,l; cin >> p >> c >> l;
        a.push_back({l,{c,p}});
    }
    sort(all(a));
    int ans = n+1;
    int l=1; int r = n;
    while (l<=r){
        int mid = (l+r)/2;
        if (Check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

//    int ans = n+1;
//    for (int i=n; i>0; i--){
//        if (Check(i)) ans = i;
//    }

    if (ans == n+1) cout << -1 << endl;
    else cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
