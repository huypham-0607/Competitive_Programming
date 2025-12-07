/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
string s,x,y;
set<string> st;
set<string> rawr;
vector<string> v;

void DFS(string & org, string& s, int idx, int lvl, bool ver){
    if (lvl > n){
        if (ver) st.insert(s);
        else{
            if (rawr.find(s)==rawr.end()){
                if (st.find(s)==st.end()) v.push_back(s);
                rawr.insert(s);
            }
        }
        return;
    }
    if (idx >= (int)org.size()) return;
    for (int i=idx; i<(int)org.size(); i++){
        s+=org[i];
        DFS(org,s,i+1,lvl+1,ver);
        s.pop_back();
    }
}

/*Solution*/
void solve(){
    cin >> m >> n >> k;
    cin >> x >> y;
    DFS(y,s,0,1,true);
    DFS(x,s,0,1,false);
    sort(v.begin(),v.end());
    for (int i=1; i<=m; i++){
        cin >> s;
        int idx = lower_bound(v.begin(),v.end(),s)-v.begin();
        if (idx == v.end()-v.begin() || v[idx]!=s) cout << -1 << endl;
        else cout << (idx+1)%k << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
