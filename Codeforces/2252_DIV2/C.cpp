/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>
#include <queue>

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

int n,m;
int sta[N];
int pref_min[N];

void solve(){
    cin >> n >> m;
    pref_min[0] = INF;
    ffor(i,1,n){
        cin >> sta[i];
        pref_min[i] = min(pref_min[i-1],sta[i]);
    }
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    ffor(i,1,n){
        ffor(j,1,m){
            cin >> v[i][j];
        }
    }

    priority_queue<int,vector<int>,greater<int>> current;
    priority_queue<int> next;

    int t = 0;
    int ans = m;
    rfor(i,n,1){
        ffor(j,1,m){
            next.push(v[i][j]);
        }

        while (!next.empty() && !current.empty() && current.top() < next.top()){
            t -= current.top();
            t += next.top();

            int tmp = current.top(); current.pop();
            current.push(next.top()); next.pop();
            next.push(tmp);
        }

        while (!current.empty() && t - current.top() >= pref_min[i]) {
            t-=current.top();
            next.push(current.top()); current.pop();
        }

        while (!next.empty() && t < pref_min[i]){
            t += next.top();

            current.push(next.top()); next.pop();
        }

        // cout << i << " " << ((current.empty())?-1:current.top()) << endl;

        if (t >= pref_min[i]){
            ans = min(ans,(int)current.size());
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

