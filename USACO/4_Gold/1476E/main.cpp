/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,k;
vector<int> adj[N],order;
map<string,int> mp;
int deg[N];
queue<int> q;
string tmp[N];

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    string s;
    for (int i=1; i<=n; i++){
        cin >> s;
        mp[s] = i;
        tmp[i] = s;
    }
    vector<int> lst;
    for (int i=1; i<=m; i++){
        lst.clear();
        int x;
        bool ver = 0;
        cin >> s >> x;

        for (int mask=0; mask<16; mask++){
            string s2 = s;
            for (int lg=0; lg<4; lg++){
                if (mask&(1<<lg)) s2[lg] = '_';
            }
            if (tmp[x] == s2) ver = 1;
            if (mp.count(s2)) lst.push_back(mp[s2]);
        }

        if (!ver){
            cout << "NO" << endl;
            return;
        }
        for (auto y:lst){
            if (x==y) continue;
            adj[x].push_back(y);
            ++deg[y];
        }
    }
    for (int i=1; i<=n; i++){
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();

        order.push_back(u);
        for (auto v:adj[u]){
            --deg[v];
            if (!deg[v]) q.push(v);
        }
    }
    if ((int)order.size()!=n){
        cout << "NO" << endl;
        return;
    }
    else{
        cout << "YES" << endl;
        for (auto x:order){
            cout << x << " ";
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
