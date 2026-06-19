#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

const int MXP = 5e5;

vector<int> primes;

void Sieve(){
    bitset<MXP+1> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=MXP; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=MXP; j+=i){
            bs[j]=0;
        }
    }

    for (int i=1; i<=MXP; i++){
        if (bs[i]) primes.push_back(i);
    }
}

int n,k;
int a[(int)1e5+10];
vector<int> lst[N];
vector<vector<vector<ll>>> dpl((int)1e5+10,vector<vector<ll>>(19,vector<ll>(19,0)));
vector<vector<vector<ll>>> dpr((int)2,vector<vector<ll>>(19,vector<ll>(19,0)));
set<int> st;
map<int,int>mp;

ll getVal(int i1, int j1, int i2, int j2, vector<vector<ll>>& dp) {
    if (i2<i1 || j2<j1) return 0;
    // cerr << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
    ll val = dp[i2][j2];
    if (i1 != 0) val = (val + MD - dp[i1-1][j2])%MD;
    if (j1 != 0) val = (val + MD - dp[i2][j1-1])%MD;
    if (i1 != 0 && j1!=0) val = (val + dp[i1-1][j1-1])%MD;
    // cerr << "meow" << endl;
    return val;
}

void solve(){
    cin >> n >> k;
    ffor(i,1,n) cin >> a[i];
    int val = k;
    for (int pi=0; pi<primes.size(); pi++){
        int p = primes[pi];
        if (p*p>k) break;
        if (val%p == 0) {
            int cnt = 0;
            while (val%p == 0){
                val=val/p;
                ++cnt;
            }
            mp[p] = cnt;
            st.insert(p);
        }
    }
    if (val != 1) {
        st.insert(val);
        mp[val] = 1;
    }
    for (int i=1; i<=n; i++){
        int x = a[i];
        int val = x;
        for (int pi=0; pi<primes.size(); pi++){
            int p = primes[pi];
            if (p*p>x) break;
            if (val%p == 0) {
                int cnt = 0;
                while (val%p == 0){
                    val=val/p;
                    ++cnt;
                }
                lst[p].push_back(cnt);
                st.insert(p);
            }
        }
        if (val != 1) {
            st.insert(val);
            lst[val].push_back(1);
        }
    }
    // if (k == 262144) {
    //     cout << st.size() << endl;
    //     for (auto x:st) {
    //         int mx = 0;
    //         for (auto val:lst[x]) mx = max(mx,val);
    //         cout << x << " " << mx << endl;
    //     }
    //     return;
    // }


    ll ans = 1;
    for (auto x:st) {
        if (mp.find(x)==mp.end()) {
            int val = 1;
            for (auto cnt:lst[x]) val+=cnt;
            ans = (ans*val)%MD;        
        }
        else{
            if (lst[x].empty()) {
                ans = 0;
                continue;
            }
            ll cum = 0;
            int m = mp[x];
            // cerr << x << " " << lst[x].size() << endl;
            ffor(i,0,m) {
                ffor(j,0,m) {
                    dpl[0][i][j] = 1;
                    dpr[0][i][j] = 1;
                }
            }
            int mx = 0;
            for (auto val:lst[x]) mx = max(mx,val);

            for (int i=1; i<=lst[x].size(); i++){
                ffor(u,0,m) dpl[i][u][0] = dpl[i-1][u][0];
                ffor(v,0,m) dpl[i][0][v] = dpl[i-1][0][v];
                for (int u=1; u<=m; u++){
                    for (int v=1; v<=m; v++) {
                        int delta = min({u,v,lst[x][i-1]});
                        dpl[i][u][v] = getVal(u,v-min(u-1,delta),u,v,dpl[i-1]);
                        if (delta == u) dpl[i][u][v] = (dpl[i][u][v] + getVal(0,v-u,u,v-u,dpl[i-1]))%MD;
                        // cout << i << " " << delta << " " << u << " " << v << " " << dpl[i][u][v] << endl;
                        // cout << getVal(0,v-u,u,v-u,dpl[i-1]) << " " << getVal(u,v-min(u-1,delta),u,v,dpl[i-1]) << endl;
                        // cout << dpl[i][u-1][v] << " " << dpl[i][u][v-1] << " " << dpl[i][u-1][v-1] << endl;

                        if (u!=0) dpl[i][u][v] = (dpl[i][u][v] + dpl[i][u-1][v])%MD;
                        if (v!=0) dpl[i][u][v] = (dpl[i][u][v] + dpl[i][u][v-1])%MD;
                        if (u!=0 && v!=0) dpl[i][u][v] = (dpl[i][u][v] - dpl[i][u-1][v-1] + MD)%MD;
                    }
                }
            }

            for (int i=lst[x].size(); i>0; i--){
                // cerr << "i: " << i  << " " << lst[x][i-1] << endl;
                for (int u=1; u<=min({lst[x][i-1]}); u++){
                    for (int v=0; v<=m; v++) {
                        ll l = getVal(0,v,u,v,dpl[i-1]);
                        ll r = getVal(0,m-v,u-1,m-v,dpr[0]);
                        if (u>m) {
                            l = getVal(0,v,m,v,dpl[i-1]);
                            r = getVal(0,m-v,m,m-v,dpr[0]);
                        }
                        // cerr << u << " " << v << " " << l << " " << r << endl;
                        cum = (cum+l*r)%MD;
                    }
                }

                ffor(u,0,m) dpr[1][u][0] = dpr[0][u][0];
                ffor(v,0,m) dpr[1][0][v] = dpr[0][0][v];
                for (int u=1; u<=m; u++){
                    for (int v=1; v<=m; v++) {
                        int delta = min({u,v,lst[x][i-1]});
                        dpr[1][u][v] = getVal(u,v-min(u-1,delta),u,v,dpr[0]);
                        if (delta == u) dpr[1][u][v] = (dpr[1][u][v] + getVal(0,v-u,u,v-u,dpr[0]))%MD;

                        if (u!=0) dpr[1][u][v] = (dpr[1][u][v] + dpr[1][u-1][v])%MD;
                        if (v!=0) dpr[1][u][v] = (dpr[1][u][v] + dpr[1][u][v-1])%MD;
                        if (u!=0 && v!=0) dpr[1][u][v] = (dpr[1][u][v] - dpr[1][u-1][v-1] + MD)%MD;
                    }
                }
                swap(dpr[0],dpr[1]);
            }

            // for (int i=1; i<=n; i++){
            //     ffor(u,0,m) {
            //         ffor(v,0,m) {
            //             cout << dpl[i][u][v] << " ";
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }

            // for (int i=1; i<=n; i++){
            //     ffor(u,0,m) {
            //         ffor(v,0,m) {
            //             cout << dpr[i][u][v] << " ";
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }

            ans = (ans*cum)%MD;
        }
    }
    cout << ans << endl;
    for (auto x:st) {
        lst[x].clear();
    }
    st.clear();
    mp.clear();
}

/*Driver Code*/
signed main(){
    Sieve();
    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

