/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e6+10;
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
int n,q;
deque<pii> dq;
int a[N];
vector<piii> query;
pair<pii,int> info[N];
int ans[N];

//SEGGS

int ST[4*N];

void Update(int idx, int l, int r, int x, int val){
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = max(ST[idx],val);
        return;
    }

    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int Get(int idx, int l, int r, int x, int y){
    if (y<l || r<x) return 0;
    if (x<=l&&r<=y) return ST[idx];
    int mid = (l+r)/2;
    return max(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        query.push_back({{i,1},a[i]});
    }
//    for (int i=1; i<=n; i++){
//        cout << a[i] << endl;
//    }
    for (int i=1; i<=q; i++){
        int l,r,w; cin >> l >> r >> w;
        info[i] = {{l,r},w};
        query.push_back({{l,0},i});
    }
    sort(all(query),greater<piii>());
    int idx = 0;
    for (int i=n; i>0; i--){
        while (idx!=(int)query.size() && query[idx].fi.fi == i){
            int ver = query[idx].fi.se;
            int l = query[idx].fi.fi;
//            cout << l << " " << ver << endl;
            if (!ver){
                int id = query[idx].se;
                int r = info[id].fi.se;
                int val = info[id].se;
                int mx = Get(1,1,n,l,r);
                if (mx > val) ans[id] = 0;
                else ans[id] = 1;
            }
            else{
                int val = query[idx].se;
                while (!dq.empty() && dq.back().fi<val){
                    Update(1,1,n,dq.back().se,val+dq.back().fi);
//                    cout << "back: " << dq.back().fi << " " << dq.back().se << endl;
                    dq.pop_back();
                }
//                cout << "val: " << val << " " << l << endl;
                dq.push_back({val,l});
            }
            ++idx;
        }
//        for (int i=1; i<=n; i++){
//            cout << Get(1,1,n,i,i) << " ";
//        }
//        cout << endl;
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
