/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
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
int n,m,k,d;
vector<vector<int>> a;
vector<long long> v;

/*Solution*/
void solve(){
    cin >> n >> m >> k >> d;
//    d+=1;
    a.clear();
    a.resize(n+1,vector<int>(m+1));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
//            a[i][j] += 1;
        }
    }

    v.clear();
    v.resize(n+1,0);

    deque<pair<long long,int>> dq;
//    dp.resize(n+1,vector<int>(m+1));
    for (int i=1; i<=n; i++){
        dq.clear();
        dq.push_back({a[i][1],1});
        for (int j=2; j<=m; j++){
            while (!dq.empty() && dq.front().se < j-d) dq.pop_front();

            long long val = dq.front().fi + a[i][j];
            if (j==m) v[i] = val;

            while (!dq.empty() && dq.back().fi > val) dq.pop_back();
            dq.push_back({val,j});
        }
    }

    long long ans = LLINF;
    long long t = 0;
    dq.clear();
    for (int i=1; i<=n; i++){
        while (!dq.empty() && dq.front().se <= i-k) dq.pop_front();
        while (!dq.empty() && dq.back().fi < v[i]) dq.pop_back();
        dq.push_back({v[i],i});

        if (i > k) t -= v[i-k];
        t+=v[i];
        if (i >= k) ans = min(ans,t-dq.front().fi);
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    freopen("XAYCAU.inp","r",stdin);
//    freopen("XAYCAU.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

