/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;

ll summ(int x) {
    return 1LL*x*(x+1)/2;
}

struct SegmentTree{
    struct Node{
        int cnt,mx;
        int pref,suf;
        int sum;
        Node(){
            cnt = 0;
            mx = 0;
            pref = 0;
            suf = 0;
            sum = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (r.sum == 0) return l;
        if (l.sum == 0) return r;
        
        Node i;
        i.sum = l.sum + r.sum;
        if (l.mx > r.mx) {
            i.pref = l.pref;
            i.suf = 0;
            i.mx = l.mx;
            i.cnt = l.cnt;
        }
        else if (r.mx > l.mx) {
            i.pref = 0;
            i.suf = r.suf;
            i.mx = r.mx;
            i.cnt = r.cnt;
        }
        else {
            i.mx = l.mx;
            i.cnt = l.cnt + r.cnt;
            i.cnt += summ(l.suf+r.pref) - summ(l.suf) - summ(r.pref);
            i.pref = l.pref + ((l.pref == l.sum) ? r.pref : 0);
            i.suf = r.suf + ((r.suf == r.sum) ? l.suf : 0);
        }
        return i;
    }

    void init(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].mx = 0;
            IT[idx].cnt = 1;
            IT[idx].pref = 1;
            IT[idx].suf = 1;
            IT[idx].sum = 1;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void add(int idx, int l, int r, int x, int val){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].mx = val;
            IT[idx].cnt = 1;
            IT[idx].sum = IT[idx].pref = IT[idx].suf = 1;
            return;
        }
        int mid = (l+r)/2;
        add(idx*2,l,mid,x,val);
        add(idx*2+1,mid+1,r,x,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void rem(int idx, int l, int r, int x){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].mx = 0;
            IT[idx].cnt = 1;
            IT[idx].sum = IT[idx].pref = IT[idx].suf = 1;
            return;
        }
        int mid = (l+r)/2;
        rem(idx*2,l,mid,x);
        rem(idx*2+1,mid+1,r,x);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }
} IT;

set<int> st[N];
int a[N];

void solve(){
    cin >> n >> q;
    IT.init(n);
    for (int i=1; i<=n; i++){
        cin >> a[i];
        st[a[i]].insert(i);
    }

    for (int i=1; i<=n; i++){
        if (!st[i].size()) continue;
        int pos = (*st[i].begin());
        int delta = (*st[i].rbegin()-pos);
        IT.add(1,1,n,pos,delta);
    }

    for (int i=1; i<=q; i++){
        int x,w; cin >> x >> w;
        // cout << "query: " << x << " " << w << endl;
        int pos,delta;

        int idx = a[x];
        pos = (*st[idx].begin());
        // cout << pos << endl;
        IT.rem(1,1,n,pos);

        st[idx].erase(x);
        if (st[idx].size()) {
            pos = (*st[idx].begin());
            delta = (*st[idx].rbegin()-pos);
            // cout << pos << " " << delta << endl;  
            IT.add(1,1,n,pos,delta);
        }

        idx = w;
        if (st[idx].size()) {
            pos = (*st[idx].begin());
            // cout << pos << endl;
            IT.rem(1,1,n,pos);
        }

        st[w].insert(x);
        pos = (*st[idx].begin());
        delta = (*st[idx].rbegin()-pos);
        // cout << pos << " " << delta << endl;
        IT.add(1,1,n,pos,delta);

        a[x] = w;

        auto node = IT.IT[1];
        if (node.mx == 0) {
            cout << 0 << " " << 0 << endl;
        }
        else {
            cout << node.mx << " " << node.cnt << endl;
        }
    }

    for (int i=1; i<=n; i++){
        st[i].clear();
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

