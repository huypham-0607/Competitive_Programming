/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "social-distancing"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,d;
int cntx[1010],cnty[1010];
int rawr[1010][1010];

/*Solution*/
void solve(){
    int res = INF;
    cin >> d >> n;
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        ++cntx[(x+INF)%(d)];
        ++cnty[(y+INF)%(d)];
        ++rawr[(x+INF)%(d)][(y+INF)%(d)];
    }
    for (int i=0; i<d; i++){
        for (int j=0; j<d; j++){
            res = min(res,cntx[i]+cnty[j]-rawr[i][j]);
//            cout << rawr[i][j] << " ";
        }
//        cout << endl;
    }
    cout << res;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
