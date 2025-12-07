/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e4;
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
int n,MD;
vector<int> dp1,dp2;
vector<int> prime;

void Sieve(){
    bitset<N+10> bs;
    bs.set();
    bs[0] = bs[1] = 1;
    for (int i=2; i*i<=N; i++){
        if (bs[i]) for (int j=i*i; j<=N; j+=i){
            bs[j] = 0;
        }
    }
    for (int i=2; i<=N; i++){
        if (bs[i]) prime.push_back(i);
    }
}

/*Solution*/
void solve(){
    Sieve();
    cin >> n >> MD;
    dp1.resize(n+10);
    dp2.resize(n+10);
    dp1[0] = 1;
    for (auto p:prime){
        for (int i=0; i<=n; i++){
            dp2[i] = dp1[i];
        }
//        cout << p << endl;
        int x = p;
        while (x<=n){
            for (int i=x; i<=n; i++){
                dp2[i] = (dp2[i]+((ll)dp1[i-x]*x)%MD)%MD;
            }
            x*=p;
        }
        swap(dp1,dp2);
    }
    int ans = 0;
    for (int i=0; i<=n; i++){
        ans = (ans+dp1[i])%MD;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
