/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define TEXT "A"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5;
const int LG = 18;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e12+3;

//Starts here

int n,q;

ll dp[LG+1][N+2];
vector<int2> stage[N+2];
vector<int2> dcnt[N+2];
vector<ll> pref[N+2];
int phi[N+2];
ll pphi[N+2];

void calc_phi() {
    iota(phi,phi+N+1,0);
    for (int i=2; i<=N; i++){
        if (phi[i] == i) {
            for (int j=i; j<=N; j+=i) phi[j] -= phi[j]/i;
        }
    }
}

ll get_cost(int x, int n) {
    int pos = stage[n].size()-1;
    int l = 0, r = stage[n].size()-1;

    while (l<=r) {
        int mid = (l+r)/2;
        if (stage[n][mid] >= x) {
            pos = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    ll res = ((pos == stage[n].size()-1) ? 0 : pref[n][pos+1]);
    res += 1LL*(stage[n][pos]-x+1)*pphi[dcnt[n][pos]];
    return res;
}

void DnC(int k, int l, int r, int optl, int optr) {
    if (l>r) return;

    int mid = (l+r)/2;

    int opt = 0;
    dp[k][mid] = LLINF;
    for (int i=optl; i<=min(mid,optr); i++){
        ll val = dp[k-1][i-1] + get_cost(i,mid);
        if (val < dp[k][mid]) {
            dp[k][mid] = val;
            opt = i; 
        }
    }

    DnC(k,l,mid-1,optl,opt);
    DnC(k,mid+1,r,opt,optr);
}

void solve(){
    n = N;
    calc_phi();

    for (int i=1; i<=n; i++){
        pphi[i] = 1LL*phi[i] + pphi[i-1];
    }

    // for (int i=1; i<=20; i++){
    //     cout << phi[i] << " ";
    // }
    // cout << endl;

    int total_size  = 0;
    for (int i=1; i<=n; i++){
        int sz = 0;
        int prev = 0;

        int j,d;

        for (j=1; j*j<=i; j++){
            d = i/j;
            stage[i].push_back(j);
            dcnt[i].push_back(d);
        }

        // cerr << j << " " << d << endl;
        for (d=i/j; d>0; d--) {
            j = i/d;
            if (j*j<=i) continue;
            stage[i].push_back(j);
            dcnt[i].push_back(d);
        }

        pref[i].resize(stage[i].size(),0);
        // total_size += stage[i].size();
        pref[i][0] = 1LL*stage[i][0]*pphi[dcnt[i][0]];
        for (int idx=1; idx<stage[i].size(); idx++) {
            // Change this to prefix sum of phi
            pref[i][idx] = 1LL*(stage[i][idx]-stage[i][idx-1])*pphi[dcnt[i][idx]];
        }
        for (int idx = stage[i].size()-2; idx>=0; idx--){
            pref[i][idx] += pref[i][idx+1];
        }
    }

    // cout << total_size << endl;
    dp[0][0] = 0;
    for (int i=1; i<=n; i++){
        dp[0][i] = LLINF;
    }
    for (int k=1; k<=LG; k++){
        dp[k][0] = LLINF;
        DnC(k,1,n,1,n);
    }

    cin >> q;

    // for (int k=1; k<=6; k++) {
    //     for (int i=1; i<=6; i++){
    //         cout << dp[k][i] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i=1; i<=6; i++) {
    //     for (int j=0; j<stage[i].size(); j++) {
    //         cout << stage[i][j] << "|" << dcnt[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int lg=1; lg<=LG; lg++){
    //     for (int i=1; i<=n; i++){
    //         if (dp[lg][i] == 0) {
    //             cout << lg << " " << i << endl;
    //         }
    //     }
    // }
    for (int i=1; i<=q; i++){
        int m,k; cin >> m >> k;
        if (k>LG) {
            cout << m << endl;
            continue;
        }
        ll ans = LLINF;
        for (int i=1; i<=k; i++){
            if (i>m) break;
            ans = min(ans,dp[i][m]);
        }
        cout << ans << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

