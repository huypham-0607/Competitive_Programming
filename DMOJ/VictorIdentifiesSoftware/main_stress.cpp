/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "main"

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

    int n = rd(5,5);
    int q = rd(1,10);
    cout << n << " " << q << endl;
    for (int i=1; i<=n; i++) {
        cout << rd(-10,10) << " ";
    }
    cout << endl;
    for (int i=1; i<=q; i++) {
        int id = rd(1,5);
        int l = rd(1,n);
        int r = rd(l,n);
        int val = rd(-10,10);
        cout << id << " " << l << " " << r;
        if (id == 3) cout << " " << val;
        cout << endl;
    }

    cout.close();
}

/*Solution*/
void Solve(){
    Gen();

    system("g++ " NAME ".cpp -o " NAME);
    system("g++ " NAME "_brute" ".cpp -o " NAME "_brute");
    system("./" NAME);
    system("./" NAME "_brute");
    if (system("diff " NAME ".out " NAME ".ans")){
        cerr << "WA" << endl;
        exit(0);
    }
}

/*Driver Code*/
signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    srand(time(NULL));
    int TEST=100;
    for (int testid = 1; testid<=TEST; testid++){
        cout << "Test " << testid << ":" << endl;
        Solve();
    }
    Solve();

    return 0;
}
