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
int a[N];
vector<pair<int,pii>> ans;

void recur(int x, int from, int to, int thru) {
    if (x==0) return;
    if (a[x] == 0) {
        recur(x-1,from,thru,to);
        ans.push_back({x,{from,to}});
        recur(x-1,thru,to,from);
    }
    else {
        recur(x-a[x]-1,from,thru,to);
        ans.push_back({x,{from,to}});
        recur(x-a[x]-1,thru,from,to);
        recur(x-1,from,to,thru);
    }
}

void solve(){
    cin >> n;
    ans.clear();
    ffor(i,1,n) {
        cin >> a[i];
    }
    ffor(i,1,n) {
        if (a[i] > i-1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    recur(n,1,3,2);
    cout << ans.size() << endl;
    for (auto [x,in]:ans) {
        cout << x << " " << in.fi << " " << in.se << endl;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

