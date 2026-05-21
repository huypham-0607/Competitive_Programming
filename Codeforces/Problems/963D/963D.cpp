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

const int N = 1e5+10;
const int SIG = 26;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
string st;
int len[N], to[N][SIG], lnk[N], sz=1;
int id[N], term[N], k[N];
vector<int> pos[N];
int ans[N];
string tmp = "";

void add_str(string s, int sus) {
    int cur = 0;
    // tmp = "";
    for (auto c: s) {
        int idx = c-'a';
        // tmp += ((char) 'a' + idx);
        if (!to[cur][idx]) {
            to[cur][idx] = sz++;
            // cerr << tmp << endl;
            len[to[cur][idx]] = len[cur]+1;
        }
        cur = to[cur][idx];
    }
    term[cur] = cur;
    id[cur] = sus;
}

void push_link() {
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int u = q.front(); q.pop();
        int p = lnk[u];
        if (!term[u]) term[u] = term[p];
        for (int idx = 0; idx < SIG; idx++){
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

void solve(){
    cin >> st >> n;
    for (int i=1; i<=n; i++){
        cin >> k[i];
        string s; cin >> s;
        add_str(s,i);
    }

    push_link();

    // for (int i = 0; i < sz; i++){
    //     cerr << i << " " << lnk[i] << " " << term[i] << endl;
    // }

    int cur = 0;
    for (int i=0; i<st.size(); i++){
        int idx = st[i] - 'a';
        cur = to[cur][idx];
        // cerr << "i: " << i << " " << cur << endl;
        int u = cur;
        while (term[u]!=0) {
            // cerr << term[u] << endl;
            pos[term[u]].push_back(i);
            u = lnk[term[u]];
        }
    }

    for (int i=0; i<sz; i++){
        if (id[i] == 0) continue;
        int delta = k[id[i]];
        ans[id[i]] = INF;
        for (int idx=0; idx<pos[i].size(); idx++){
            if (idx-delta+1 < 0) continue;
            ans[id[i]] = min(pos[i][idx] - pos[i][idx-delta+1] + len[i],ans[id[i]]);
        }
    }

    for (int i=1; i<=n; i++){
        if (ans[i] == INF) cout << -1 << endl;
        else cout << ans[i] << endl;
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

