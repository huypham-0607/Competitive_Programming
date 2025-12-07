/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define double long double
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 16;
const int INF = 1e9+7;
const double EP = 1e-9;
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
pair<int,int> pos[N];
int t[N];
double dp[N][(1<<16)+10];
//double v[N][(1<<15)+10];
double power[N];

double GetDist(pii a, pii b){
    return sqrtl((b.fi-a.fi)*(b.fi-a.fi)+(b.se-a.se)*(b.se-a.se));
}

bool Check(double x){
    for (int i=0; i<n; i++){
        for (int mask=0; mask<(1<<n); mask++){
            dp[i][mask] = LLINF;
        }
    }

	for (int i = 0; i < n; ++i) {
		double time = GetDist(make_pair(0,0), pos[i]) / x;
		if (time <= t[i]) {dp[i][1<<i] = time;}
	}

    for (int mask=1; mask<(1<<n); mask++){
        int cnt = __builtin_popcount(mask);
        for (int i=0; i<n; i++){
            if (!(mask&(1<<i))) continue;
            pre = (mask^(1<<i));
            for (int j=0; j<n; j++){
                if (!(pre&(1<<j))) continue;
                if (dp[j][pre] == LLINF) continue;
                double tmp = dp[j][pre]+(GetDist(pos[j],pos[i])/(x*power[cnt-1]));

                if (tmp<=t[i] && dp[i][mask]>tmp){
                    dp[i][mask] = tmp;
                }
            }
        }
    }
//    for (int i=0; i<n; i++){
//        cout << i << " " << dp[i][(1<<n)-1] << endl;
//    }
    for (int i=0; i<n; i++){
        if (dp[i][(1<<n)-1]!=LLINF) return true;
    }
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> pos[i].fi >> pos[i].se >> t[i];
    }
    char tmp; cin >> tmp;
    double mul; cin >> mul;
    mul = mul/(double)100;
    power[0] = (double)1;
    for (int i=1; i<=n; i++){
        power[i] = power[i-1]*mul;
    }

//    double ans = INF+EP;
    double l = 0, r = 1e12;
    for(int i=1; i<=150; i++){
        double mid = (l+r)/2;
        if (Check(mid)){
            r = mid;
        }
        else l = mid;
    }
    cout << fixed << setprecision(16) << l << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
