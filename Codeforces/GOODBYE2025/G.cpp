/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "G"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
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

int rand(int l, int r) {
    return rd()%(r-l+1LL)+l;
}

int genHash() {
    return rand(1LL,(1LL<<62)-1);
}

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        n = _n;
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        while (idx<=n){
            BIT[idx]^=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res^=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)^getPoint(l-1));
    }
};


int n;

void solve(){
    cin >> n;
    string s;
    Fenwick cnt(2*n),hash(2*n);
    int cur = 0;
    for (int i=1; i<=n; i++){
        int l,r; cin >> l >> r;
        if (l>r) swap(l,r);
        int val = cnt.getVal(l,r)^1;
        // cout << val << endl;
        int hashval = hash.getVal(l,r);
        // cout << hashval << " ";
        if (val) {
            int newHash = genHash();
            // cout << newHash << " ";
            hashval^=newHash;
            cnt.update(l,val);
            cnt.update(r,val);
        }
        // cout << endl;
        cur^=hashval;
        hash.update(l,hashval);
        hash.update(r,hashval);
        if (cur == 0) s+="1";
        else s+="0";
    }
    cout << s << endl;
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

