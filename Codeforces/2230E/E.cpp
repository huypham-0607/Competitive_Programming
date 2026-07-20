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

const int N = 4e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e16+3;

struct SegmentTree{
    struct Node{
        int poly,cul,mixed;
        Node(){
            poly = cul = mixed = LLINF;
        }
    };

    int n;
    vector<Node> IT;

    void comb(Node& i, Node& l, Node& r){
        i.poly= min(l.poly,r.poly);
        i.cul=min(l.cul,r.cul);
        i.mixed=min(l.mixed,r.mixed);
    }

    void init(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx] = Node();
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int val1, int val2){
        if (r < x || x < l) return;
        if (l==r){
            IT[idx].poly = min(IT[idx].poly,val1);
            IT[idx].cul = min(IT[idx].cul,val2);
            IT[idx].mixed = min(IT[idx].mixed,val1+val2);
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,val1,val2);
        update(idx*2+1,mid+1,r,x,val1,val2);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    int getPoly(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return LLINF;
        if (x <= l && r <= y){
            return IT[idx].poly;
        }

        int mid = (l+r)/2;
        return min(getPoly(idx*2,l,mid,x,y),getPoly(idx*2+1,mid+1,r,x,y));
    }
    int getCul(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return LLINF;
        if (x <= l && r <= y){
            return IT[idx].cul;
        }

        int mid = (l+r)/2;
        return min(getCul(idx*2,l,mid,x,y),getCul(idx*2+1,mid+1,r,x,y));
    }
    int getMixed(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return LLINF;
        if (x <= l && r <= y){
            return IT[idx].mixed;
        }

        int mid = (l+r)/2;
        return min(getMixed(idx*2,l,mid,x,y),getMixed(idx*2+1,mid+1,r,x,y));
    }
} IT;


int n,m;
int poly[N], cul[N];
int poly_tol[N], cul_tol[N];
int delta[N];

int ans[N];

vector<pair<pii,pair<int,pii>>> query;
vector<int> nen;

void compute() {
    ffor(i,1,n) {
        int x = lower_bound(all(nen),poly[i])-nen.begin()+1; 
        int y = lower_bound(all(nen),cul[i])-nen.begin()+1;
        query.push_back({{y,0},{x,{poly[i],cul[i]}}});
    }

    ffor(i,1,m) {
        int x = lower_bound(all(nen),poly_tol[i])-nen.begin()+1;
        int y = lower_bound(all(nen),cul_tol[i])-nen.begin()+1;
        int y2 = lower_bound(all(nen),cul_tol[i]+delta[i])-nen.begin()+1;
        int x2 = lower_bound(all(nen),poly_tol[i]+delta[i])-nen.begin()+1;
        query.push_back({{y-1,i},{(int)nen.size(),{0,0}}});
        query.push_back({{nen.size(),i},{(int)nen.size(),{0,cul_tol[i]+delta[i]}}});
        query.push_back({{nen.size(),i},{x-1,{1,0}}});
        query.push_back({{nen.size(),i},{(int)nen.size(),{1,poly_tol[i]+delta[i]}}});
        query.push_back({{y2,i},{x2,{2,0}}});
    }

    // for (auto x:nen) cout << x << " "; cout << endl;

    int idx = 0;
    sort(all(query));
    // while (idx!=query.size() && query[idx].fi.fi == 0) ++idx;
    for (int i=1; i<=nen.size(); i++){
        // cerr << i << " " << query[idx].fi.fi << endl;
        while (idx!=query.size() && query[idx].fi.fi <= i) {
            auto in = query[idx];
            ++idx;

            int x = in.se.fi;
            int y = in.fi.fi;
            int t1 = in.fi.se;
            int t2 = in.se.se.fi;
            int val = in.se.se.se;

            // if (t1 == 0) cout << "news: " <<  x << " " << y << " " << t1 << " " << t2 << " " << val << endl;

            if (t1 == 0){ 
                IT.update(1,1,nen.size(),x,t2,val);
            }
            else {
                if (t2 == 0) {
                    int tmp = IT.getPoly(1,1,nen.size(),1,x);
                    if (tmp == LLINF) continue;
                    tmp = min(tmp,poly_tol[t1]+delta[t1]);
                    if (tmp < poly_tol[t1]) tmp = 0;
                    // cout << "t2 = " << t2 << ": " << t1 << " " << x << " " << y << " " << val << " " << tmp << endl;
                    ans[t1] = min(ans[t1],val + tmp);
                }
                else if (t2 == 1) {
                    int tmp = IT.getCul(1,1,nen.size(),1,x);
                    if (tmp == LLINF) continue;
                    tmp = min(tmp,cul_tol[t1]+delta[t1]);
                    if (tmp < cul_tol[t1]) tmp = 0;
                    // cout << "t2 = " << t2 << ": " << t1 << " " << x << " " << y << " " << val << " " << tmp << endl;
                    ans[t1] = min(ans[t1],val + tmp);
                }
                else {
                    ans[t1] = min(ans[t1],val + IT.getMixed(1,1,nen.size(),1,x));
                    // cout << "t2 = " << t2 << ": " << t1 << " " << x << " " << y << " " << IT.getMixed(1,1,nen.size(),1,x) << endl;

                }
            }
        }
    }
}

void solve(){
    nen.clear();
    cin >> n;
    ffor(i,1,n) cin >> poly[i];
    ffor(i,1,n) cin >> cul[i];
    ffor(i,1,n) {
        nen.push_back(poly[i]);
        nen.push_back(cul[i]);
    }
    cin >> m;

    ffor(i,1,m) {
        cin >> poly_tol[i];
        nen.push_back(poly_tol[i]);
    }
    ffor(i,1,m) {
        cin >> cul_tol[i];
        nen.push_back(cul_tol[i]);
    }
    ffor(i,1,m) {
        cin >> delta[i];
        nen.push_back(poly_tol[i]+delta[i]);
        nen.push_back(cul_tol[i]+delta[i]);
    }

    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());

    ffor(i,1,m){ 
        ans[i] = poly_tol[i] + cul_tol[i] + 2*delta[i];
    }

    query.clear();
    IT.init(nen.size());
    compute();
    ffor(i,1,m){
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

