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
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l,int r){
    return ((mt()%(r-l+1))+l);
}

/*Solution*/
void solve(){
    srand(time(NULL));
    for (int tst=1; tst<=100; tst++){
        ofstream inp("poetry.in");
        int n = rand(400,500), m = rand(400,500), k = rand(400,500);
        n*=8; m*=8; k*=8;
        inp << n << " " << m << " " << k << endl;
        for (int i=1; i<=n; i++){
            inp << rand(1,k) << " " << rand(1,n) << endl;
        }
        for (int i=1; i<=m; i++){
            inp << char('A'+rand(0,25)) << endl;
        }
        inp.close();

        system("main.exe"); system("sol.exe");
        if (system("fc poetry.out poetry.ans")!=0){
            return;
        }
    }
    return;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

