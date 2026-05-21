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

const int N = 2010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int h;
int a[N];
vector<int> lval[N],rval[N];
vector<int> lh[N],rh[N];
vector<int> lpos[N],rpos[N];
int lyay[N], ryay[N]; 

deque<pair<int,pii>> dq;

int calc2(int i, int mxh, int org) {
    // cout << "i: " << i << " " << mxh << " "  << org << endl;

    int lidx = lower_bound(all(lh[i]),mxh) - lh[i].begin();
    int ridx = lower_bound(all(rh[i]),mxh) - rh[i].begin();

    // cout << lidx << " " << ridx << endl;
    // cout << lpos[i][lidx] << " " << rpos[i][ridx];

    int sum = 0;
    if (lidx!=0) sum += lval[i][lidx-1];
    if (ridx!=0) sum += rval[i][ridx-1];

    int lb = (lidx == lval[i].size()) ? 1 : lpos[i][lidx]+1;
    int rb = (ridx == rval[i].size()) ? n : rpos[i][ridx]-1;

    // cout << sum << " " << lb << " " << rb << endl;

    if (rb < lb) {
        // cout << endl;
        return 0;
    }
    sum -= (rb - lb + 1)*(h-mxh) + (h-a[i]);
    // cout << "final sum: " << sum << endl << endl;
    return sum;
}



void solve(){
    cin >> n >> h;

    for (int i=0; i<=n+1; i++){
        lval[i].clear();
        rval[i].clear();
        lh[i].clear();
        rh[i].clear();
        lpos[i].clear();
        rpos[i].clear();
        a[i] = 0;
        lyay[i] = 0;
        ryay[i] = 0;
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    // <height,<sum,pos>>

    int sum = 0;
    dq.clear();
    for (int i=n; i>0; i--){
        while (!dq.empty() && a[i] >= dq.back().fi) {
            sum -= dq.back().se.fi;
            dq.pop_back();
        }
        int prev = (dq.empty()) ? n+1 : dq.back().se.se;
        int val = (prev-i)*(h-a[i]);
        sum += val;
        dq.push_back({a[i],{val,i}});

        ryay[i] = sum;

        for (int idx = dq.size()-1; idx>=0; idx--){
            rh[i].push_back(dq[idx].fi);

            rpos[i].push_back(dq[idx].se.se);
            rval[i].push_back(dq[idx].se.fi);
            if (rval[i].size() > 1) rval[i].back() += rval[i][rval[i].size()-2];
        }
    }

    int ans = 0;

    sum = 0;
    dq.clear();
    for (int i=1; i<=n; i++){
        while (!dq.empty() && a[i] >= dq.back().fi) {
            sum -= dq.back().se.fi;
            dq.pop_back();
        }
        int prev = (dq.empty()) ? 0 : dq.back().se.se;
        int val = (i-prev)*(h-a[i]);
        sum += val;
        dq.push_back({a[i],{val,i}});
        
        lyay[i] = sum;

        for (int idx = dq.size()-1; idx>=0; idx--){
            lh[i].push_back(dq[idx].fi);

            lpos[i].push_back(dq[idx].se.se);
            lval[i].push_back(dq[idx].se.fi);
            if (lval[i].size() > 1) lval[i].back() += lval[i][lval[i].size()-2];
        }
        int idx = 0;
        int mxh = dq.front().fi;
        ans = max(ans,lyay[i] + ryay[i+1]);
        for (int j=1; j<i; j++){
            while (dq[idx].se.se < j) {
                ++idx;
                mxh = dq[idx].fi;
            }
            int res = calc2(j, mxh, i);

            int lmao = lyay[i] + ryay[i+1] + res;
            ans = max(ans,lmao);
        }
    }

    // for (int i=1; i<=n; i++){
    //     for (auto x:lh[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i=1; i<=n; i++){
    //     for (auto x:rh[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i=1; i<=n; i++){
    //     cout << lyay[i] << " " << ryay[i] << endl;
    // }

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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

