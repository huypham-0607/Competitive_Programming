#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ROBOT"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,m,q;
vector<pii> query;
vector<vector<int>> a;

/*Inititalization*/
void Init(){
    cin >> n >> m >> q;
    a.resize(n+10,vector<int> (m+10));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for (int i=1; i<=q; i++){
        int x,y; cin >> x >> y;
        query.push_back({x,y});
    }
}

/*Subtask1*/
bool CheckSub1(){
    return true;
}

vector<vector<int>> dp;
vector<vector<bool>> banned;

void SolveSub1(){
    dp.resize(n+10,vector<int> (m+10));
    banned.resize(n+10,vector<bool> (m+10));
    for (auto in:query){
        int ans = 0;
        int x,y; tie(x,y) = in;
        banned[x][y] = true;
        if (x == 1){
            for (int j=y; j<=m; j++){
                banned[x][j] = true;
            }
        }
        if (x == n){
            for (int j=y; j>0; j--){
                banned[x][j] = true;
            }
        }
        if (y == 1){
            for (int i=x; i<=n; i++){
                banned[i][y] = true;
            }
        }
        if (y == m){
            for (int i=x; i>0; i--){
                banned[i][y] = true;
            }
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (banned[i][j]) continue;
                int val = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = val+a[i][j];
                ans = max(ans,dp[i][j]);
            }
        }
        cout << ans << endl;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
//                cout << dp[i][j] << " ";
                dp[i][j] = 0;
                banned[i][j] = 0;
            }
//            cout << endl;
        }
    }
}

/*Subtask2*/
bool CheckSub2(){
    return false;
}

void SolveSub2(){

}

/*Subtask3*/
bool CheckSub3(){
    return false;
}

void SolveSub3(){

}

/*Subtask4*/
bool CheckSub4(){
    return false;
}

void SolveSub4(){

}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;

    return 0;
}
