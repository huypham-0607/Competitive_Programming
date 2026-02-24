/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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

const int N = 1e2;
const int LG = 7;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;

int dp[LG+1][N+1];
vector<pii> stage[N+1];
vector<int> pref[N+1];
int phi[N+1];
int pphi[N+1];

void calc_phi() {
    iota(phi,phi+N+1,0);
    for (int i=2; i<=N; i++){
        if (phi[i] == i) {
            for (int j=i; j<=N; j+=i) phi[j] -= phi[j]/i;
        }
    }
}

int get_cost(int x, int n) {
    int pos = stage[n].size()-1;
    int l = 0, r = stage[n].size()-1;

    while (l<=r) {
        int mid = (l+r)/2;
        if (stage[n][mid].fi >= x) {
            pos = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    int res = ((pos == stage[n].size()-1) ? 0 : pref[n][pos+1]);
    res += (stage[n][pos].fi-x+1)*pphi[stage[n][pos].se];
    return res;
}

void DnC(int k, int l, int r, int optl, int optr) {
    if (l>r) return;

    int mid = (l+r)/2;

    int opt = 0;
    dp[k][mid] = LLINF;
    for (int i=optl; i<=min(mid,optr); i++){
        int val = dp[k-1][i-1] + get_cost(i,mid);
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
        pphi[i] = phi[i] + pphi[i-1];
    }

    // for (int i=1; i<=20; i++){
    //     cout << phi[i] << " ";
    // }
    // cout << endl;

    int total_size  = 0;
    for (int i=1; i<=n; i++){
        for (int d=1; d*d<=i; d++) {
            int j = i/d;
            if (j*j<=i) break;
            stage[i].push_back({j,d});
        }

        int aux = stage[i].size();
        // if (i <= 6) cout << aux << endl;
        for (int j=1; j*j<=i; j++){
            int d = i/j;
            stage[i].push_back({j,d});
        }
        reverse(stage[i].begin() + aux, stage[i].end());
        reverse(stage[i].begin(), stage[i].end());
        total_size += stage[i].size();
        pref[i].resize(stage[i].size());
        pref[i][0] = stage[i][0].fi*pphi[stage[i][0].se];
        for (int idx=1; idx<stage[i].size(); idx++) {
            // Change this to prefix sum of phi
            pref[i][idx] = (stage[i][idx].fi-stage[i][idx-1].fi)*pphi[stage[i][idx].se];
        }
        for (int idx = stage[i].size()-2; idx>=0; idx--){
            pref[i][idx] += pref[i][idx+1];
        }
    }

    // for (int i=1; i<=6; i++){
    //     for (auto [j,d]:stage[i]) {
    //         cout << j << "/" << d << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i=1; i<=6; i++){
    //     for (auto x:pref[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

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

    for (int k=1; k<=6; k++) {
        for (int i=1; i<=6; i++){
            cout << dp[k][i] << " ";
        }
        cout << endl;
    }
    for (int i=1; i<=6; i++) {
        for (int j=0; j<stage[i].size(); j++) {
            cout << stage[i][j].fi << "|" << stage[i][j].se << " ";
        }
        cout << endl;
    }
    
    for (int i=1; i<=q; i++){
        int m,k; cin >> m >> k;
        if (k>LG) {
            cout << 0 << endl;
            continue;
        }
        int ans = LLINF;
        for (int i=1; i<=k; i++){
            ans = min(ans,dp[i][m]);
        }
        cout << ans << endl;
    }
}

/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".ans","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}