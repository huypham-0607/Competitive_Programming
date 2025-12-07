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

/*Global Variables*/
int n, mnlen, mxlen;
int a[N], b[N];

/*Solution*/
void solve(){
    cin >> n >> mnlen >> mxlen;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i]*=2;
    }

    sort(a+1, a+1+n);


    for (int i=1; i<n; i++){
        if (a[i] + mnlen > a[i+1] - mnlen){
            cout << -1 << endl;
            return;
        }
    }

    int ans = 0;

    b[0] = -2*INF;
    a[n+1] = 2*INF;
    for (int i=1; i<=n; i++){
        int delta = min({a[i] - b[i-1], mxlen, (a[i+1] - mnlen) - a[i]});
        ans += delta;
        b[i] = a[i] + delta;
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
