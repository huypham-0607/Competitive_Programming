/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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

map<int,int> mp1,mp2;

/*Solution*/
void solve(){
    for (int i=1; i<=3; i++){
        int x,y;
        cin >> x >> y;
        mp1[x]++;
        mp2[y]++;
    }
    int res1=0, res2=0;
    for (auto it = mp1.begin(); it!=mp1.end(); it++){
        if (it->se < 2) res1 = it->fi;
    }
    for (auto it = mp2.begin(); it!=mp2.end(); it++){
        if (it->se < 2) res2 = it->fi;
    }
    cout << res1 << " " << res2 << endl;
}

/*Driver Code*/
signed main(){
    freopen("cetvrta.inp","r",stdin);
    freopen("cetvrta.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
