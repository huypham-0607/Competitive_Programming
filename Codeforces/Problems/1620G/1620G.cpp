/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
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

const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 23;
const int MD = 998244353; //998244353;
const long long LLINF = 1e18+3;

//Starts here
int mx[26];
int cap[26][(1<<LG)+10];
int SOS[(1<<LG)+10];
int a[(1<<LG)+10];

int n;

void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        string s; cin >> s;
        int cur = -1;
        int val = 0;
        for (int idx=0; idx<s.size(); idx++){
            int id = s[idx]-'a';
            if (cur!=id) {
                if (cur!=-1) cap[cur][(1<<i)] = val;
                cur = id;
                val = 1;
            }
            else {
                ++val;
            }
        }
        if (val) {
            // cout << cur << endl;
            cap[cur][(1<<i)] = val;
        }
    }

    // for (int i=0; i<n; i++){
    //     for (int idx=0; idx<3; idx++){
    //         cout << cap[idx][(1<<i)] << " ";
    //     }
    //     cout << endl;
    // }

    for (int mask=1; mask<(1<<n); mask++){
        int cnt = __builtin_popcount(mask);
        if (cnt>1){
            int pos = 31-__builtin_clz(mask);
            for (int idx=0; idx<26; idx++){
                cap[idx][mask] = min(cap[idx][mask^(1<<pos)],cap[idx][(1<<pos)]);
            }
        }

        SOS[mask] = 1;
        for (int idx=0; idx<26; idx++){
            SOS[mask] = (1LL*SOS[mask]*(cap[idx][mask]+1))%MD;
        }
        // cout << mask << " " << SOS[mask] << endl;
    }

    for (int lg=0; lg<n; lg++){
        for (int mask=1; mask<(1<<n);mask++){
            if (!(mask&(1<<lg))) SOS[mask] = (1LL*SOS[mask]-SOS[mask^(1<<lg)]+MD)%MD;
        }
    }

    for (int lg=0; lg<n; lg++){
        for (int mask=1; mask<(1<<n); mask++){
            if (mask&(1<<lg)) SOS[mask] = (1LL*SOS[mask]+SOS[mask^(1<<lg)])%MD;
        }
    }

    // cout << "End SOS" << endl;

    // for (int mask=0; mask<(1<<n); mask++){
    //     cout << mask << " " << SOS[mask] << endl;
    // }

    // cout << "Calc" << endl;

    ll ans = 0;
    for (int mask=0; mask<(1<<n);mask++){
        ll res = (1LL*SOS[(1<<n)-1]-SOS[mask^((1<<n)-1)]+MD)%MD;
        // cout << mask << " " << res << endl;
        ll tmp = 0;
        for (int i=0; i<n; i++){
            if (mask&(1<<i)) tmp = (tmp+(i+1))%MD;
        }
        tmp = tmp*__builtin_popcount(mask)%MD;
        res = res*tmp;
        ans = ans^res;
    }
    cout << ans << endl;
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

