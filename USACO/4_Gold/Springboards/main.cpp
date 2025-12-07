/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 4e5+10;
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
int e,n;
vector<int> cmp;
int sve[N];
int sus[N];
vector<piiii> query;
int luue;

//SEGGS
int ST[4*N];

void Update(int idx, int l, int r, int x, int val){
//    cout << idx << endl;
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = max(ST[idx],val);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val);
    Update(idx*2+1,mid+1,r,x,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int Get(int idx, int l, int r, int x, int y){
//    cout << idx << endl;
    if (y<l || r<x) return 0;
    if (x<=l && r<=y){
        return ST[idx];
    }
    int mid = (l+r)/2;
    return max(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> e >> n;
    luue = e;
    cmp.push_back(e);
    cmp.push_back(0);
    for (int i=1; i<=n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cmp.push_back(x1);
        cmp.push_back(x2);
        cmp.push_back(y1);
        cmp.push_back(y2);
        sus[i] = x2-x1+y2-y1;
        query.push_back({{y1,x1},{1,i}});
        query.push_back({{y2,x2},{0,i}});
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp)) - cmp.begin());
    e = lower_bound(all(cmp),e) - cmp.begin();
    for (int i=0; i<n*2; i++){
        query[i].fi.fi = lower_bound(all(cmp),query[i].fi.fi) - cmp.begin();
        query[i].fi.se = lower_bound(all(cmp),query[i].fi.se) - cmp.begin();
//        query[i].se.fi = lower_bound(all(cmp),query[i].se.fi) - cmp.begin();
//        query[i].se.se = lower_bound(all(cmp),query[i].se.se) - cmp.begin();
    }
//    for (auto x:cmp){
//        cout << x << " ";
//    }
//    cout << endl;
//    cout << e << " " << endl;
    sort(query.begin(),query.end());
    n = cmp.size();
    int idx = 0;
    int m = query.size();
    int res = 0;
    for (int i=0; i<n; i++){
        while (idx<m && query[idx].fi.fi == i){
            int y = query[idx].fi.fi;
            int x = query[idx].fi.se;
            int ver = query[idx].se.fi;
            int id = query[idx].se.se;
            ++idx;

//            cout << id << " " << x << " " << y << " " << ver << " " << id << " " << sve[id] << endl;

            if (!ver){
                Update(1,0,n-1,x,sve[id]+sus[id]);
            }
            else{
                sve[id] = Get(1,0,n-1,0,x);
            }
        }
//        for (int i=0; i<n; i++){
//            cout << Get(1,0,n-1,i,i) << " ";
//        }
//        cout << endl;
        if (i==e){
            res = luue+luue-Get(1,0,n-1,0,e);
        }
    }
    cout << res << endl;

}

/*Driver Code*/
signed main(){
    freopen("boards.in","r",stdin);
    freopen("boards.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
