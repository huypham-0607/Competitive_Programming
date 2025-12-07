/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define psusiii pair<int,pii>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5e5+10;
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
int n,m;
int parent[N];
vector<piiii> v;
int vl[N];
vector<int> nen;
vector<psusiii> edges;
set<piii> st;

//DSU
void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

bool Same(int u, int v){
    return (Find(u) == Find(v));
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x>y) swap(x,y);
    if (x!=y){
        parent[y] = x;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    Init();
    for (int i=1; i<=n; i++){
        int l,r,val;
        cin >> l >> r >> val;
        vl[i] = val;
        v.push_back({{val,i},{l,r}});
    }
    sort(v.begin(),v.end());
    st.insert({{0,0},0});
    st.insert({{INF,INF},n+1});
    queue<piii> q;
    int ans = 0;
    for (auto in:v){
        int val1 = in.fi.fi;
        int idx1 = in.fi.se;
        int l1 = in.se.fi;
        int r1 = in.se.se;
        auto it = st.upper_bound({{r1,INF},INF});
        auto luuit = it;
        while (prev(it)->fi.se>=l1){
            --it;
            int l2 = it->fi.fi;
            int r2 = it->fi.se;
            int idx2 = it->se;
            int val2 = vl[idx2];
            if (l2 < l1 && r1 < r2){
                q.push({{l2,l1-1},idx2});
                q.push({{r1+1,r2},idx2});
            }
            else if (l1 <= l2 && r1 < r2){
                q.push({{r1+1,r2},idx2});
            }
            else if (l2 < l1 && r2 <= r1){
                q.push({{l2,l1-1},idx2});
            }
            edges.push_back({abs(val1-val2),{idx1,idx2}});
        }
        q.push({{l1,r1},idx1});
        st.erase(it,luuit);
        while (!q.empty()){
            st.insert(q.front());
            q.pop();
        }
    }
    sort(edges.begin(),edges.end());
    for (auto in:edges){
        int val = in.fi;
        int u = in.se.fi;
        int v = in.se.se;
        if (!Same(u,v)){
            ans+=val;
            Union(u,v);
        }
    }
    int ver = 0;
    for (int i=1; i<=n; i++){
        if (ver==0) ver = Find(i);
        else if (ver!=Find(i)) ver = -1;
    }
    if (ver == -1) cout << ver << endl;
    else cout << ans << endl;
    v.clear();
    st.clear();
    edges.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
