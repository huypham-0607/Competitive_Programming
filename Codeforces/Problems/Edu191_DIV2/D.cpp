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
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

struct block{
    int val,sz,s;
    vector<int> adj;
    block(int _val=0, int _sz=0, int _s = 0) {
        val = _val;
        sz = _sz;
        s = _s;
    }
};

int a[N];
vector<block> blist[N];
vector<int> nen;

int check(int u, int v) {
    swap(a[u],a[v]);

    int cmp = 1;
    for (int i=1; i<n; i++){
        if (a[i] != a[i+1]) ++ cmp;
    }
    swap(a[u],a[v]);
    return (cmp == nen.size());
}

void solve(){
    cin >> n;
    ffor (i,1,n) {
        blist[i].clear();
    }
    nen.clear();
    ffor(i,1,n) {
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    ffor(i,1,n) a[i] = lower_bound(all(nen),a[i])-nen.begin()+1;
    int m = 0;
    int sz = 0;
    int lst = 0;
    vector<int> adj;
    for (int i=1; i<=n; i++){
        ++sz;
        if (i == n || a[i] != a[i+1]) {
            if (i!=n) adj.push_back(a[i+1]);
            block bl(a[i],sz,lst+1);
            ++m;
            bl.adj = adj;
            blist[a[i]].push_back(bl);
            adj.clear();
            adj.push_back(a[i]);
            sz = 0;
            lst = i;
        }
    }

    int aval = 0;

    for (int i=1; i<=nen.size(); i++){
        if (blist[i].size() > 3) {
            cout << "NO" << endl;
            return;
        }
        if (blist[i].size() > 1) {
            aval = i;
            break;
        }
    }

    if (aval == 0) {
        cout << "YES" << endl;
        return;
    }

    // cout << aval << endl;

    for (auto u:blist[aval]) {
        for (auto v:blist[aval]){
            if (v.s-1>0) {
                if (check(u.s,v.s-1)) {
                    cout << "YES" << endl;
                    return;
                }
                if (check(u.s+u.sz-1,v.s-1)) {
                    cout << "YES" << endl;
                    return;
                }
            }
            if (v.s+v.sz <=n) {
                if (check(u.s,v.s+v.sz)) {
                    cout << "YES" << endl;
                    return;
                }
                if (check(u.s+u.sz-1,v.s+v.sz)) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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

