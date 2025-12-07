/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 550;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1,tst;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    for (tst=1; tst<=test; tst++) solve();
}

/*Global Variables*/
int n;
int row[N],col[N];
int vis[N][N];
priority_queue<piii,vector<piii>,greater<piii>> edge;

void check(int i, bool rawr){
    for (int j=1; j<=n; j++){
        if (rawr){
            if (!vis[j][i]){
                edge.push({0,{j,i}});
            }
        }
        else{
            if (!vis[i][j]){
                edge.push({0,{i,j}});
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    int x;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> x;
            vis[i][j] = false;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> x;
            edge.push({x,{i,j}});
        }
    }
    for (int i=1; i<=2; i++){
        for (int i=1; i<=n; i++){
            row[i] = n;
            col[i] = n;
            cin >> x;
        }
    }
//    cout << endl;
    int ans = 0;
    while (!edge.empty()){
        int w = edge.top().fi;
        int i = edge.top().se.fi;
        int j = edge.top().se.se;

        edge.pop();

        if (vis[i][j]) continue;
        vis[i][j] = true;
        ans+=w;

//        cout << i << " " << j << " " << w << endl;

        row[i]--;
        if (row[i] == 1) check(i,0);
        col[j]--;
        if (col[j] == 1) check(j,1);
    }
    cout << "Case #" << tst << ": " << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}

