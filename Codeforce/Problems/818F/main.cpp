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
int q,n;

int Calc_Edge(int x){
    int val = n-x;
    return val*(val-1)/2;
}

bool Check(int x){
    int cnt = Calc_Edge(x);
    if (cnt<x) return false;
    return true;
}

/*Solution*/
void solve(){
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> n;
        int ans = -1;
        int l = 0, r = n-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (Check(mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        if (ans == n-1) cout << ans*2 << endl;
        else{
            int res = max(ans*2,(ans+1)+Calc_Edge(ans+1));
            cout << res << endl;
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
