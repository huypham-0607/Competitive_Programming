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
const int N = 1e5;
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
int n;
int state[N*2+10];
int cnt[N+10][2];
int nxt[N*2+10];
int vis[N*2+10];
int a[N];

int Get(int s){
    int x = s;
    int d = 0;
    vector<int> res;
    res.resize(2);
    int cnt = 1;
    do{
        vis[x] = true;
        if (x>N) vis[x-N] = true;
        else vis[x+N] = true;
        int y = nxt[x];
        if (state[y] != 0){
            if (y>N) y = y-N;
            else y = y+N;
        }
        ++d;
        if (state[y]!=1){
            ++cnt;
            res[cnt%2]+=d;
            d = 0;
        }
        x = y;
    } while (!vis[x] && state[x]);
    vis[x] = true;
    return min(res[0],res[1]);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        ++cnt[a[i]][0];
        if (cnt[a[i]][0] == 2) a[i] = a[i]+N;
    }
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        ++cnt[x][1];
        if (cnt[x][0] + cnt[x][1] == 2) x+=N;
        nxt[x] = a[i];
        nxt[a[i]] = x;
    }
    for (int i=1; i<=N; i++){
        if (cnt[i][0] + cnt[i][1] == 2){
            if (cnt[i][0] == 2 || cnt[i][1] == 2){
                state[i] = 2;
                state[i+N] = 2;
            }
            else{
                state[i] = 1;
                state[i+N] = 1;
            }
        }
    }
    int ans = 0;
//    for (int i=1; i<=9; i++){
//        cout << cnt[i][0] << " " << cnt[i][1] << " " << nxt[i] << " " << nxt[i+N] << " " << state[i] << " " << state[i+N] << endl;
//    }
    for (int i=1; i<=N; i++){
        if (!vis[i] && !state[i] && nxt[i]) ans+=Get(i);
    }
    for (int i=1; i<=N*2; i++){
        if (!vis[i] && state[i] == 2) ans+=Get(i);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("SWAP.inp","r",stdin);
    freopen("SWAP.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
