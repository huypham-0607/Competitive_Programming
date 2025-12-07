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
pair<short,short> dp[1230][N+1];
vector<int> prime;
vector<int> nxt;
vector<int> v;

void Sieve(){
    nxt.resize(N+10);
    bitset<N+10> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    nxt[0] = nxt[1] = 1;
    for (int i=2; i*i<=N; i++){
        if (bs[i]){
            nxt[i]=i;
            for (int j=i*i; j<=N; j+=i){
                bs[j] = 0;
                if (!nxt[j]) nxt[j] = i;
            }
        }
    }
    for (int i=2; i<=N; i++){
        if (bs[i]) prime.push_back(i);
    }
}

/*Solution*/
void precalc(){
    Sieve();
    n = N;
    dp[0][0] = {(short)1,(short)0}
    for (idx=0; idx<(short)prime.size(); idx++){
        short p = prime[idx];
        for (short i=0; i<=n; i++){
            dp[idx][i] = dp[idx-1][i];
        }
//        cout << p << endl;
        short x = p;
        while (x<=n){
            for (short i=x; i<=n; i++){
                if (dp[idx][x].fi < dp[idx-1][i-x].fi)
            }
            x*=p;
        }
        swap(dp1,dp2);
    }
    cout << prime.size() << endl;
}

void solve(){
    cin >> n;
    int ans = 1;
    int pos = 0;
    for (int i=1; i<=n; i++){
        if (dp1[i]>ans){
            ans = dp1[i];
            pos = i;
        }
    }
//    cout << ans << " " << pos << endl;
    int cnt = n-pos;
    for (int i=1; i<=cnt; i++){
        v.push_back(1);
    }
    int rawr = 1;
    while (nxt[ans]!=1){
//        cout << ans << " " << nxt[ans] << endl;
        rawr*=nxt[ans];
        if (nxt[ans]!=nxt[ans/nxt[ans]]){
            v.push_back(rawr);
            cnt+=rawr;
            rawr = 1;
        }
        ans = ans/nxt[ans];
    }
    sort(v.begin(),v.end());
    cnt = 0;
    for (auto x:v){
        for (int i=1; i<x; i++){
            cout << cnt+i+1 << " ";
        }
        cout << cnt+1 << " ";
        cnt+=x;
    }
    cout << endl;
    v.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    TestCases(1);

    return 0;
}
