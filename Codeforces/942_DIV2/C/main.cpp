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
const long long LLINF = 2e12+17;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,k;
vector<int> v;

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(LLINF);
    sort(v.begin(),v.end());
    int val = v[0];
    int i=0;
    while (k>=(v[i+1]-v[i])*(i+1)){
        k-=(v[i+1]-v[i])*(i+1);
        ++i;
        val = v[i];
    }
    val+=k/(i+1);
    int du = k%(i+1) + n-(lower_bound(v.begin(),v.end(),val+1) - v.begin());
    int ans = 1+(val-1)*n+du;
//    cout << i << " " << val << " " << k << " " << du << " " << ans << endl;
    cout << ans << endl;
    v.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
