/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int LG = 30;
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
int n,q;
int a[N];
int cnt[30];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        for (int idx=0; idx<LG; idx++){
            int val = ((a[i]>>idx)&1);
            if (val) ++cnt[idx];
        }
    }
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        if (x==1){
            int p,v; cin >> p >> v;
            for (int idx=0; idx<LG; idx++){
                int val = ((a[p]>>idx)&1);
                if (val) --cnt[idx];
            }
            a[p] = v;
            for (int idx=0; idx<LG; idx++){
                int val = ((a[p]>>idx)&1);
                if (val) ++cnt[idx];
            }
        }
        else {
            int res = 0;
            for (int idx=0; idx<LG; idx++){
                if (cnt[idx]) res+=(1<<idx);
            }
            cout << res << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    freopen("TRUYVANOR.inp","r",stdin);
    freopen("TRUYVANOR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

