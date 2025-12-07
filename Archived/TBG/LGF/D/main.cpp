/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1010;
const int LG = 31;
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
int n,m,L,R;
int a[N][N];
int cnt[N][N];
bool reachable[N][N];
stack<pair<int,int>> s;

bool check(int val){
    bool res = 0;
    for (int i=1; i<=n; i++){
        while (!s.empty()) s.pop();
        s.push({0,0});
        for (int j=1; j<=m; j++){
            cnt[i][j] = cnt[i-1][j]+1;
            if ((val&a[i][j])!=val) cnt[i][j] = 0;
            int pos = j;
            while (!s.empty() && s.top().se>=cnt[i][j]){
//                cout << i << " " << j << " " << s.top().fi << " " << s.top().se << " " << j-s.top().fi << endl;
                if (reachable[s.top().se][j-s.top().fi]) res = true;
                pos = s.top().fi;
                s.pop();
            }
            s.push({pos,cnt[i][j]});
        }
        while (!s.empty()){
            if (reachable[s.top().se][m+1-s.top().fi]) res = true;
            s.pop();
        }
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> m >> L >> R;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            reachable[i][j] = (reachable[i-1][j]||reachable[i][j-1]);
            if (i*j>=L && i*j<=R) reachable[i][j] = true;
//            cout << reachable[i][j] << " ";
        }
//        cout << endl;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int lg=LG; lg>=0; lg--){
//        cout << lg << endl;
        int tmp = (ans^(1<<lg));
        if (check(tmp)) ans = (ans^(1<<lg));
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=m; j++){
//                cout << cnt[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
