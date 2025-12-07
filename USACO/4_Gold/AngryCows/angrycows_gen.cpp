/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "angrycows"

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

mt19937_64 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rd(int l, int r){
    return mt()%(r-l+1)+l;
}

set<int> st;

void Gen(){
    ofstream cout(NAME".inp");
    st.clear();
    int n = rd(5,7);
    cout << n << endl;
    for (int i=1; i<=n; i++){
        int val;
        do{
            val = rd(1,20);
        } while (st.count(val));
        st.insert(val);
        cout << val << endl;
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

