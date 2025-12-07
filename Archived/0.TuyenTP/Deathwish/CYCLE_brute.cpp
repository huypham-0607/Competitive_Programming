/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CYCLE"

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
int n,m,k;
vector<int> cstp, cstq;
vector<int> p,q;

/*Solution*/
void solve(){
    p.clear();
    q.clear();
    cstp.clear();
    cstq.clear();
    cin >> n >> m >> k;
    cstp.resize(n,INF);
    cstq.resize(n,INF);
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        --x;
        p.push_back(x);
    }
    for (int i=1; i<=k; i++){
        int x; cin >> x;
        --x;
        q.push_back(x);
    }
    sort(all(p));
    sort(all(q));
    for (int tmp=0; tmp<n; tmp++){
        for (int idx=0; idx<m; idx++){
            int cur = 0;
            for (int delta=0; delta<m; delta++){
                int i = p[(idx+delta)%m];
                int pos = tmp+delta;
                int dist = min({abs(i-pos),abs(i-(pos+n)),abs((i+n)-pos)});
                cur+=dist;
            }
            cstp[tmp] = min(cstp[tmp],cur);
        }
    }
    for (int tmp=0; tmp<n; tmp++){
        for (int idx=0; idx<k; idx++){
            int cur = 0;
            for (int delta=0; delta<k; delta++){
                int i = q[(idx+delta)%k];
                int pos = tmp+delta;
                int dist = min({abs(i-pos),abs(i-(pos+n)),abs((i+n)-pos)});
                cur+=dist;
            }
            cstq[tmp] = min(cstq[tmp],cur);
        }
    }
    int ans = INF;
    for (int i=0; i<n; i++){
        for (int idx=i+m; idx<i+m+n; idx++){
            int j = idx%n;
            if ((j+k)%n > i) break;
            else ans = min(ans,cstp[i] + cstq[j]);
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}

