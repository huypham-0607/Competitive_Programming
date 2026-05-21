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

const int N = 5e5+10;
const int SIG = 26;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
string st;
int len[N], to[N][SIG], lnk[N], sz = 1;
int cnt[N];
int ans[N];
vector<int> id[N];

void add_str(string s, int sus) {
    int cur = 0;
    for (auto c: s) {
        int idx = c-'a';
        if (!to[cur][idx]) {
            to[cur][idx] = sz++;
            len[to[cur][idx]] = len[cur]+1;
        }
        cur = to[cur][idx];
    }
    id[cur].push_back(sus);
}

void push_link() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int p = lnk[u];

        frep(idx,0,SIG){
            if (to[u][idx]) {
                lnk[to[u][idx]] = (u) ? to[p][idx] : 0;
                q.push(to[u][idx]);
            }
            else {
                to[u][idx] = to[p][idx];
            }
        }
    }
}

string pref;

void DFS(int cur) {
    // cout << pref << endl;
    frep(idx, 0, SIG) {
        if (len[to[cur][idx]] > len[cur]) {
            // pref.push_back((char)'a'+idx);
            DFS(to[cur][idx]);
            // pref.pop_back();
            cnt[cur] += cnt[to[cur][idx]];
        }
    }
    for (auto pos:id[cur]) {
        if (cnt[cur]) ans[pos] = 1;
    }
}

void solve(){
    cin >> st;
    cin >> n;
    for (int i=1; i<=n; i++){
        string s; cin >> s;
        add_str(s,i);
    }
    push_link();

    int cur = 0;
    for (int i=0; i<st.size(); i++){
        int idx = st[i] - 'a';
        cur = to[cur][idx];
        // cout << i << " " << cur << endl;
        ++cnt[cur];
    }

    DFS(0);

    priority_queue<pii> pq;
    frep(i,0,sz){
        // cout << i << " " << lnk[i] << endl;
        pq.push({len[i],i});
    }

    while (!pq.empty()) {
        int cur = pq.top().se; pq.pop();
        if (cnt[cur]) {
            for (auto x:id[cur]) {
                ans[x] = 1;
            }
        }
        if (cur) cnt[lnk[cur]] += cnt[cur];
    }

    ffor(i,1,n){
        if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
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

