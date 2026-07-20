/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define TEXT ""
using namespace __gnu_pbds;
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
int q_type[N];
int val[N], ans[N];

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        n = _n;
        BIT.clear();
        BIT.resize(n+10,0);
    }

    void Init (int _n, int val=0){
        n = _n;
        BIT.clear();
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        assert(idx>0);
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)-getPoint(l-1));
    }
} BITval;

ordered_set os;

vector<int> query;

void solve(){
    cin >> n;
    query.clear();
    query.push_back(0);
    for (int i=1; i<=n; i++){
        char c; cin >> c >> val[i];
        q_type[i] = ((c=='p')?0:1);
        if (q_type[i]) {
            query.push_back(i);
        }
        else {
            ans[i] = val[i];
        }
    }

    // ffor(i,1,n) {
    //     cerr << q_type[i] << " " << val[i] << endl;
    // }

    // cerr << "passed init" << endl;

    BITval.Init(n);
    BITval.update(1,n);
    ffor(i,1,n) {
        BITval.update(i,-1);
        os.insert(i);
    }

    for (int i=n; i>query.back(); i--){
        // cerr << "prelim" << " " << val[i] << endl;
        BITval.update(1,-1);
        BITval.update(val[i],1);
        os.erase(os.find(val[i]));
    }

    for (int idx=query.size()-1; idx>0; idx--){
        // cerr << "idx: " <<  idx << " " << (*os.find_by_order(0)) <<  endl;
        int delta = val[query[idx]] - val[query[idx-1]];

        vector<int> lst;
        for (int i=query[idx]-1; i>query[idx-1]; i--) {
            int x = BITval.getVal(1,val[i]);
            delta -= x;

            BITval.update(1,-1);
            BITval.update(val[i],1);
            lst.push_back(val[i]);
        }

        for (int i=query[idx]-1; i>query[idx-1]; i--) {
            // cerr << i << " " << val[i] << endl;
            BITval.update(1,1);
            BITval.update(val[i],-1);
        }

        sort(all(lst));
        int fnum = 0;
        // cerr << "lst: " << endl;
        // for (auto x:lst) {
        //     cerr  << x << " ";
        // }cerr << endl;
        // cerr << "os: " << endl;
        // for (auto x:os) {
        //     cerr  << x << " ";
        // }cerr << endl;
        for (int offset=0; offset<=lst.size(); offset++){
            int pos = query[idx]-(delta+offset);
            // cerr << offset << " " << pos << " " << delta << endl;
            if (pos > query[idx] || pos <= 0) continue;
            int num = (*os.find_by_order(pos-1));
            // cerr << "num: " << num << endl;
            if (offset!=0 && num < lst[offset-1]) continue;
            if (offset!=lst.size() && num > lst[offset]) continue;
            fnum = num;
            break;
        }
        // cerr << fnum << endl;
        assert(fnum!=0);

        BITval.update(1,-1);
        BITval.update(fnum,1);
        os.erase(os.find(fnum));
        ans[query[idx]] = fnum;
        for (int i=query[idx]-1; i>query[idx-1]; i--) {
            BITval.update(1,-1);
            BITval.update(val[i],1);
            os.erase(os.find(val[i]));
        }
    }

    ffor(i,1,n) cout << ans[i] << " "; cout << endl;
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

