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
int n,m;
int fact[N];
int a[1010][1010];
int cnt[100010];
bitset<100010> bs;

void Sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    fact[0] = fact[1] = 0;
    for (int i=1; i*i<=100000; i++){
        if (bs[i]){
            fact[i] = i;
            for (int j=i*i; j<=100000; j+=i){
                bs[j] = 0;
                if (fact[j]==0) fact[j] = i;
            }
        }
    }
    for (int i=2; i<=100000; i++){
        if (fact[i] == 0){
            fact[i] = i;
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            a[i][j] = cnt[a[i][j]];
            if (i==1 && j==1) continue;
            if (i==1 || j==1){
                if (i==1) a[i][j]+=a[i][j-1];
                else a[i][j]+=a[i-1][j];
            }
            else a[i][j] += min(a[i-1][j],a[i][j-1]);
        }
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << a[n][m] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("BOARDG.inp","r",stdin);
//    freopen("BOARDG.out","w",stdout);

    Sieve();
//    for (int i=1; i<=40; i++){
//        if (bs[i]) cout << i << ",";
//    }
    for (int i=1; i<=100000; i++){
        int tmp = i;
        while (tmp>1){
//            cout << tmp << " ";
            ++cnt[i];

            tmp/=fact[tmp];
        }
//        cout << endl;
    }

    TestCases(1);

    return 0;
}
