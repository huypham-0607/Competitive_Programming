/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int n,k;
int a[N];

bool check(int x){
    int tmp = k;
    for (int i=n/2+1; i<=n; i++){
        if (a[i]>=x) continue;
        tmp -= (x-a[i]);
        if (tmp<0) return false;
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int l = a[n/2+1], r = 2e9+10;
    int res = l;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

