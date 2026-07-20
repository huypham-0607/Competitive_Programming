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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;

vector<pair<pii,int>> queries[4*N];

struct LazySegmentTree{
    struct Node{
        int mx,mn;
        Node(){
            mn = 0;
            mx = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;
    
    void applySet(int idx, int val){
        IT[idx].mx = IT[idx].mn = val;
        lazy[idx] = val;
    }

    void propagate(int idx){
        int val = lazy[idx];
        if (val != -INF) {
            applySet(idx*2,val);
            applySet(idx*2+1,val);
        }
        //Reset idx
        lazy[idx] = -INF;
    }

    void comb(Node& i, Node& l, Node& r){
        i.mx = max(l.mx,r.mx);
        i.mn = min(l.mn,r.mn);
    }

    void init(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, -INF);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].mx = IT[idx].mn = -1;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val, int qid){
        if (y < l || r < x) return;
        if (x <= l && r <= y && IT[idx].mn == IT[idx].mx){
            queries[idx].push_back({{val-max(IT[idx].mx,0LL),(IT[idx].mx == -1)},qid});
            applySet(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val,qid);
        update(idx*2+1,mid+1,r,x,y,val,qid);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    // int getVal(int idx, int l, int r, int x, int y){
    //     if (y < l || r < x) return 0;
    //     if (x <= l && r <= y){
    //         // Get Logic
    //     }

    //     propagate(idx);

    //     int mid = (l+r)/2;
    //     return max(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    // }
} IT;

int ans[N];
int start_mana[N],max_mana[N],regen[N],cap[N];
vector<int> lst[4*N];

void upt(int qid, int delta, int is_first, int l, int r, int t, int pref) {
    int val;
    if (is_first) {
        val = 0;
        for (int i=l; i<=r; i++){
            val += min(delta*regen[i]+start_mana[i],max_mana[i]);
        }
    }
    else val = delta*t + pref;

    // cout << qid << " " << l << " " << r << " " << delta << " " << val << endl;

    ans[qid] += val;
}

void resolveQueries(int idx, int l, int r) {
    if (l==r) {
        int i = l;
        for (auto [in,qid]:queries[idx]) {
            auto [delta,is_first] = in;
            int val = min(delta*regen[i] + ((is_first)?start_mana[i]:0),max_mana[i]);
            // cout << qid << " " << l << " " << r << " " << delta << " " << val << endl;

            ans[qid] += val;
        }
        lst[idx].push_back(i);
        return;
    }

    int mid = (l+r)/2;
    resolveQueries(idx*2,l,mid); resolveQueries(idx*2+1,mid+1,r);

    int t = 0;
    int pref = 0;
    for (auto x:lst[idx*2]) t+=regen[x];
    for (auto x:lst[idx*2+1]) t+=regen[x];
    sort(all(queries[idx]));
    int n = lst[idx*2].size() + lst[idx*2+1].size();

    int pos = 0;
    int lptr = 0, rptr = 0;
    for (int lol=0; lol<n; lol++){
        if (lptr == lst[idx*2].size()) lst[idx].push_back(lst[idx*2+1][rptr++]);
        else if (rptr == lst[idx*2+1].size()) lst[idx].push_back(lst[idx*2][lptr++]);
        else lst[idx].push_back((cap[lst[idx*2][lptr]] <= cap[lst[idx*2+1][rptr]]) ? lst[idx*2][lptr++] : lst[idx*2+1][rptr++]);
        
        while (pos!=queries[idx].size() && queries[idx][pos].fi.fi <= cap[lst[idx].back()]) {
            int qid = queries[idx][pos].se;
            auto [delta,is_first] = queries[idx][pos].fi;
            upt(qid,delta,is_first,l,r,t,pref);
            ++pos;
        }

        t-=regen[lst[idx].back()];
        pref+=max_mana[lst[idx].back()];
    }
    while (pos!=queries[idx].size()) {
        int qid = queries[idx][pos].se;
        auto [delta,is_first] = queries[idx][pos].fi;
        upt(qid,delta,is_first,l,r,t,pref);
        ++pos;
    }
}

void solve(){
    cin >> n;
    ffor(i,1,n) {
        cin >> start_mana[i] >> max_mana[i] >> regen[i];
        cap[i] = ((regen[i] == 0) ? LLINF : max_mana[i]/regen[i]);
    }

    IT.init(n);
    cin >> q;
    ffor(i,1,q) {
        int val,l,r; cin >> val >> l >> r;
        IT.update(1,1,n,l,r,val,i);
    }

    resolveQueries(1,1,n);
    ffor(i,1,q){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

