/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
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
int n;
int a[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int vis[N];
int last[N];
vector<int> spos[N];

//SEGG

piiii ST[4*N];

void BuildST(int idx, int l, int r){
    if (l==r){
        ST[idx] = {{a[l],l},{a[l],-l}};
        return;
    }
    int mid = (l+r)/2;
    BuildST(idx*2,l,mid); BuildST(idx*2+1,mid+1,r);
    ST[idx].fi = min(ST[idx*2].fi,ST[idx*2+1].fi);
    ST[idx].se = max(ST[idx*2].se,ST[idx*2+1].se);
}

void Update(int idx, int l, int r, int x){
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = {{INF,INF},{0,-INF}};
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x); Update(idx*2+1,mid+1,r,x);
    ST[idx].fi = min(ST[idx*2].fi,ST[idx*2+1].fi);
    ST[idx].se = max(ST[idx*2].se,ST[idx*2+1].se);
}

pii Query(int idx, int l, int r, int x, int y, bool ismax){
    if (r<x || y<l){
        if (ismax) return make_pair(0,-INF);
        else return make_pair(INF,INF);
    }
    if (x<=l && r<=y){
        if (ismax) return ST[idx].se;
        else return ST[idx].fi;
    }
    int mid = (l+r)/2;
    if (ismax) return max(Query(idx*2,l,mid,x,y,ismax),Query(idx*2+1,mid+1,r,x,y,ismax));
    else return min(Query(idx*2,l,mid,x,y,ismax),Query(idx*2+1,mid+1,r,x,y,ismax));
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        last[i] = 0;
    }
    for (int i=1; i<=n; i++){
        vis[i] = false;
        cin >> a[i];
        spos[a[i]].push_back(i);
        last[a[i]] = i;
    }
    for (int i=1; i<=n; i++){
        if (last[i]){
            pq.push({last[i],i});
        }
    }
    BuildST(1,1,n);
//    cout << "meow" << endl;
    vector<int> ans;
    int cnt = 1;
    int last = 0;
    while (!pq.empty()){
        int ver = (cnt%2==1)? true:false;
        int pos = pq.top().fi;
        int idx = pq.top().se;

//        cout << pos << " " << idx << endl;

        if (vis[idx]){
            pq.pop();
            continue;
        }

        pii in = Query(1,1,n,last+1,pos,ver);
        int pos2 = in.se;
        int idx2 = in.fi;

        if (ver) pos2 = -pos2;

        ans.push_back(idx2);
        for (auto ps:spos[idx2]){
            Update(1,1,n,ps);
        }
        spos[idx2].clear();
        ++cnt;
        vis[idx2] = true;
        if (pos2 == pos) pq.pop();
        last = pos2;
    }
    cout << ans.size() << endl;
    for (auto x:ans){
        cout << x << " ";
    }
    cout << endl;
    while (!pq.empty()){
        pq.pop();
    }
    ans.clear();
    for (int i=1; i<=n; i++){
        spos[i].clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}

