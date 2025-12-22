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

set<int> st;
vector<int> p,q;

void Gen(){
    ofstream cout(NAME".inp");

    cout << 1 << endl;
    int n = rd(5,7), q = rd(3,4);
    cout << n << " " << q << " " << endl;
    vector<int> v(n);
    iota(all(v),1);
    shuffle(all(v),mt);
    for (auto x:v){
        cout << x << " ";
    }
    cout << endl;
    shuffle(all(v),mt);
    for (auto x:v){
        cout << x << " ";
    }
    cout << endl;
    while (q--){
        int id = rd(1,2);
        int l = rd(1,n-1);
        int r = rd(1,n);
        if (r==l) ++r;
        cout << id << " " << l << " " << r << endl;
    }
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

    return 0;
}
