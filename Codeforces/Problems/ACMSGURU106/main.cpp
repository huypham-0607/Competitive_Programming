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
int test=1,itest;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int a,b,c;

pii Ext_Euclidean(int a, int b){
    if (b==0){
        return make_pair(1,0);
    }
    pii tmp = Ext_Euclidean(b,a&b);
    int x,y; tie(x,y) = tmp;
    return make_pair(y,x-(a/b)*y);
}

/*Solution*/
void solve(){
    cin >> a >> b >> c;

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    for (itest=1; itest<=test; itest++){
        solve();
    }

    return 0;
}
