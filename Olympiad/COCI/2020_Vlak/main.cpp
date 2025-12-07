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
int n,m;
bool exist[26];
vector<int> a[N][26];
bool vis[N][26];
bool ans[N][26];

bool DFS(int i, int f){
    bool res = true;
    for (auto idx:a[i][f]){
        if (vis[i+1][idx]) res = (res && (!ans[i+1][idx]));
        else res = (res && (!DFS(i+1,idx)));
    }
    vis[i][f] = true;
    ans[i][f] = res;
//    cout << i << " " << char(f+'a') << " " << res << endl;
    return res;
}

/*Solution*/
void solve(){
    string s;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> s;
        exist[s[0]-'a'] = true;
        for (int j=1; j<(int)s.size(); j++){
            if (j%2==0){
                a[j-1][s[j-1]-'a'].push_back(s[j]-'a');
            }
        }
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        cin >> s;
        for (int j=0; j<(int)s.size(); j++){
            if (j%2){
                a[j-1][s[j-1]-'a'].push_back(s[j]-'a');
            }
        }
    }
    bool verify = 0;
    for (int i=0; i<26; i++){
        if (exist[i]){
            verify = (DFS(0,i) || verify);
        }
    }
    if (verify) cout << "Nina" << endl;
    else cout << "Emilija" << endl;
}


/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
