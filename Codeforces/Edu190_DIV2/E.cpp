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
const long long LLINF = 1e18+3;

//Starts here

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        n = _n+1;
        BIT.resize(n+10);
    }

    void Init (int _n, int val=0){
        n = _n+1;
        BIT.clear();
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        ++idx;
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        ++idx;
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)-getPoint(l-1));
    }
};

int n,m;
int p[N],c[N],tp[N],tc[N],d[N];

void solve(){
    cin >> n;
    ffor(i,1,n) cin >> p[i];
    ffor(i,1,n) cin >> c[i];
    cin >> m;
    ffor(i,1,m) cin >> tp[i];
    ffor(i,1,m) cin >> tc[i];

    Fenwick pubval((int)1e6), pcnt((int)1e6);
    Fenwick cubval((int)1e6), ccnt((int)1e6);

    ffor(i,1,m) {
        cin >> d[i];
        if (tp[i]+d[i] < (int)1e6) {
            pubval.update(tp[i]+d[i]+1,tp[i]+d[i]);
        }
        pcnt.update(tp[i],1);
        if (tp[i]+d[i]<(int)1e6) pcnt.update(tp[i]+d[i]+1,-1);

        if (tc[i]+d[i] < (int)1e6) {
            cubval.update(tc[i]+d[i]+1,tc[i]+d[i]);
        }
        ccnt.update(tc[i],1);
        if (tc[i]+d[i]<(int)1e6) ccnt.update(tc[i]+d[i]+1,-1);
        cout << tp[i] << " " << tp[i] + d[i] << " " << tc[i] << " " << tc[i] + d[i] << endl;
    }
    
    int ans = LLINF;
    for (int i=1; i<=n; i++){
        int val = 0;
        val += pubval.getVal(1,p[i]);
        val += cubval.getVal(1,c[i]);
        val += pcnt.getVal(1,p[i])*p[i];
        val += ccnt.getVal(1,c[i])*c[i];
        cout << i << " " << val << endl;
        cout << pubval.getVal(1,p[i]) << " " << cubval.getVal(1,c[i]) << " "
            << pcnt.getVal(1,p[i]) << " " << ccnt.getVal(1,c[i]) << endl;
        ans = min(ans,val);
    }
    cout << ans << endl;
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

