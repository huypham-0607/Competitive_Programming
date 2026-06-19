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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e13+3;

//Starts here

int n,m;
int a[N];

struct SegmentTree{
    int n;
    vector<int> IT;

    SegmentTree(int _n) {
        n = _n;
        IT.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        IT[idx]= 0;
        if (l==r){
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (r < x || y < l) return;
        if (x <= l && r <= y){
            IT[idx] = min(IT[idx],val);
            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
    }

    int getVal(int idx, int l, int r, int x){
        if (x < l || r < x) return INF;
        if (l==r){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return min({IT[idx],getVal(idx*2,l,mid,x),getVal(idx*2+1,mid+1,r,x)});
    }
};

void solve(){
    cin >> n>>m;
    ffor(i,1,n) cin >> a[i];
    SegmentTree IT(n);
    for (int i=1; i<=n; i++){
        if (i>m) {
            int val = IT.getVal(1,1,n,i-m);
            IT.update(1,1,n,i-m+1,min(n,i+1),val);
        }
        if (i-a[i]+1>0) {
            int val = IT.getVal(1,1,n,i-a[i]+1)-1;
            IT.update(1,1,n,i-a[i]+1,i-a[i]+1,val);
            if (i<n) IT.update(1,1,n,i+1,i+1,val);
        }
        if (i<n) {
            int val = IT.getVal(1,1,n,i);
            IT.update(1,1,n,i+1,i+1,val);
        }
    }

    cout << IT.getVal(1,1,n,n-m+1)+n << endl;
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

