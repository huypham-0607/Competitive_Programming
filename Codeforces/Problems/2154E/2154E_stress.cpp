/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "2154E"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(ll l, ll r){
    return uniform_int_distribution<ll> (l,r) (mt);
}

void Gen(){
    ofstream cout(NAME".inp");

    int t = rd(1,10);
    cout << t << endl;
    for (int tid=1; tid<=t; tid++){
        int n = rd(10,15);
        int k = rd(1,15);
        cout << n << " " << k << endl;
        for (int i=1; i<=n; i++){
            int x = rd(1,30);
            cout << x << " ";
        }
        cout << endl;
    }

    cout.close();
}

/*Solution*/
void Solve(){
    Gen();

    system("./" NAME);
    system("./" NAME "_brute");
    if (system("diff " NAME ".out " NAME ".ans")){
        cerr << "WA" << endl;
        exit(0);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    system("g++ " NAME ".cpp -o" NAME);
    system("g++ " NAME "_brute.cpp -o " NAME "_brute");

    srand(time(NULL));
    int TEST=1000;
    for (int testid = 1; testid<=TEST; testid++){
        cerr << "Test: " << testid << endl;
        Solve();
    }
    Solve();

    return 0;
}
