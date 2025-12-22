/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "446B"

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

const int N = 1e3+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,k,p;
int a[N][N];
int rowval[1000000+10];
int colval[1000000+10];

void solve(){
    cin >> n >> m >> k >> p;
    priority_queue<pii> pq;
    for (int i=1; i<=n; i++){
        int val = 0;
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            val += a[i][j];
        }
        pq.push({val,i});
    }
    
    int t = 0;
    for (int idx=1; idx<=k; idx++){
        auto [val,i] = pq.top();
        pq.pop();
        t += val;
        rowval[idx] = t;
        val -= p*m;
        pq.push({val,i});
    }

    while (!pq.empty()) pq.pop();
    for (int j=1; j<=m; j++){
        int val = 0;
        for (int i=1; i<=n; i++){
            val += a[i][j];
        }
        pq.push({val,j});
    }
    t = 0;
    for (int idx=1; idx<=k; idx++){
        auto [val,j] = pq.top();
        pq.pop();
        t += val;
        colval[idx] = t;
        val -= p*n;
        pq.push({val,j});
    }

    int ans = -LLINF;
    // for (int i=1; i<=k; i++){
    //     cout << rowval[i] << " " << colval[i] << endl;
    // }

    for (int i=0; i<=k; i++){
        int j = k-i;
        int val = rowval[i] + colval[j] -i*j*p;
        ans = max(ans,val);
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

