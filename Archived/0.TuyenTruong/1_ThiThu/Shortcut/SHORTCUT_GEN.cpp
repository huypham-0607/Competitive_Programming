/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SHORTCUT"

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

set<pii> st;

void Gen(){
    ofstream cout(NAME".in");

    st.clear();
    int n = rd(5,7);
    int m = rd(n+2,n+4);
    int t = rd(2,4);
    cout << n << " " << m << " " << t << endl;
    for (int i=1; i<=n; i++){
        int rawr = rd(0,3);
        cout << rawr << " ";
    }
    cout << endl;
    for (int i=1; i<n; i++){
        bool ver = 0;
        while (!ver){
            int u = rd(1,i);
            int v = i+1;
            int cst = rd(2,5);
            if (!st.count(make_pair(u,v))){
                ver = 1;
                cout << u << " " << v << " " << cst << endl;
                st.insert(make_pair(u,v));
            }
        }
    }

    for (int i=n; i<=m; i++){
        bool ver = 0;
        while (!ver){
            int u = rd(1,n);
            int v = rd(1,n);
            int cst = rd(2,5);
            if (u==v) continue;
            if (u>v) swap(u,v);
            if (!st.count(make_pair(u,v))){
                ver = 1;
                cout << u << " " << v << " " << cst << endl;
                st.insert(make_pair(u,v));
            }
        }
    }

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
    int TEST=1000;
    for (int testid = 1; testid<=TEST; testid++){
        Solve();
    }
    Solve();

    return 0;
}

