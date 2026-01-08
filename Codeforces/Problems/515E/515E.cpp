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

struct SegmentTree{
    struct Node{
        int sum,pre,suf,ans;
        Node(){
            sum = 0;
            pre = 0;
            suf = 0;
            ans = 0;
        }
    };

    int n;
    vector<Node> IT;

    Node comb(Node l, Node r){
        if (l.sum == 0) return r;
        if (r.sum == 0) return l;

        Node i;
        i.sum = l.sum + r.sum;
        i.pre = max(l.pre,r.pre + l.sum);
        i.suf = max(r.suf,l.suf + r.sum);
        i.ans = max({l.ans,r.ans,l.suf + r.pre});

        return i;
    }

    void build(int idx, int l, int r, vector<int>& d, vector<int>& h){
        if (l==r){
            IT[idx].sum = d[l];
            IT[idx].pre = 2*h[l];
            IT[idx].suf = 2*h[l] + d[l];
            IT[idx].ans = 0;

            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid,d,h);
        build(idx*2+1,mid+1,r,d,h);
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

    SegmentTree(int _n, vector<int>& d, vector<int>& h){
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n,d,h);
    }
};


int n,q;
vector<int> d,h;

void solve(){
    cin >> n >> q;
    d.resize(n+10);
    h.resize(n+10);
    for (int i=1; i<=n; i++){
        cin >> d[i];
    }
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }
    SegmentTree IT(n,d,h);
    while (q--){
        int l,r; cin >> l >> r;
        if (l > r) {
            auto node = IT.getNode(1,1,n,r+1,l-1);
            cout << node.ans << endl;
        }
        else {
            auto node1 = IT.getNode(1,1,n,r+1,n);
            auto node2 = IT.getNode(1,1,n,1,l-1);
            auto node = IT.comb(node1,node2);
            cout << node.ans << endl;
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

