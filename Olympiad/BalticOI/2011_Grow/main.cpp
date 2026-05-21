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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<int> BIT;

void Init (int _n, int val=0){
    n = _n;
    BIT.resize(n+10,0);
}

void updatePoint(int idx, int val){
    while (idx<=n){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

void update(int l, int r, int val) {
    updatePoint(l,val);
    updatePoint(r+1,-val);
}

int getVal(int idx){
    int res = 0;
    while (idx>0){
        res+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return res;
}

int fwlb(int val) {
    int res = n+1;
    int l = 1, r = n;
    while (l<=r) {
        int mid = (l+r)/2;
        int x = getVal(mid);
        if (x >= val) {
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
        // cerr << l << " " << r << " " << mid << " " << res << endl;
    }
    return res;
} 

int m;
int a[N];

void solve(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    Init(n);
    for (int i=1; i<=n; i++){
        update(i,i,a[i]);
    }

    for (int i=1; i<=m; i++){
        // cerr << "Query: " << i << endl;
        // for (int idx=1; idx<=n; idx++){
        //     cerr << getVal(idx) << " ";
        // }
        // cerr << endl;
        char chr; 
        int c,h;
        cin >> chr >> c >> h;
        if (chr == 'C') {
            int l = fwlb(c);
            int r = fwlb(h+1);
            cout << r-l << endl;
        }
        else {
            int x = fwlb(h);
            if (x > n) continue;
            int y = min(n,x+c-1);
            if (y == n) {
                update(x,y,1);
                continue;
            }

            // cerr << x << " " << y << endl;

            int val = getVal(y);
            // cerr << val << endl;
            int l = fwlb(val);
            int r = fwlb(val+1);
            // cerr << l << " " << r << endl;
            update(x,l-1,1);
            update(r-c+(l-x),r-1,1);
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

