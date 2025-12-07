/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct SegmentTree{
    struct Node{
        int val;
        Node(){
            val = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.val == 0) return r;
        if (r.val == 0) return l;

        Node i;
        i.val = max(l.val, r.val);

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = INF;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].val = val;
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val);
        update(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }
};

int n;
int crit[N], a[N], pre[N], occ[N];
map<pii,int> mp;
vector<pair<pii,pii>> query;
vector<pii> lst;
int ans[N];

void addElement(pii x, int t) {
    auto it = mp.lower_bound(x);

    auto previt = it;
    if (it!=mp.begin()) --previt;

    if (it != mp.begin() && it!=mp.end()) {
        pii cur = it->fi;
        pii prev = previt->fi;
        int delta = t - previt->se;
        lst.push_back({prev.se, (cur.fi - prev.fi)*(delta)});
        previt->se = t;
    }
    mp[x] = t;
}

void delElement(pii x, int t) {
    auto it = mp.find(x);

    auto lit = it, rit = it;
    if (it!=mp.begin()) lit--;
    if (it!=mp.end()) rit++;

    if (it != mp.begin()) {
        pii cur = it->fi;
        pii prev = lit->fi;
        int delta = t - lit->se;
        lst.push_back({prev.se, (cur.fi - prev.fi)*(delta)});
        lit->se = t;
    }

    if (rit != mp.end()) {
        pii cur = rit->fi;
        pii prev = it->fi;
        int delta = t - it->se;
        lst.push_back({prev.se, (cur.fi - prev.fi)*(delta)});
        it->se = t;
    }

    mp.erase(it);
}

void getHead(int val) {
    auto it = mp.begin();
    if (it == mp.end()) return;
    int delta = it->fi.fi;

    lst.push_back({val,delta});
}

void getTail(int val, int pos) {
    auto it = mp.end();
    if (it == mp.begin()){
        lst.push_back({val,pos});
        return;
    }
    --it;
    int delta = pos - it->fi.fi;

    lst.push_back({val,delta});
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ++a[i];
    }
    SegmentTree IT;
    IT.init(n);

    for (int i=n; i>0; i--){
        if (a[i] == 1) {
            crit[i] = i;
        }
        else {
            SegmentTree::Node tmp = IT.getNode(1,1,n,1,a[i]-1);
            crit[i] = tmp.val;
        }
        IT.update(1,1,n,a[i],i);
    }

    for (int i=1; i<=n; i++) {
        if (pre[a[i]]) {
            int j = pre[a[i]];
            if (crit[j] < i) {
                query.push_back({{crit[j],0},{j,a[i]}});
                query.push_back({{i,-1},{j,a[i]}});
            }
        }
        pre[a[i]] = i;
    }
    for (int val=1; val<=n; val++) {
        if (pre[val]) {
            int j = pre[val];
            if (crit[j] <= n) {
                query.push_back({{crit[j],0},{j,val}});
                query.push_back({{n+1,-1},{j,val}});
            }
        }
    }

    sort(all(query));

    int idx = 0;
    int mex = 1;
    for (int i=1; i<=n+1; i++) {
        while (idx!=(int)query.size() && query[idx].fi.fi == i) {
            auto in = query[idx];
            ++idx;
            int t = in.fi.fi;
            int op = in.fi.se;
            pii key = in.se;

            if (op == 0) {
                addElement(key,t);
            }
            else {
                delElement(key,t);
            }
        }
        if (i!=n+1){
            occ[a[i]]++;
            while (occ[mex]) mex++;
            getHead(mex);
            getTail(1,i);
        }
    }

    for (auto [val,cnt]:lst) {
        ans[val]+=cnt;
    }

    for (int i = 1; i <= n+1; i++) {
        cout << ans[i] << " ";
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

