/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
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
vector<pii> query;
vector<int> nen;
pii lmao;

struct Fenwick{
    int n;
    vector<int> BIT;

    void Init(int _n){
        BIT.clear();
        n = _n;
        BIT.resize(n+10);
    }

    void Reset(){
        for (int i=1; i<=n; i++){
            BIT[i] = 0;
        }
    }

    void Update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int GetPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int Get(int l, int r){
        return GetPoint(r)-GetPoint(l-1);
    }

} BITup, BITdown;

bool Check(int mid, int n){
//    cout << mid << endl;
    BITup.Reset();
    BITdown.Reset();
    int lup = (int)nen.size()+1, rup = 0;
    int ldown = 0, rdown = (int)nen.size()+1;

    for (auto in:query){
        BITdown.Update(in.se,1);
    }

    while (ldown<=n && BITdown.Get(1,ldown)<mid) ++ldown;
    while (rdown>0 && BITdown.Get(rdown,n)<mid) --rdown;

    int idx = 0;
    for (int i=(int)nen.size(); i>0 ; i--){
        while (idx!=(int)query.size() && query[idx].fi == i){
            int x = query[idx].se;
            BITdown.Update(x,-1);
            BITup.Update(x,+1);
            ++idx;
        }

        while (lup>0 && BITup.Get(1,lup-1)>=mid) --lup;
        while (rup<=n && BITup.Get(rup+1,n)>=mid) ++rup;
        while (ldown<=n && BITdown.Get(1,ldown)<mid) ++ldown;
        while (rdown>0 && BITdown.Get(rdown,n)<mid) --rdown;

//        cout << i << " " << lup << " " << rup << " " << ldown << " " << rdown << endl;

        if (max(lup+1,ldown+1)<=min(rup,rdown)){
            lmao.se = i;
            lmao.fi = min(rup,rdown);
            return true;
        }
    }
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        nen.push_back(x);
        nen.push_back(y);
        query.push_back({y,x});
    }
    sort(nen.begin(),nen.end());
    nen.resize(unique(all(nen))-nen.begin());

    for (int idx=0; idx<n; idx++){
        query[idx].fi = lower_bound(all(nen),query[idx].fi) - nen.begin()+1;
        query[idx].se = lower_bound(all(nen),query[idx].se) - nen.begin()+1;
    }

    sort(all(query),greater<pii>());

    BITup.Init((int)nen.size());
    BITdown.Init((int)nen.size());

    int ans = 0;
    pii coordans = {0,0};
    int l = 1, r = n;
    while (l<=r){
        int mid = (l+r)/2;
        if (Check(mid,(int)nen.size())){
            ans = mid;
            coordans = lmao;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << endl;
    if (ans == 0) cout << 0 << " " << 0 << endl;
    else cout << nen[coordans.fi-1] << " " << nen[coordans.se-1] << endl;
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
