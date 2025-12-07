/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "training"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=500;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
set<pii> st;

mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(int l, int r){
    return mt()%(r-l+1)+l;
}

void Gen(){
    ofstream cout(NAME".inp");
    st.clear();
    int n = rd(15,25);
    int m = rd(n-1+10,n-1+20);

    cout << n  << " "  << m << endl;
    for (int i=2; i<=n; i++){
        int u = rd(1,i-1);
        cout << u << " " << i << " " << 0 << endl;
        st.insert({u,i});
    }
    for (int i=1; i<=m-n+1; i++){
        int cnt = 0;
        while (!cnt){
            int u = rd(1,n);
            int v = rd(1,n);
            int cst = rd(5,30);
            if (u>v) swap(u,v);
            if (u==v) continue;
            if (st.count({u,v})) continue;
            cout << u << " " << v << " " << cst << endl;
            st.insert({u,v});
            ++cnt;
        }
    }
    cout.close();
}

/*Solution*/
void solve(){
    Gen();

    system(NAME".exe");
    system(NAME"_brute.exe");
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
    TestCases(0);

    return 0;
}


