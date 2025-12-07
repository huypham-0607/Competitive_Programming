/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
//#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LG = 20;
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
int n;
ll ways[(1<<LG)+10];
int a[21],b[21];
ll fac[21];

/*Solution*/
void solve(){
    fac[0] = 1;
    for (int i=1; i<=20; i++){
        fac[i] = fac[i-1]*i;
    }
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    for (int mask=1; mask<(1<<n); mask++){
        int pos = -1;
        int cnt = 0;
        ways[mask] = 1;
        for (int idx=0; idx<n; idx++){
            if ((1<<idx)&mask){
                while (pos+1<n && a[pos+1]>b[idx]) ++pos;
                ways[mask] = ways[mask]*max(pos-cnt+1,0);
                ++cnt;
            }
        }
        ways[mask] = ways[mask]*fac[n-cnt];
    }

    ll ans = 1;
    for (int i=1; i<=n; i++){
        ans = ans*i;
    }
//    cout << ans << endl;
//
//    for (int i=1; i<(1<<n); i++){
//        cout << ways[i] << " ";
//    }
//    cout << endl;

    for (int mask=1; mask<(1<<n); mask++){
        int cnt = __builtin_popcount(mask);
        if (cnt%2) ans-=ways[mask];
        else ans+=ways[mask];
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
