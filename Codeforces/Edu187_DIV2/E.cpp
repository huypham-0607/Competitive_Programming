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
const int INF = 998244353;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
set<int> st;
vector<int> nen;

struct Fenwick{
    int n;
    int mxlg;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        n = _n;
        mxlg = 0;
        for (int i=1; i<18; i++) {
            if ((1<<i) <= n) ++mxlg;
        }
        BIT.resize(n+10);
    }

    void Init (int _n, int val=0){
        n = _n;
        mxlg = 0;
        for (int i=1; i<18; i++) {
            if ((1<<i) <= n) ++mxlg;
        }
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
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

    int getPos(int x){
        int sum=0;
        int ret=0;
        for(int i=1<<mxlg;i && ret+(i-1)<n;i>>=1)
        {
            if(sum+BIT[ret+(i-1)]<x)
                sum+=BIT[ret+(i-1)],
                ret+=i;
        }
        return ret;
    }
} BIT, BITpos;

namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 2e5;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
            }
        }
    } _init;
}


int a[N];

int getpos(int val) {
    return lower_bound(all(nen),val) - nen.begin()+1;
}

int find(int m) {
    int ave = BIT.getVal(1,n)/m;

    // cout << ave << endl;

    auto org = st.lower_bound(ave);
    int ans = LLINF;

    auto it = org;
    int i = 0;
    for (it = org, i = 0; (it!=st.end() && i!=10); it++, i++) {
        auto l = it;
        auto r = it;
        l--;
        if (it == st.begin()) continue;
        if (++r == st.end())  break;

        int lpos = getpos(*l);
        int rpos = getpos(*r);

        // cout << lpos << " " << rpos << endl;

        int lval = -BIT.getVal(1,lpos) + (*l)*BITpos.getVal(1,lpos);
        int rval = BIT.getVal(rpos, n) - (*r)*BITpos.getVal(rpos, n);

        ans = min(ans,max(lval,rval));
    }

    for (it = org, i = 0; (it!=st.begin() && i!=10); it--, i++) {
        auto l = it;
        auto r = it;
        l--;
        if (it == st.begin()) break;
        if (++r == st.end())  continue;

        int lpos = getpos(*l);
        int rpos = getpos(*r);

        // cout << lpos << " " << rpos << endl;

        int lval = -BIT.getVal(1,lpos) + (*l)*BITpos.getVal(1,lpos);
        int rval = BIT.getVal(rpos, n) - (*r)*BITpos.getVal(rpos, n);

        ans = min(ans,max(lval,rval));
    }
    return ans;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
        
    }
    sort(all(nen));
    BIT.Init(n);
    BITpos.Init(n);
    for (int i=1; i<=n; i++){
        int x = getpos(a[i]);
        st.insert(a[i]);
        BIT.update(x,a[i]);
        BITpos.update(x,1);

        if (i >= 3) {
            int sus = find(i);
            int lmao = ((sus%MD)*Comb::invMod(i-2,MD))%MD;
            // cout << "sus: " <<  sus << " " << i-2 << endl;
            cout << lmao << endl;
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

