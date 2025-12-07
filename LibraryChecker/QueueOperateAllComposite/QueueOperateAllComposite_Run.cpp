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
const int NTEST = 100;
const int N = 2e5+10;
const int INF = 998244353;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    return (mt()%(r-l+1))+l;
}

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    n = rand(1,1000);
    int cnt = 0;
    ofstream inp("QOAC.inp");
    inp << n << endl;
    for (int i=1; i<=n; i++){
        int idx;
        if (cnt == 0){
            idx = rand(0,1);
            idx*=2;
        }
        else idx = rand(0,2);
        inp << idx;
        if (idx == 0){
            ++cnt;
            int a=rand(1,INF);
            int b=rand(0,INF);
            inp << " " << a << " " << b << endl;
        }
        else if (idx == 1){
            --cnt;
            inp << endl;
        }
        else{
            int x = rand(0,INF);
            inp << " " << x << endl;
        }
    }
    inp.close();

    cerr << n << endl;

    system("QueueOperateAllComposite.exe");
    system("QueueOperateAllComposite_Brute.exe");
    if (system("fc QOAC.out QOAC.ans")){
        exit(0);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    int TEST = 100;
    while (TEST--){
        solve();
    }

    return 0;
}

