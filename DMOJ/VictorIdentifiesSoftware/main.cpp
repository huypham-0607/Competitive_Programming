/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "main"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
//#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e12+3;

//Starts here

int n,q;
ll a[N];

struct LazySegmentTree{
    struct Node{
        ll sum;
        int cnt;
        bool isHomo;
        ll val[2];
        int valcnt[2];
        ll valsub[2];
        int type[2];
        ll ans[2];
        int anscnt[2];
        ll anssub;
        Node(){
            sum = -LLINF;
            cnt = 0;
            isHomo = false;
            val[0] = val[1] -LLINF;
            valcnt[0] = valcnt[1] = 0;
            valsub[0] = valsub[1] = -LLINF;
            type[0] = type[1] = -1;
            ans[0] = ans[1] = -LLINF;
            anscnt[0] = anscnt[1] = 0;
            anssub = -LLINF;
        }

        Node(int lmao) {
            sum = -LLINF;
        }

        void debug() {
            cout << sum << " " << cnt << endl;
            cout << isHomo << endl;
            cout << type[0] << " " << type[1] << endl;
            cout << "Val" << endl;
            cout << val[0] << " " << val[1] << endl;
            cout << valcnt[0] << " " << valcnt[1] << endl;
            cout << valsub[0] << " " << valsub[1] << endl;
            cout << "Ans" << endl;
            cout << ans[0] << " " << ans[1] << endl;
            cout << anscnt[0] << " " << anscnt[1] << endl;
            cout << anssub << endl;
        }
    };

    struct LazyNode{
        ll val;
        int type;
        LazyNode(){ 
            val = -LLINF;
            type = -1;
        }
    };

    int n;
    vector<Node> IT;
    vector<LazyNode> lazy;

    void setVal(int idx, ll x) {
        IT[idx].sum = IT[idx].cnt*x;
        IT[idx].val[0] = max(x,IT[idx].valcnt[0]*x);
        IT[idx].val[1] = max(x,IT[idx].valcnt[1]*x);
        IT[idx].valsub[0] = max(x,IT[idx].sum);
        IT[idx].valsub[1] = max(x,IT[idx].sum);
        IT[idx].ans[0] = (IT[idx].anscnt[0] == 0)? -LLINF : max(x,IT[idx].anscnt[0]*x);
        IT[idx].ans[1] = (IT[idx].anscnt[1] == 0)? -LLINF : max(x,IT[idx].anscnt[1]*x);
        IT[idx].anssub = max(x,IT[idx].sum);
        lazy[idx].val = x;
    }

    void setType(int idx, int x) {
        IT[idx].isHomo = true;
        IT[idx].type[0] = IT[idx].type[1] = x;
        IT[idx].valcnt[0] = IT[idx].valcnt[1] = IT[idx].cnt;
        IT[idx].anscnt[x] = IT[idx].cnt;
        IT[idx].anscnt[x^1] = 0;
        IT[idx].val[0] = IT[idx].valsub[0];
        IT[idx].val[1] = IT[idx].valsub[1];
        IT[idx].ans[x] = IT[idx].anssub;
        IT[idx].ans[x^1] = -LLINF;
        lazy[idx].type = x;
    }

    void propagate(int idx){
        //Update idx*2
        if (lazy[idx].val != -LLINF) {
            ll x = lazy[idx].val;

            setVal(idx*2,x);
            setVal(idx*2+1,x);
        }

        
        if (lazy[idx].type != -1) {
            int x = lazy[idx].type;

            setType(idx*2,x);
            setType(idx*2+1,x);
        }
        //Update idx*2+1

        //Reset idx
        lazy[idx] = LazyNode();
    }

    Node comb(Node l, Node r){
        if (l.sum == -LLINF) return r;
        if (r.sum == -LLINF) return l;

        Node i;

        i.sum = l.sum + r.sum;
        i.cnt = l.cnt + r.cnt;

        //isHomo
        if (l.isHomo && r.isHomo && l.type[1] == r.type[0]) i.isHomo = true;
        else i.isHomo = false;

        //type
        i.type[0] = l.type[0];
        i.type[1] = r.type[1];

        //val
        if (l.isHomo) {
            if (l.type[0] == r.type[0]) i.val[0] = max(l.val[0], l.sum + r.val[0]);
            else i.val[0] = l.val[0];
        } else {
            i.val[0] = l.val[0];
        }
        if (r.isHomo) {
            if (l.type[1] == r.type[1]) i.val[1] = max(r.val[1], l.val[1] + r.sum);
            else i.val[1] = r.val[1];
        } else {
            i.val[1] = r.val[1];
        }

        //valcnt
        if (l.isHomo) {
            if (l.type[0] == r.type[0]) i.valcnt[0] = l.valcnt[0] + r.valcnt[0];
            else i.valcnt[0] = l.valcnt[0];
        } else {
            i.valcnt[0] = l.valcnt[0];
        }
        if (r.isHomo) {
            if (l.type[1] == r.type[1]) i.valcnt[1] = l.valcnt[1] + r.valcnt[1];
            else i.valcnt[1] = r.valcnt[1];
        } else {
            i.valcnt[1] = r.valcnt[1];
        }

        //valsub
        i.valsub[0] = max(l.valsub[0], l.sum + r.valsub[0]); 
        i.valsub[1] = max(r.valsub[1], l.valsub[1] + r.sum); 

        //ans
        i.ans[0] = max(l.ans[0],r.ans[0]);
        i.ans[1] = max(l.ans[1],r.ans[1]);
        if (l.type[1] == r.type[0]) {
            int t = l.type[1];
            i.ans[t] = max(i.ans[t], l.val[1] + r.val[0]);
        }

        //anscnt
        i.anscnt[0] = max(l.anscnt[0],r.anscnt[0]);
        i.anscnt[1] = max(l.anscnt[1],r.anscnt[1]);
        if (l.type[1] == r.type[0]) {
            int t = l.type[1];
            i.anscnt[t] = max(i.anscnt[t], l.valcnt[1] + r.valcnt[0]);
        }

        //anssub
        i.anssub = max({l.anssub, r.anssub, l.valsub[1] + r.valsub[0]});

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].isHomo = true;
            IT[idx].sum = a[l];
            IT[idx].cnt = 1;
            IT[idx].val[0] = a[l];
            IT[idx].val[1] = a[l];
            IT[idx].valcnt[0] = 1;
            IT[idx].valcnt[1] = 1;
            IT[idx].valsub[0] = a[l];
            IT[idx].valsub[1] = a[l];
            IT[idx].type[0] = 0;
            IT[idx].type[1] = 0;
            IT[idx].ans[0] = a[l];
            IT[idx].ans[1] = -LLINF;
            IT[idx].anscnt[0] = 1;
            IT[idx].anscnt[1] = 0;
            IT[idx].anssub = a[l];
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void updateVal(int idx, int l, int r, int x, int y, ll val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            setVal(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateVal(idx*2,l,mid,x,y,val);
        updateVal(idx*2+1,mid+1,r,x,y,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void updateType(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            setType(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        updateType(idx*2,l,mid,x,y,val);
        updateType(idx*2+1,mid+1,r,x,y,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    Node getNode(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Node(1);
        if (x <= l && r <= y){
            return IT[idx];
        }

        propagate(idx);

        int mid = (l+r)/2;
        return comb(getNode(idx*2,l,mid,x,y),getNode(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, LazyNode());
        build(1,1,n);
    }
} IT;


void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    IT.init(n);
    for (int i=1; i<=q; i++){
        int id,l,r,val;
        cin >> id >> l >> r;
        if (id == 1) {
            IT.updateType(1,1,n,l,r,0);
        }
        if (id == 2) {
            IT.updateType(1,1,n,l,r,1);
        } 
        if (id == 3){
            cin >> val;
            IT.updateVal(1,1,n,l,r,val);
        }
        if (id == 4) {
            auto node = IT.getNode(1,1,n,l,r);

            // ll res = 0;
            ll res = node.ans[0];
            if (res == -LLINF) cout << "breaks galore" << endl;
            else cout << res << endl;
            // node.debug();
            // cout << endl;
        }
        if (id == 5) {
            auto node = IT.getNode(1,1,n,l,r);

            // ll res = 0;
            ll res = node.ans[1];
            if (res == -LLINF) cout << "breaks galore" << endl;
            else cout << res << endl;
            // node.debug();
            // cout << endl;
        }
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

