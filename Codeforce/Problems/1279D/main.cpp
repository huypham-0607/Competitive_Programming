/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int LIM = 1000000;
const int N = 1e6+10;
const int INF = 1e9+7;
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

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = ((ll)res*res)%MD;
        if (b&(1<<lg)) res = ((ll)res*a)%MD;
    }
    return res;
}

/*Global Variables*/
int n;
int k[N];
vector<int> a[N];
int cnt[N];
int pre[N],suf[N];

/*Solution*/
void solve(){
    cin >> n;
    int x=0, y=1;
    for (int i=1; i<=n; i++){
        cin >> k[i];
        for (int j=1; j<=k[i]; j++){
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
            ++cnt[tmp];
        }
    }
    pre[0] = 1, suf[LIM+1] = 1;
    for (int i=1; i<=LIM; i++){
        pre[i] = (pre[i-1]*i)%MD;
    }
    for (int i=LIM; i>0; i--){
        suf[i] = (suf[i+1]*i)%MD;
    }
    y = (((y*pre[LIM])%MD*n)%MD*(n)%MD);
    for (int i=1; i<=n; i++){
        int tmp = 0;
        for (auto j:a[i]){
            int rawr = cnt[j];
            rawr = ((rawr*pre[k[i]-1])%MD*suf[k[i]+1])%MD;
            tmp = (tmp+rawr)%MD;
        }
        x = (x+tmp)%MD;
    }
//    cout << y << endl;
//    cout << x << endl;
    cout << (x*bin_pow(y,MD-2))%MD << endl;
//    cout << (3*bin_pow(4,MD-2))%MD << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
