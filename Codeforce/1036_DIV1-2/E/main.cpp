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
int pre[N],suf[N];

void lmao(){
    for (int i=1; i<=n; i++){
        pre[i] = 0;
        suf[i] = 0;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    int t = 0;
    int mx = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        t+=a[i];
        mx = max(mx,a[i]);
    }

    if (t%2){
        cout << -1 << endl;
        lmao();
        return;
    }

    if (mx>t/2){
        cout << -1 << endl;
        lmao();
        return;
    }

    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1]+a[i];
    }
    for (int i=n; i>0; i--){
        suf[i] = suf[i+1]+a[i];
    }

    for (int i=1; i<n; i++){
        if (pre[i] = suf[i+1]){
            cout << 1 << endl;
            for (int i=1; i<=n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            lmao();
            return;
        }
    }

    for (int i=1; i<=n; i++){
        if (pre[i]>suf[i+1]){

        }
    }

    int pos = 1;
    for (pos; pos<=n; pos++){
        if (pre[pos]>=t/2){
            break;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
