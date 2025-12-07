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
const int N = 5e5+10;
const int INF = 998244353;
const int MD = 998244353;
const long long LLINF = 1e18+3;
const int LG = 30;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int q,l,r;
int la[N],lb[N];
int cura, curb;

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = (res*res)%MD;
        if (b&(1<<lg)) res = (res*a)%MD;
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> q;
    la[0] = 1;
    lb[0] = 0;
    cura = 1;
    curb = 0;
    l = 1; r = 0;
    while (q--){
        int idx;
        cin >> idx;
        if (idx==0){
            ++r;
            int a,b;
            cin >> a >> b;
            la[r] = a;
            lb[r] = b;
            cura = (cura*a)%MD;
            curb = (curb*a)%MD;
            curb = (curb+b)%MD;
        }
        else if (idx==1){
            cura = (cura*bin_pow(la[l],MD-2)%MD);
            curb = (MD+curb-(lb[l]*cura)%MD)%MD;
            ++l;
        }
        else{
            int x;
            cin >> x;
            cout << (x*cura%MD+curb)%MD << endl;
        }
    }
}

/*Driver Code*/
signed main(){
//    freopen("QOAC.inp","r",stdin);
//    freopen("QOAC.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

