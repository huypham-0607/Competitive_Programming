/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 5e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
vector<vector<vector<int>>> adj;
string ans = "";

void DFS(int lvl, int u){
    if (lvl != 0) ans+="(";
    for (int i=(int)adj[lvl][u].size()-1; i>=0; i--){
        int v = adj[lvl][u][i];
        DFS(lvl+1,v);
    }
    if (lvl!=0) ans+=")";
}

/*Solution*/
void solve(){
    string s; cin >> s;
    n = (int)s.size();
    int idx = 0;
    int prevcnt = 0;
    int curcnt = 0;
    int lvl = 0;
    adj.push_back(vector<vector<int>>(1,vector<int>()));
    for (int i=0; i<n; i++){
        if (s[i] == '('){
            ++curcnt;
            adj[lvl][idx].push_back(curcnt-1);
        }
        else{
            if (idx+1 >= prevcnt){
                adj.push_back(vector<vector<int>>(curcnt,vector<int>()));
                ++lvl;
                prevcnt = curcnt;
                curcnt = 0;
                idx = -1;
            }
            ++idx;
        }
    }

    DFS(0,0);
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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
