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
int a,b;
int val[4] = {2,3,5,7};

int Calc(int lmao){
    int cnt = 0;
    for (int mask=1; mask<(1<<4); mask++){
        int x = 1;
        for (int idx=0; idx<4; idx++){
            if (mask&(1<<idx)) x*=val[idx];
        }
        if (__builtin_popcountll(mask)%2) cnt+=(lmao/x);
        else cnt-=lmao/x;
    }
    return cnt;
}

/*Solution*/
void solve(){
    cin >> a >> b;
    int l = Calc(a-1);
    int r = Calc(b);
//    cout << l << " " << r << " " << r-l << endl;
    cout << b-a+1-(r-l) << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
