/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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

/*Global Variables*/
int l,r;
int cnt[10];

bool check(int x){
    for (int i=0; i<10; i++){
        cnt[i] = 0;
    }
    int t = 0;
    while (x!=0){
        ++t;
        cnt[x%10]++;
        x/=10;
    }
    for (int i=0; i<10; i++){
        if (t%2==0 && cnt[i]>=t/2) return true;
        else if (t%2==1 && cnt[i]>t/2) return true;
    }
    return false;
}

/*Solution*/
void solve(){
    cin >> l >> r;
    int res = 0;
    for (int i=l; i<=r; i++){
        if (check(i)) ++res;
    }
    cerr << res << endl;
    cout << res << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

