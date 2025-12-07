/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "odometer"

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

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    return mt()%(r-l+1)+l;
}

/*Global Variables*/
int l,r;

/*Solution*/
void solve(){
    l = rand(1,1000000);
    r = rand(1,1000000);
    if (l>r) swap(l,r);
    cout << l << " " << r << endl;
}

/*Driver Code*/
signed main(){
//    freopen(NAME".in","r",stdin);
    freopen(NAME".in","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

