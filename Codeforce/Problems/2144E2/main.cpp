/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LG = 20;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

int bin_pow(int a, int b){
    int res = 1;
    for (int lg = LG-1; lg>=0; lg--){
        res = (res*res)%MD;
        if ((1<<lg)&b) res = (res*a)%MD;
    }
    return res;
}

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n): n(_n){
        BIT.resize(n+10);
    }

    void updatePoint(int idx, int val){
        ++idx;
        while (idx<=n+1){
            BIT[idx]+=val;
            idx += (idx&(-idx));
        }
    }

    void updateRange(int l, int r, int val){
        updatePoint(l,val);
        updatePoint(r+1,-val);
    }

    int getPoint(int idx){
        ++idx;
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx -= (idx&(-idx));
        }
        return res;
    }
};


void solve(){
    cin >> n;
    vector<int> a(n+10,0);
    vector<int> dpl(n+10,0);
    vector<int> cntl(n+10,0), cntr(n+10,0);
    vector<int> lval,rval;

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    lval.push_back(0);
    rval.push_back(0);
    for (int i=1; i<=n; i++){
        if (lval.empty() || a[i] > lval.back()) lval.push_back(a[i]);
    }
    for (int i=n; i>0; i--){
        if (a[i] == lval.back()) break;
        if (rval.empty() || a[i] > rval.back()) rval.push_back(a[i]);
    }

//    for (auto x:lval) cout << x << " ";
//    cout << endl;
//    for (auto x:rval) cout << x << " ";
//    cout << endl;

    Fenwick lpref(lval.size()), rpref(rval.size());
    int ans = 0;

    cntl[0] = 1;
    for (int i=1; i<=n; i++){
        int idx = lower_bound(all(lval),a[i]) - lval.begin();
//        cout << idx << endl;
        lpref.updateRange(idx,lval.size()-1,1);
        if (a[i] == lval[idx]){
            int cpow = lpref.getPoint(idx);
            lpref.updateRange(idx,idx,-cpow);
            int ppow = lpref.getPoint(idx-1);
            lpref.updateRange(idx-1,idx-1,-ppow);

            if (idx == (int)lval.size()-1){
                dpl[i] = (cntl[idx-1]*bin_pow(2,ppow)%MD + cntl[idx]*bin_pow(2,cpow-1)%MD)%MD;
            }
            cntl[idx] = cntl[idx]*bin_pow(2,cpow)%MD;
            cntl[idx-1] = cntl[idx-1]*bin_pow(2,ppow)%MD;
            cntl[idx] = (cntl[idx] + cntl[idx-1])%MD;
        }
//        dpl[i] = cntl[(int)lval.size()]*bin_pow(2,lpref.getPoint((int)lval.size()))%MD;
//        for (int i=1; i<=; i++){
//            cout <<
//        }
    }
//    cout << endl;
    cntr[0] = 1;
    for (int i=n; i>0; i--){
        int idx = lower_bound(all(rval),a[i]) - rval.begin();
//        cout << idx << endl;
        rpref.updateRange(idx,(int)rval.size()-1,1);
        if (idx!=(int)rval.size() && a[i] == rval[idx]){
            int cpow = rpref.getPoint(idx);
            cntr[idx] = cntr[idx]*bin_pow(2,cpow)%MD;
            rpref.updateRange(idx,idx,-cpow);
            int ppow = rpref.getPoint(idx-1);
            cntr[idx-1] = cntr[idx-1]*bin_pow(2,ppow)%MD;
            rpref.updateRange(idx-1,idx-1,-ppow);
            cntr[idx] = (cntr[idx] + cntr[idx-1])%MD;
        }
        int tmp = cntr[(int)rval.size()-1]*bin_pow(2,rpref.getPoint((int)rval.size()-1))%MD;
        ans = (ans + (tmp*dpl[i-1]%MD))%MD;
    }

    ans = (ans + dpl[n])%MD;

    cout << ans << endl;
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
