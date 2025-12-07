/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "1320E"

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

void Gen(){
    ofstream cout(NAME".inp");

    int n = rd(50,70);
    int q = rd(50,70);
    cout << n << endl;
    for (int i=2; i<=n; i++){
        int j = rd(1,i-1);
        cout << i << " " << j << endl;
    }
    cout << q << endl;
    for (int id=1; id<=q; id++){
        st.clear();
        for (int i=1; i<=n; i++){
            st.insert(i);
        }
        int k = rd(1,n);
        int m = rd(1,n);
        cout << k << " " << m << endl;
        for (int i=1; i<=k; i++){
            int pos = rd(0,n-i);
            auto it = st.begin();
            for (int idx=1; idx<=pos; idx++){
                ++it;
            }
            int x = (*it);
            int lvl = rd(1,30);
            cout << x << " " << lvl << endl;
            st.erase(x);
        }

        for (int i=1; i<=n; i++){
            st.insert(i);
        }
        for (int i=1; i<=m; i++){
            int pos = rd(0,n-i);
            auto it = st.begin();
            for (int idx=1; idx<=pos; idx++){
                ++it;
            }
            int x = (*it);
            cout << x << " ";
            st.erase(x);
        }
        cout << endl;

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
