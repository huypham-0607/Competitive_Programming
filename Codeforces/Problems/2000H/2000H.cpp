/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int M = 2e6;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

set<pii> st, ans;

void ins(int x) {
    // cerr << "x: " << x  << endl;
    auto it = (--st.upper_bound({x,INF}));
    pii e = (*it);  
    // cerr << e.fi << " " << e.se << endl;
    ans.erase({it->se - it->fi + 1,it->fi});

    bool fl = false;
    bool fr = false;

    if (x != it->fi) {
        fl = true;
        ans.insert({x-it->fi, it->fi});
    }
    if (x != it->se) {
        fr = true;
        ans.insert({it->se-x, x+1});
    }
    st.erase(e);

    // cerr << fl << " " << fr << " " << e.fi << " " << e.se << endl;
    if (fl) {
        st.insert({e.fi, x-1});
    }
    if (fr) {
        st.insert({x+1, e.se});
    }
}

void del(int x) {
    auto it = (st.upper_bound({x,INF}));

    pii le = {0,0};
    pii re = {0,0};

    bool fl = false;
    bool fr = false;
    int l=x, r = x;
    if (it != st.begin() && prev(it)->se + 1 == x) {
        le = (*prev(it));
        l = prev(it)->fi;
        fl = true;
        ans.erase({prev(it)->se - prev(it)->fi + 1, prev(it)->fi});
    }
    if (it != st.end() && it->fi - 1 == x) {
        re = (*it);
        r = it->se;
        fr = true;
        ans.erase({it->se - it->fi + 1, it->fi});
    }

    if (fl) {
        st.erase(le);
    }
    if (fr) {
        st.erase(re);
    }

    st.insert({l,r});
    ans.insert({r-l+1,l});
}

void solve(){
    cin >> n;
    st.clear();
    ans.clear();
    st.insert({1,2*M});
    ans.insert({2*M,1});
    // cerr << "Init set: \n";
    for (int i=1; i<=n; i++){
        // cerr << i << endl;
        int x; cin >> x;
        ins(x);
        // for (auto in : st) {
        //     cerr << in.fi << "-" << in.se << endl;
        // }
        // for (auto in : ans) {
        //     cerr << in.fi << "-" << in.se << endl;
        // }
    }
    // cerr << "Query: \n";

    int m; cin >> m;
    for (int i=1; i<=m; i++){
        // cerr << "Id: " << i << endl;
        char c; int x; cin >> c >> x;
        if (c == '+') {
            // cerr << "+ " << x << endl;
            ins(x);
        }
        else if (c == '-') {
            // cerr << "- " << x << endl;
            del(x);
        }
        else {
            int mn = INF;
            int delta = x;
            auto it = ans.lower_bound({delta,0});
            
            while (it != ans.end()) {
                mn = min(mn,it->se);
                delta = it->fi+1;
                it = ans.lower_bound({delta,0});
            }
            if (mn == INF) {
                cout << M+1 << " ";
            }
            else {
                cout << mn << " ";
            }
        }
        // cerr << "set: " << endl;
        // for (auto in : st) {
        //     cerr << in.fi << "-" << in.se << endl;
        // }
        // cerr << "ans: " << endl;
        // for (auto in : ans) {
        //     cerr << in.fi << "-" << in.se << endl;
        // }
    }
    cout << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

