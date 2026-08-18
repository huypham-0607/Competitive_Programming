/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q,x;

struct Matrix {
    bool flag;
    int mat[25];
    Matrix() {
        flag = false;
    }
    Matrix(int val) {
        flag = true;
        frep(i,0,x*x) mat[i] = val;
    }
    Matrix(int s, int d) {
        flag = true;
        frep(i,0,x) {
            frep(j,0,x) {
                int a = i+1;
                int b = d-x+1+j;
                if (a > d || b <= 0) {
                    (*this)(i,j) = INF;
                    continue;
                }
                int delta = abs(b-a);
                (*this)(i,j) = ((delta == 0) ? 0 : (1+(delta-1)/x)*s);
            }
        }
    }

    const int operator() (const int i,const int j) const {
        return mat[i*x + j];
    }

    int& operator() (const int i, const int j) {
        return mat[i*x + j];
    }

    void print(){
        frep(i,0,x) {
            frep(j,0,x) {
                cerr << (*this)(i,j) << " ";
            }
            cerr << endl;
        }
    }
};

Matrix mul(Matrix a, Matrix b) {
    if (!a.flag) return b;
    if (!b.flag) return a;
    // cerr << a.mat.size() << " " << b.mat.size() << endl;
    Matrix res = Matrix(LLINF);
    res.flag = true;
    frep(i,0,x) {
        frep(j,0,x) {
            int mn = LLINF;
            frep(k,0,x) {
                mn = min(mn,b(k,j));
                res(i,j) = min(res(i,j), a(i,k) + mn);
            }
        }
    }
    return res;
}

struct SegmentTree{
    int n;
    vector<Matrix> IT;

    void comb(Matrix& i, Matrix& l, Matrix& r){
        i = mul(l,r);
    }

    Matrix comb_new(Matrix l, Matrix r) {
        Matrix i = mul(l,r);
        return i;
    }

    SegmentTree(int _n, int s[], int d[]) {
        n = _n;
        IT.resize(n*4+10, Matrix());
        build(1,1,n,s,d);
    }

    void build(int idx, int l, int r, int s[], int d[]){
        // cerr << "idx: " << idx << " " << l << " " << r << endl;
        if (l==r){
            IT[idx] = Matrix(s[l],d[l]);
            // cerr << idx << endl;
            // IT[idx].print();
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid,s,d);
        build(idx*2+1,mid+1,r,s,d);
        // cerr << "merge: " << idx << endl;
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int s, int d){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            IT[idx] = Matrix(s,d);

            return;
        }
        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,s,d);
        update(idx*2+1,mid+1,r,x,y,s,d);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    Matrix getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return Matrix();
        if (x <= l && r <= y){
            return IT[idx];
        }

        int mid = (l+r)/2;
        return comb_new(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }

};

int s[N], d[N];

void solve(){
    cin >> n >> q >> x;

    for (int i=1; i<=n; i++){
        cin >> d[i];
    }
    ffor(i,1,n) {
        cin >> s[i];
    }

    SegmentTree IT(n,s,d);

    ffor(i,1,q) {
        char c;
        int a,b;
        cin >> c >> a >> b;
        if (c == '?') {
            Matrix res = IT.getVal(1,1,n,a,b);
            cout << res(0,x-1) << endl;
            // cerr << "i: " << i << endl;
            // res.print(); 
        }
        else if (c == '1') {
            d[a] = b;
            IT.update(1,1,n,a,a,s[a],d[a]);

        }
        else {
            s[a] = b;
            IT.update(1,1,n,a,a,s[a],d[a]);
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

