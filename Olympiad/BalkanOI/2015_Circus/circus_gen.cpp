/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "circus"

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

    vector<int> p;
    int m = rd(1,1000000000);
    int n = rd(min(m,1000),min(m,1000));
    for (int i=1; i<=n; i++){
        p.push_back(rd(0,m-1));
    }
    sort(all(p));
    p.resize(unique(all(p))-p.begin());

    n = p.size();

    cout << n << " " << m << endl;
    for (auto x:p) cout << x << " ";
    cout << endl;

    int q = rd(1,10000);
    cout << q << endl;
    for (int i=1; i<=q; i++){
        cout << rd(0,m-1) << " ";
    }
    cout << endl;

    cout.close();
}

/*Solution*/
void Solve(){
    Gen();

    system(NAME ".exe");
    system(NAME "_brute.exe");
    if (system("fc " NAME ".out " NAME ".ans")){
        cerr << "WA" << endl;
        exit(0);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    int TEST=1000;
    for (int testid = 1; testid<=TEST; testid++){
        Solve();
    }
    Solve();

    return 0;
}
