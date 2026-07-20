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

int n,m;
int val[N];
vector<int> pos[N],neg[N];
int posdeg[N],negdeg[N];

void solve(){
    cin >> n >> m;
    ffor(i,1,n){
        val[i] = 0;
        posdeg[i] = negdeg[i] = 0;
        pos[i].clear();
        neg[i].clear();
    }
    ffor(i,1,m){
        int t,u,v; cin >> t >> u >> v;
        if (t==1){
            posdeg[u]++; posdeg[v]++;
            pos[u].push_back(v);
            pos[v].push_back(u);
        }
        else{
            negdeg[u]++; negdeg[v]++;
            neg[u].push_back(v);
            neg[v].push_back(u);
        }
    }

    queue<pii> q;
    ffor(i,1,n){
        if (!posdeg[i]){
            q.push({i,2});
        }
        else if (!negdeg[i]){
            q.push({i,1});
        }
    }

    int cur = n;

    while (!q.empty()){
        auto [u,t] = q.front(); q.pop();
        if (val[u]) continue;
        if (t == 1){
            val[u] = cur;
        }
        else {
            val[u] = -cur;
        }
        --cur;

        for (auto v:pos[u]){
            if (val[v]) continue;

            --posdeg[v];
            if (!posdeg[v]) q.push({v,2});
        }
        for(auto v:neg[u]){
            if (val[v]) continue;

            --negdeg[v];
            if (!negdeg[v]) q.push({v,1});
        }
    }

    if (cur == 0){
        cout << "YES" << endl;
        ffor(i,1,n){
            cout << val[i] << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;

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

