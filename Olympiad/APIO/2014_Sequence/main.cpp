/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define ld long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int n,k;
int a[N],pre[N];
int dp[N],predp[N];
signed trace[201][N];

struct Line{
    ll m,n;

    Line (ll _m=0, ll _n=0): m(_m), n(_n){};

    ll operator()(ll x) const{return m*x+n;}

    bool operator== (Line line) const {return (m==line.m);}

    friend ld intersect(Line a, Line b) {return (ld)(b.n-a.n)/(ld)(a.m-b.m);};
};

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1] + a[i];
    }

    deque<pair<Line,int>> dq;

//    cout << 1/0 << endl;

    for (int j=1; j<=k; j++){
        swap(dp,predp);
        dq.clear();
        dq.push_back({Line(pre[j-1],predp[j-1]-pre[j-1]*pre[j-1]),j-1});
        for (int i=j; i<=n; i++){
            while (dq.size() > 1 && intersect(dq[0].fi,dq[1].fi) < pre[i]) dq.pop_front();
//            cout << i << " " << j << " " << dq.size() << endl;
            dp[i] = dq[0].fi(pre[i]);
            trace[j][i] = dq[0].se;
            Line line(pre[i],predp[i]-pre[i]*pre[i]);
            if (j>1){
                if (!(dq[dq.size()-1].fi == line) || dq[dq.size()-1].fi.n <= line.n){
                    if (dq[dq.size()-1].fi == line){
                        dq.pop_back();
                    }
//                    cout << dq[dq.size()-1].fi.m << " " << dq[dq.size()-1].fi.n << " " << line.m << " " << line.n << endl;
                    while (dq.size() > 1 &&
                           (intersect(dq[dq.size()-1].fi,dq[dq.size()-2].fi) > intersect(dq[dq.size()-1].fi,line))){
                        dq.pop_back();
//                        cout << dq[dq.size()-1].fi.m << " " << dq[dq.size()-1].fi.n << " " << line.m << " " << line.n << endl;

                    }
                    dq.push_back({line,i});
                }
            }
        }
    }
    ll ans = -1;
    int pos = 0;
    for (int i=k; i<n; i++){
        if (ans < dp[i] + (pre[n] - pre[i])*pre[i]){
            ans = max(ans,dp[i] + (pre[n] - pre[i])*pre[i]);
            pos = i;
        }
    }
    cout << ans << endl;
    for (int i=k; i>0; i--){
        cout << pos << " ";
        pos = trace[i][pos];
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("sequence.in","r",stdin);
//    freopen("sequence.out","w",stdout);

    TestCases(0);

    return 0;
}
