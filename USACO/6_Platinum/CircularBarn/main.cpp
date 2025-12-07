/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define ld long double
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1000 + 10;
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
int a[N];
int pre[N],pre2[N];
int dp[8][N];

struct Line{
    ll m,n;

    Line (ll _m=0, ll _n=0): m(_m), n(_n) {};

    ll operator()(ll x) const {return m*x+n;}

    friend ld intersect(Line a, Line b) {return (ld)(b.n-a.n)/(ld)(a.m-b.m);}
};

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=n; i>0; i--){
        cin >> a[i];
    }

    int ans = LLINF+100;

    deque<Line> dq;
    for (int lmeo=1; lmeo<=n; lmeo++){
//        cout << "lmeo " << lmeo << endl;
        for (int i=1; i<=n; i++){
            pre[i] = pre[i-1] + a[i];
            pre2[i] = pre2[i-1] + pre[i];
        }

//        for (int i=1; i<=n; i++){
//            cout << a[i] << " ";
//        }
//        cout << endl;

//        dq.clear();
        for (int j=1; j<=k; j++){
            dq.clear();
            dq.push_back(Line(-pre[j-1],dp[j-1][j-1] - pre2[j-1] + pre[j-1]*(j-1) + pre[j-1]));
//            cout << dq[0].m << " " <<dq[0].n << endl;
            for (int i=j; i<=n; i++){
                while (dq.size()>1 && intersect(dq[0],dq[1])<i) dq.pop_front();
                dp[j][i] = dq.front()(i) + pre2[i-1];
//                cout << j << " " << i << " " << dq.front().m << " " << dq.front().n << " " << dq.size() << endl;

                if (j>1){
                    Line line(-pre[i],dp[j-1][i] - pre2[i] + pre[i]*i + pre[i]);
//                    cout << line.m << " " << line.n << endl;
                    while (dq.size()>1 && intersect(dq[dq.size()-1],dq[dq.size()-2])>intersect(dq[dq.size()-1],line)) dq.pop_back();
                    dq.push_back(line);
                }
            }
//            cout << endl;
        }

//        for (int j=1; j<=k; j++){
//            for (int i=1; i<=n; i++){
//                cout << dp[j][i] << " ";
//            }
//            cout << endl;
//        }

        ans = min(ans,dp[k][n]);

        int tmp = a[1];
        for (int i=2; i<=n; i++){
            a[i-1] = a[i];
        }
        a[n] = tmp;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
