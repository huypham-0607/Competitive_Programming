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
const int MX = 60000+10;
const int N = 6e4;
const int M = 6e4;
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
int n,m,q;

//SEGGS
int ST[4*MX];
int lazy[4*MX];

void Propagate(int idx){
    int idx2 = idx*2;
    ST[idx2]+=lazy[idx];
    lazy[idx2]+=lazy[idx];
    idx2+=1;
    ST[idx2]+=lazy[idx];
    lazy[idx2]+=lazy[idx];
    lazy[idx] = 0;
}

void UpdateST(int idx, int l, int r, int x, int y, int val){
    if (y<l || r<x) return;
    if (x<=l && r<=y){
        ST[idx]+=val;
        lazy[idx]+=val;
        return;
    }
    Propagate(idx);
    int mid = (l+r)/2;
    UpdateST(idx*2,l,mid,x,y,val); UpdateST(idx*2+1,mid+1,r,x,y,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int QueryST(int idx, int l, int r, int x, int y){
    if (y<l || r<x) return 0;
    if (x<=l && r<=y){
        return ST[idx];
    }
    Propagate(idx);
    int mid = (l+r)/2;
    return max(QueryST(idx*2,l,mid,x,y),QueryST(idx*2+1,mid+1,r,x,y));
}

void Update(int l,int val){
    UpdateST(1,0,M,l,M,val);
    if (l+m<=M) UpdateST(1,0,M,l+m,M,-val);
}

int Query(){
    return QueryST(1,0,M,0,M);
}

/*Solution*/
void solve(){
    cin >> m >> n;
    m++; n++;
    cin >> q;
    vector<pii> v;
    int ans = 0;
    for (int i=1; i<=q; i++){
        int x, y;
        cin >> x >> y;
        x+=30000; y+=30000;
        v.push_back({y,x});
    }
    v.push_back({INF,INF});
    sort(v.begin(),v.end());
    int l = 0, r = 0;
    for (int i=0; i<=N; i++){
        while (v[r].fi <= i){
            Update(v[r].se,1);
            ++r;
        }
        while (v[l].fi <= i-n){
            Update(v[l].se,-1);
            l++;
        }
        if (i-n+1>=0){
            ans = max(ans,Query());
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("GOLD.INP","r",stdin);
    freopen("GOLD.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
