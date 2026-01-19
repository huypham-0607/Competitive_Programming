#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const long long LLINF = 1e18+3;


int n;

void solve(){
    cin >> n;
    for (int i=n/2; i>0; i--){
        cout << i << " " << i+n/2 << " ";
    }
    if (n%2) cout << n << " ";
    cout << endl;
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

