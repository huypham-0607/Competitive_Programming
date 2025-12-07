/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "sumdiv"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
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
int n,a,b;
vector<pii> v;

int sum_bin_pow(int a, int b){
    int tmp = a;
    vector<int> pointlg(LG);
    vector<int> sumlg(LG);
    sumlg[0] = a;
    pointlg[0] = a;
    for (int lg = 1; lg<LG; lg++){
        sumlg[lg] = ((sumlg[lg-1]*tmp)%MD+sumlg[lg-1])%MD;
        tmp = (tmp*tmp)%MD;
        pointlg[lg]=tmp;
//        sumlg[lg]+=tmp;
    }
    tmp = 1;
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        if (b&(1<<lg)){
//            cout << lg << " " << tmp << " " << sumlg[lg] << " " << res << endl;
            res += (tmp*sumlg[lg]);
            tmp = (tmp*pointlg[lg])%MD;
        }
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> a >> b;
    int cdiv = b/(MD-1), cmod = b%(MD-1);
    int tmp = a;
    int ans = 1;
    for (int i=2; i*i<a; i++){
        int vdiv=0,vmod=0;
        while (tmp%i==0){
            tmp/=i;
            vdiv+=cdiv;
            vmod+=cmod;
            if (vmod/(MD-1)){
                vdiv+=vmod/(MD-1);
                vmod%=(MD-1);
            }
        }
        if (!vdiv || !vmod){
//            cout << vdiv << " " << vmod << " " << cdiv << " " << cmod << endl;
            ans = (ans*(((sum_bin_pow(i,MD-2)*vdiv)%MD+sum_bin_pow(i,vmod))%MD))%MD;
        }
    }
    if (tmp!=1) ans = (ans*(sum_bin_pow(tmp,MD-2)*cdiv%MD+sum_bin_pow(tmp,cmod))%MD)%MD;
//    cout << cdiv << " " << cmod << " " << sum_bin_pow(tmp,cmod) << endl;
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".in","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
