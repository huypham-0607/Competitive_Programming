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
const int N = 3e5+10;
const long long INF = 1e15+7;
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
vector<int> sector_list[N];
ll sample_req[N];
piii Query[N];
int L[N],R[N],ans[N];
vector<int> check_mid[N];

//struct STLazy{
//    int n;
//    vector<int> ST,lazy;
//
//    STLazy(int _n): n(_n), ST(_n*4+10), lazy(_n*4+10){};
//
//    void RecReset(int idx, int l, int r){
//        if (l==r){
//            ST[idx] = 0;
//            lazy[idx] = 0;
//            return;
//        }
//        int mid = (l+r)/2;
//        RecReset(idx*2,l,mid);
//        RecReset(idx*2+1,mid+1,r);
//        ST[idx] = ST[idx]
//    }
//};

struct FW{
    int n;
    vector<ll> BIT;

    FW(int _n): n(_n), BIT(n+10,0){};

    void Reset(){
        for (int i=1; i<=n; i++){
            BIT[i] = 0;
        }
    }

    void UpdatePoint(int idx, int val){
        while (idx<=n){
            BIT[idx] = min(BIT[idx]+val,(ll)INF);
            idx+=(idx&(-idx));
        }
    }

    void Update(int l, int r, int val){
        UpdatePoint(l,val);
        UpdatePoint(r+1,-val);
    }

    ll Get(int idx){
        ll res = 0;
        while (idx>0){
            res = min(res+BIT[idx],(ll)INF);
            idx-=(idx&(-idx));
        }
        return res;
    }
};

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        sector_list[x].push_back(i);
    }
    for (int i=1; i<=n; i++){
        cin >> sample_req[i];
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int l,r,w;
        cin >> l >> r >> w;
        Query[i] = {{l,r},w};
    }
    FW BIT(m);

    for (int i=1; i<=n; i++){
        L[i] = 1;
        R[i] = q;
    }

    for (int lvl = 0; lvl<22; lvl++){
//        cout << "lvl " << lvl << endl;
        BIT.Reset();
        for (int i=1; i<=n; i++){
            if (L[i]<=R[i]){
                check_mid[(L[i]+R[i])/2].push_back(i);
            }
        }
        for (int i=1; i<=q; i++){
//            cout << i << ": ";
            if (Query[i].fi.fi > Query[i].fi.se){
                BIT.Update(Query[i].fi.fi,m,Query[i].se);
                BIT.Update(1,Query[i].fi.se,Query[i].se);
            }
            else{
                BIT.Update(Query[i].fi.fi,Query[i].fi.se,Query[i].se);
            }
            for (auto idx:check_mid[i]){
                ll cnt = 0;
                for (auto pos:sector_list[idx]){
                    cnt = min(cnt+BIT.Get(pos),(ll)INF);
                }
//                cout << "{" << idx << "," << cnt << "} ";
                if (cnt<sample_req[idx]){
                    ans[idx] = i;
                    L[idx] = i+1;
                }
                else{
                    R[idx] = i-1;
                }
            }
            check_mid[i].clear();
//            cout << endl;
        }
    }

    for (int i=1; i<=n; i++){
        if (ans[i]==q) cout << "NIE" << endl;
        else cout << ans[i]+1 << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
