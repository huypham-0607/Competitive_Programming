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

const int N = 6010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int a[N];
int anst[N];
int freq[N];

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int dcnt = 0;
    deque<pii> mxdq, mndq;
    for (int delta = 1; delta<=n/2; delta++){
        for (int i=1; i<=n; i++){
            anst[i] = 0;
            freq[i] = 0;
        }
        dcnt = 0;
        mxdq.clear();
        mndq.clear();
        for (int i=1; i<=n; i++){
            freq[a[i]]++;
            if (freq[a[i]] == 2) ++dcnt;
            if (i-delta > 0) {
                if (freq[a[i-delta]] == 2) --dcnt;
                freq[a[i-delta]]--;
            }

            while (!mxdq.empty() && mxdq.front().se <= i-delta) mxdq.pop_front();
            while (!mndq.empty() && mndq.front().se <= i-delta) mndq.pop_front();
            while (!mxdq.empty() && mxdq.back().fi<a[i]) mxdq.pop_back();
            mxdq.push_back({a[i],i});
            while (!mndq.empty() && mndq.back().fi>a[i]) mndq.pop_back();
            mndq.push_back({a[i],i});

            if (i >= delta && dcnt == 0 && mxdq.front().fi - mndq.front().fi == delta-1) {
                anst[mxdq.front().fi] = 1;
            }
        }
        for (int i=1; i<=n-delta; i++){
            if ((anst[i]) && (anst[i+delta])) {
                ans = delta;
            }
        }
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

