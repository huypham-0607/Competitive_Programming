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
const int LG = 60;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,a,b,orgb;

int bin_pow(int a, int b){
    a%=MD;
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = (res*res)%MD;
        if (b&(1LL<<lg)) res = (res*a)%MD;
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> a >> orgb;
    b = orgb%(MD-1);
    int ans = 1;
    int tmp = a;
    for (int i=2; i*i<a; i++){
        if (tmp%i!=0) continue;
        int cnt = 0;
        while (tmp%i==0){
            tmp/=i;
            ++cnt;
        }
        int dk_1 = (MD+bin_pow(i,(cnt*b+1)%(MD-1))-1)%MD;
        int d_1 = (bin_pow(i-1,MD-2));
        ans = (ans*((dk_1*d_1)%MD)%MD);
    }
    if (tmp!=1){
        if ((tmp-1)%MD == 0){
            ans = (ans*((orgb+1)%MD))%MD;
        }
        else{
            int i = tmp;
            int cnt = 1;
            int dk_1 = (MD+bin_pow(i,(cnt*b+1)%(MD-1))-1)%MD;
            int d_1 = (bin_pow(i-1,MD-2));
            ans = (ans*((dk_1*d_1)%MD)%MD);
        }
    }
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
