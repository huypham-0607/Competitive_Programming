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
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int cnt[31];
int tin[31];

void ask(int x) {
    cout << "? " << x << endl;
    cout.flush();
}

void answer(int x, vector<pii>& edges) {
    cout << "! " << x << endl;
    for (auto [x,y]:edges) {
        cout << x << " " << y << endl;
    }
    cout.flush();
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cnt[i] = 0;
        tin[i] = 0;
    }
    vector<pii> edges;
    vector<int> nodes;
    int pivot = 1;
    pii prev = {1,0};


    vector<int> st;

    tin[1] = 1;
    st.push_back(1);
    int q = 0;

    int cur = 2;

    do {
        ask(cur);
        cin >> q;
        nodes.clear();
        for (int i=0; i<q; i++){
            int x; cin >> x;
            nodes.push_back(x);
        }
        if (q == 0) break;
        while (st.size() >= q) {
            int x = st.back();
            cnt[x] = cur - tin[x];
            st.pop_back();
        }

        int u = nodes.back();
        if (q>1) {
            int v = nodes[q-2];
            edges.push_back({v,u});
        }
        if (!tin[u]) {
            tin[u] = cur;
            st.push_back(u);
            cur++;
        }
        else {
            cur += cnt[u];
        }
        // cout << "Stack: " << endl;
        // for (int i = 0; i < st.size(); i++){
        //     cout << st[i] << " ";
        // }
        // cout << endl;
    } while (q);

    answer(edges.size(), edges);
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

