/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
int n;
int a[N];
int cnt[N];
int f[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res = 0;
    int lim = 200000;
    for (int i=lim; i>=1; i--){
        int sus = cnt[i];
        for (int j=2; i*j<=lim; j++){
            sus+=cnt[i*j];
        }

        f[i] = (sus*(sus-1))/2;

        for (int j=2; i*j<=lim; j++){
            f[i]-=f[i*j];
        }

        res+=f[i]*i;
    }
    cout << res;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
