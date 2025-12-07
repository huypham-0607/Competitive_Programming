/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define piii2 pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5e5+100;
const int INF = 2e11+17;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int lft[N],rgt[N],val[N];
map<int,int> mp;
vector<piii> v;
vector<piii2> edge;
priority_queue<piii,vector<piii>,greater<piii>> pq;

//DSU
int parent[N];

void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int Find(int x){
    return (parent[x] == x)? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        parent[x] = y;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int l,r,x;
        cin >> l >> r >> x;
        lft[i] = l;
        rgt[i] = r;
        val[i] = x;
        v.push_back({{l,r},x});
    }
    mp.insert({INF,0});
    mp.insert({-INF,0});
    sort(v.begin(),v.end());
    for (int i=1; i<=n; i++){
        int l = v[i-1].fi.fi;
        int r = v[i-1].fi.se;
        int w = v[i-1].se;

        while (!pq.empty() && pq.top().fi.fi < l){
            int x = pq.top().se;
            int idx = pq.top().fi.se;
            if (mp.find(x)!=mp.end() && mp[x]==idx) mp.erase(x);
            pq.pop();
        }
        auto it = mp.lower_bound(w);
        if (it->fi!=INF) edge.push_back({abs(it->fi-w),{i,it->se}});
        --it;
        if (it->fi!=-INF) edge.push_back({abs(it->fi-w),{i,it->se}});

        if (mp.find(w)==mp.end() || rgt[mp[w]] < r){
            mp[w] = i;
            pq.push({{r,i},w});
        }
    }
    while (!pq.empty()) pq.pop();
    mp.clear();
    sort(edge.begin(),edge.end());
    int UnionCount = 0;
    Init();
    int ans = 0;
    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        if (Find(u)!=Find(v)){
            UnionCount++;
            Union(u,v);
            ans+=w;
        }
    }
//    if (n == 500000){
//        cout <<  UnionCount << " " << Find(0) << " " << Find(1) << endl;
//    }
    if (UnionCount != n-1){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    edge.clear();
    v.clear();
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(1);

    return 0;
}
