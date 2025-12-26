/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "679E"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

#define int long long

/*Global Variables*/
int n;
mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(ll l, ll r){
    return uniform_int_distribution<ll> (l,r) (mt);
}

int pw[12];

void Gen(){
    ofstream cout(NAME".inp");

    int n = rd(10,20);
    int q = rd(10,20);
    cout << n << " " << q << endl;
    int delta = rd(20,200);
    for (int i=1; i<=n; i++) {
        int id = rd(1,5);
        if (id == 1) {
            cout << rd(2,pw[id]-1) << " ";
        } else {
            cout << rd(pw[id]-delta,pw[id]-1) << " ";
        }
    }
    cout << endl;
    for (int i=1; i<=q; i++) {
        int id = rd(1,3);
        if (id == 1) {
            int x = rd(1,n);
            cout << id << " " << x << endl;
        }
        if (id == 2) {
            int l = rd(1,n);
            int r = rd(l,n);        
            int p = rd(1,5);
            int x;
            if (p == 1) {
                x = rd(2,pw[p]-1);
            } else {
                x = rd(pw[p]-delta,pw[p]-1);
            }
            cout << id << " " << l << " " << r << " " << x << endl;
        }
        if (id == 3) {
            int l = rd(1,n);
            int r = rd(l,n);
            int p = rd(1,delta);
            cout << id << " " << l << " " << r << " " << p << endl;
        }
    }

    cout.close();
}

/*Solution*/
void Solve(){
    pw[0] = 1;
    for (int i=1; i<12; i++){
        pw[i] = pw[i-1]*42;
    }
    Gen();

    system("g++ " NAME ".cpp -o " NAME " && ./" NAME);
    system("g++ " NAME "_brute.cpp -o " NAME "_brute" " && ./" NAME "_brute");
    if (system("diff " NAME ".out " NAME ".ans")){
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
        cerr << testid << endl;
        Solve();
    }
    Solve();

    return 0;
}
