/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "swap"

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

    int n = rd(10,100);

    cout << n << endl;

    vector<int> v;

    for (int i=1; i<=n; i++){
        v.push_back(i);
    }

    for (int i=n-1; i>=0; i--){
        int x = rd(0,n-1);
        swap(v[i],v[x]);
    }

    for (int i=0; i<n; i++){
        cout << v[i] << " ";
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
    int TEST=100;
    for (int testid = 1; testid<=TEST; testid++){
        Solve();
    }
    Solve();

    return 0;
}
