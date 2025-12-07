/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "CYCLE"

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

    int nt = rd(1,10);

    cout << nt << endl;
    for (int nopium=1; nopium<=nt; nopium++){
        int n = rd(5,7);
        int m = rd(1,n-1);
        int k = rd(1,n-m);
        cout << n << " " << m << " " << k << endl;
        int tq = m+k;
        for (int i=1; i<=n; i++){
            st.insert(i);
        }
        for (int i=0; i<tq; i++){
            int delta = rd(0,n-i-1);
            auto it = st.begin();
            while (delta--) ++it;
            if (i<m) p.push_back(*it);
            else q.push_back(*it);
            st.erase(it);
        }
        for (auto x:p) cout << x << " ";
        cout << endl;
        for (auto x:q) cout << x << " ";
        cout << endl;
        st.clear();
        p.clear();
        q.clear();
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
    int TEST=10;
    for (int testid = 1; testid<=TEST; testid++){
        Solve();
    }

    return 0;
}
