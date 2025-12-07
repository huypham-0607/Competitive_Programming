/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "QOAC"

using namespace std;

/*Constants*/
const int N = 5e5+10;
const int INF = 998244353;
const int MD = 998244353;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int q;
int a[N],b[N];
int l=1, r=0;

int Get(int x){
    int cura = 1, curb = 0;
    for (int i=l; i<=r; i++){
        cura = (cura*a[i]%MD);
        curb = (curb*a[i]%MD+b[i])%MD;
    }
    return (x*cura%MD+curb)%MD;
}

/*Solution*/
void solve(){
    cin >> q;
    while (q--){
        int idx;
        cin >> idx;
        if (idx==0){
            ++r;
            int x,y;
            cin >> x >> y;
            a[r] = x;
            b[r] = y;
        }
        else if (idx==1){
            ++l;
        }
        else{
            int x;
            cin >> x;
            cout << Get(x) << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

