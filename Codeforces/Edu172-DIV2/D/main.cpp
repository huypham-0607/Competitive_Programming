/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
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
bool dup[N];
int la[N],ra[N],lans[N],rans[N];
vector<int> nen;
int cnt[N*2];
vector<piii> query;
map<pii,int> mp;

//SEGG

struct SegmentTree{
    vector<int> ST;

    SegmentTree(int n){
        ST.resize(n*4+10);
    }

    void Update(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx] = val;
            return;
        }

        int mid = (l+r)/2;

        Update(idx*2,l,mid,x,val);
        Update(idx*2+1,mid+1,r,x,val);
        ST[idx] = max(ST[idx*2],ST[idx*2+1]);
    }

    int Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return 0;
        if (x<=l && r<=y) return ST[idx];
        int mid = (l+r)/2;
        return max(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
    }
};

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        la[i] = x;
        ra[i] = y;
        if (mp.count(make_pair(x,y))){
            dup[i] = true;
            dup[mp[make_pair(x,y)]] = true;
        }
        else{
            mp[make_pair(x,y)] = i;
            nen.push_back(x);
            nen.push_back(y);
            query.push_back({{y,1},{-x,i}});
            query.push_back({{x,0},{y,i}});
        }
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());

    for (int i=0; i<n; i++){
        int val;
        val = lower_bound(all(nen),query[i].fi.fi) - nen.begin()+1;
//        cnt[val]++;
        query[i].fi.fi = val;
        val = lower_bound(all(nen),-query[i].se.fi) - nen.begin()+1;
//        cnt[val]++;
        query[i].fi.se = -val;
    }

    sort(all(query),greater<piii>());

    SegmentTree ST(n);

    int idx = 0;
    int previd = INF;
    for (int i=(int)nen.size(); i>0; i--){
        int cnt = 0;
//        int tmpidx = idx;
//        while (tmpidx!=(int)query.size() && query[tmpidx].fi.fi==i){
//            ++cnt[query[tmpidx].fi.se];
//            ST.Update(1,1,(int)nen.size(),query[tmpidx].fi.se,query[tmpidx].fi.se);
//            ++tmpidx;
//        }

//        if (tmpidx-idx>1) previd = i;
//        int luuidx = idx;

        while (idx!=(int)query.size() && query[idx].fi.fi==i){
            ++cnt;
            if (cnt>1) previd = i;
            rans[query[idx].se] = previd;
            lans[query[idx].se] = ST.Get(1,1,(int)nen.size(),1,-query[idx].fi.se);
            ST.Update(1,1,(int)nen.size(),-query[idx].fi.se,-query[idx].fi.se);
//            if (cnt[query[idx].fi.se]>1) lans[query[idx].se] = query[idx].fi.se;
            ++idx;
        }
        if (cnt==1) previd = i;
//        if (tmpidx-luuidx==1) previd = i;
    }
    for (int i=1; i<=n; i++){
        cout << lans[i] << " " << rans[i] << endl;
        if (dup[i]) cout << 0 << endl;
        else if (lans[i] == 0 || rans[i] == INF) cout << 0 << endl;
        else cout << (la[i]-nen[lans[i]-1]) + (nen[rans[i]-1]-ra[i]) << endl;
    }
    for (int i=1; i<=n; i++){
        la[i] = ra[i] = lans[i] = rans[i] = 0;
        dup[i] = false;
    }
    for (int i=1; i<=(int)nen.size(); i++){
        cnt[i] = 0;
    }
    query.clear();
    nen.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
