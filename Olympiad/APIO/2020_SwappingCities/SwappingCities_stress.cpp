/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SwappingCities"

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

bool check[1000][1000];

void Gen(){
    ofstream cout(NAME".inp");

    int n = rd(2,10);
    int m = rd(n-1,min(n*(n-1)/2,16));

    cout << n << " " << m << endl;

    for (int i=1; i<=m; i++){
        int u,v,w;
        if (i<=n-1){
            v = i;
            u = rd(0,i-1);
        }
        else{
            do{
                u = rd(0,n-2);
                v = rd(u+1,n-1);
            } while (check[u][v]);
        }
        w = rd(1,10);
        check[u][v] = true;
        int inv = rd(0,1);
        if (inv) cout << v << " " << u << " " << w << endl;
        else cout << u << " " << v << " " << w << endl;
    }

    int q = rd(10,20);
    cout << q << endl;
    for (int i=1; i<=q; i++){
        int u = rd(0,n-1);
        int v = rd(0,n-1);
        cout << u << " " << v << endl;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            check[i][j] = false;
        }
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
    int TEST=100;
    for (int testid = 1; testid<=TEST; testid++){
        Solve();
    }
    Solve();

    return 0;
}
