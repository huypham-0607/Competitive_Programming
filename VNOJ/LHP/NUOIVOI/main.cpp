/*Author: KawakiMeido*/
/*AHAHAHAHAHAH OAUAWAUAWHUAWH PERSISTENT SEGGGGGGGGGGGGGGGGS(MENT TREE) NHU CCCCCCCCCCCC*/
/*TREE ALGORITHM SUPREMACY AWHEFUIAWHFUIAWHFIAWHFUIAWH*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e3+10;
const int N2 = 1e5+10;
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
int n,m,q;
vector<int> adj[N2];
int flip[N];
int a[N][N];
int sum[N];
int total = 0;
int type[N2];
pii dt[N2];
int ans[N2];

/*DFS*/

void DFS(int u){
    int i,j;
    int active = false;
    if (type[u] == 1){
        i=dt[u].fi;
        j=dt[u].se;
        if ((a[i][j]+flip[i])%2==0){
            a[i][j] = (a[i][j]+1)%2;
            sum[i]+=1;
            total+=1;
            active = true;
        }
    }
    if (type[u] == 2){
        i=dt[u].fi;
        j=dt[u].se;
        if ((a[i][j]+flip[i])%2==1){
            a[i][j] = (a[i][j]+1)%2;
            sum[i]-=1;
            total-=1;
            active = true;
        }
    }
    if (type[u] == 3){
        i=dt[u].fi;
        flip[i] = (flip[i]+1)%2;
        total+=m-2*sum[i];
        sum[i] = m-sum[i];
        active = true;
    }
    ans[u] = total;
//    cout << "{" << u << "}" << endl;
    for (auto v:adj[u]){
//        cout << "{" << v << "}" << endl;
        DFS(v);
    }
    if (active){
        if (type[u] == 1){
            a[i][j] = (a[i][j]+1)%2;
            sum[i]-=1;
            total-=1;
        }
        if (type[u] == 2){
            a[i][j] = (a[i][j]+1)%2;
            sum[i]+=1;
            total+=1;
        }
        if (type[u] == 3){
            flip[i] = (flip[i]+1)%2;
            total+=m-2*sum[i];
            sum[i] = m-sum[i];
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    dt[0] = {0,0};
    type[0] = 4;
    for (int ver=1; ver<=q; ver++){
        char c;
        cin >> c;
        if (c == '+') type[ver] = 1;
        if (c == '-') type[ver] = 2;
        if (c == '~') type[ver] = 3;
        if (c == '<') type[ver] = 4;
        if (type[ver] == 1){
            int i,j;
            cin >> i >> j;
//            cout << i << " " << j << endl;
            adj[ver-1].push_back(ver);
            dt[ver] = {i,j};
        }
        if (type[ver] == 2){
            int i,j;
            cin >> i >> j;
//            cout << i << " " << j << endl;
            adj[ver-1].push_back(ver);
            dt[ver] = {i,j};
        }
        if (type[ver] == 3){
            int i;
            cin >> i;
//            cout << i << " " << 0 << endl;
            adj[ver-1].push_back(ver);
            dt[ver] = {i,0};
        }
        if (type[ver] == 4){
            int k;
            cin >> k;
//            cout << k << " meow" << endl;
            adj[k].push_back(ver);
            dt[ver] = {0,0};
        }
    }
    DFS(0);
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
