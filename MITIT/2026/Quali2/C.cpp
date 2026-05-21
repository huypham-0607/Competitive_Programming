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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int h[N];
int lans[N];
int rans[N];

int getAns(int s) {
    deque<pii> dq;
    dq.push_back({0,0});
    for (int i=1; i<=n; i++){
        lans[i] = lans[i-1] + h[i];
        int cur = i;
        while (dq.back().fi >= h[i]) {
            lans[i] -= (dq.back().fi - h[i])*(cur-dq.back().se);
            cur = dq.back().se;
            dq.pop_back();
        }
        dq.push_back({h[i],cur});
    }

    dq.clear();
    dq.push_back({0,n+1});
    for (int i=n; i>0; i--){
        rans[i] = rans[i+1] + h[i];
        int cur = i;
        while (dq.back().fi >= h[i]) {
            rans[i] -= (dq.back().fi - h[i])*(dq.back().se-cur);
            cur = dq.back().se;
            dq.pop_back();
        }
        dq.push_back({h[i],cur});
    }

    int res = 0;
    for (int i=1; i<=n; i++){
        if (i == s) continue;
        res = max(res,lans[i]+rans[i]-h[i]);
    }
    return res;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> h[i];
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        int tmp = h[i];
        h[i] = INF;
        int res = getAns(i);
        ans = max(ans,res);
        h[i] = tmp;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

