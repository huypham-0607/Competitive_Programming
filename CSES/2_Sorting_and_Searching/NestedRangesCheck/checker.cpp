/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9;
const long long LLINF = 1e18+3;

const string NAME = "main";

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Random*/
const int NTEST = 10;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r){
    return l+mt()%(r-l+1);
}

/*Global Variables*/
int n;
set<pii> st;
/*Solution*/
void solve(){
    srand(time(NULL));
    for (int itest=1; itest<=NTEST; itest++){
        st.clear();
        ofstream inp((NAME + ".inp").c_str());
        int n = rd(2,8);
        inp << n << endl;
//        cout << n << endl;
        for (int i=1; i<=n; i++){
            pii point;
            do{
                point.fi = rd(1,999);
                point.se = rd(point.fi+1,1000);
            } while (st.find(point)!=st.end());
//            cout << point.fi << " " << point.se << endl;
            inp << point.fi << " " << point.se << endl;
            st.insert(point);
        }
        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        system(("fc " + NAME + ".out " + NAME + ".ans").c_str());
    }
}

/*Driver Code*/
signed main(){
    freopen("checker.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
