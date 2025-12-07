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
int test=50;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r){
    return (mt()%(r-l+1))+l;
}

/*Solution*/
void solve(){
    ofstream inp("ILIGHT.inp");
    int n = rd(5,10);
    int k = rd(5,10);
    inp << n << " " << k << endl;
    for (int i=1; i<=n; i++){
        inp << rd(1,20) << " " << rd(1,20) << endl;
    }
    for (int i=1; i<=k; i++){
        inp << rd(1,20) << endl;
    }
    inp.close();

    system("ILIGHT.exe");
    system("ILIGHT_Brute.exe");
    if (system("fc ILIGHT.out ILIGHT.ans")){
        exit(0);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    TestCases(0);

    return 0;
}

