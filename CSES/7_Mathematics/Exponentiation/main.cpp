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
const int LG = 30;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,a,b,c;

int magic(int a, int b){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = ((ll)res*res)%(INF-1);
        if (b&(1<<lg)) res = ((ll)res*a)%(INF-1);
    }
    return res;
}

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=LG-1; lg>=0; lg--){
        res = ((ll)res*res)%INF;
        if (b&(1<<lg)) res = ((ll)res*a)%INF;
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> a >> b >> c;
    cout << bin_pow(a,magic(b,c)) << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
