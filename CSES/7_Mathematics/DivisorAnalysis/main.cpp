/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
const int LG = 30;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,a,b;

int bin_pow(int a, int b, int md){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = (res*res)%md;
        if (b&(1<<lg)) res = (res*a)%md;
    }
    return res;
}

int luua[N],luub[N];
int pre[N],suf[N];

/*Solution*/
void solve(){
    cin >> n;
    int cnt=1,sum=1,product=1,tmp=1;
    for (int i=1; i<=n; i++){
        cin >> a >> b;
        cnt = (cnt*(b+1))%MD;
        luua[i] = a;
        luub[i] = b;
        pre[i] = b+1;
        suf[i] = b+1;
        sum = sum*((bin_pow(a,b+1,MD)-1)*(bin_pow(a-1,MD-2,MD))%MD)%MD;
        tmp = (tmp*bin_pow(a,b,MD))%MD;
    }
    pre[0] = 1;
    suf[n+1] = 1;
    for (int i=1; i<=n; i++){
        pre[i] = (pre[i-1]*pre[i])%(MD-1);
    }
    for (int i=n; i>0; i--){
        suf[i] = (suf[i+1]*suf[i])%(MD-1);
    }
    for (int i=1; i<=n; i++){
        int t = ((luub[i]*(luub[i]+1))/(long long)2)%(MD-1);
//        int num = bin_pow(luua[i],t,MD);
        int sus = (((t*pre[i-1])%(MD-1))*suf[i+1])%(MD-1);
        int rawr = bin_pow(luua[i],sus,MD);
//        cout << rawr << endl;
        product = product*rawr%MD;
    }
//    cout << 1LL*2*3*4*6*8*9*12*18*24*36*72%MD << endl;
    cout << cnt << " " << sum << " " << product << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
