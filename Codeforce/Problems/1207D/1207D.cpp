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

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const long long MD = 998244353;

/*Global Variables*/
int n;
pii a[N];
int fac[N];

/*Solution*/
void solve(){
    fac[0] = 1;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i].fi >> a[i].se;
    }
//    for (int i=1; i<=n; i++){
//        cout << fac[i] << " ";
//    }
    for (int i=1; i<=n; i++){
        fac[i] = fac[i-1]*i%MD;
    }
    sort(a,a+n,[&] (pii x, pii y){return x.fi < y.fi;});
    int lcalc = 1;
    int cnt = 0;
    for (int i=0; i<n; i++){
        ++cnt;
        if (a[i+1].fi!=a[i].fi){
            lcalc = lcalc*fac[cnt]%MD;
            cnt = 0;
        }
    }
    sort(a,a+n,[&] (pii x, pii y){return x.se < y.se;});
    int rcalc = 1;
    cnt = 0;
    for (int i=0; i<n; i++){
        ++cnt;
        if (a[i+1].se!=a[i].se){
            rcalc = rcalc*fac[cnt]%MD;
            cnt = 0;
        }
    }
    int lmao = 1;
    map<int,int> mp;
    for (int i=0; i<n; i++){
        mp[a[i].se]++;
        if (a[i].fi!=a[i+1].fi){
            if (a[i].se!=a[i+1].se){
                lmao = 0;
                break;
            }
            for (auto it = mp.begin(); it!=mp.end(); it++){
                lmao = (lmao*fac[it->se])%MD;
            }
            mp.clear();

        }
    }
    cout << ((lcalc+rcalc)%MD-lmao)%MD << endl;
//    cout << lcalc << " " << rcalc << " " << lmao <<endl;
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
