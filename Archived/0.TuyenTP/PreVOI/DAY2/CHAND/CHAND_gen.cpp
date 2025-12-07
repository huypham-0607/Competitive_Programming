/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CHAND"

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

vector<pii> v;

void Gen(){
    ofstream cout(NAME".inp");

    int n = rd(5,7);
    int q = rd(5,7);
    cout << n << " " << q << endl;
    for (int i=1; i<=n; i++){
        int val = rd(1,10);
        cout << val << endl;
    }

    for (int i=1; i<=n; i++){
        int val = rd(1,1000000);
        v.push_back({val,i});
    }
    sort(all(v));
    for (int i=1; i<(int)v.size(); i++){
        cout << v[i-1].se << " " << v[i].se << endl;
    }

    for (int i=1; i<=q; i++){
        if (i<=n){
            int pos = rd(0,n-i);
            int u = v[pos].se;
            int x = v[pos+i-1].se;
            cout << u << " " << x << endl;
        }
        else{
            int u = rd(1,n);
            int v = rd(1,n);
            cout << u << " " << v << endl;
        }
    }

    v.clear();
    cout.close();
}

/*Solution*/
void Solve(){
    Gen();

    system(NAME ".exe");
    system(NAME "_BRUTE.exe");
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
