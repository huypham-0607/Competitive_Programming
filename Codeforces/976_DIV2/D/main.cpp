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
int n,q,cnt;
int parent[N];
int pre[N];
vector<pii> v[11][11];

void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
    cnt = n;
}

int Find(int x){
    return (x==parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        parent[y] = x;
        --cnt;
    }
}

/*Solution*/
void solve(){
    cin >> n >> q;
    Init();
    for (int i=1; i<=10; i++){
        for (int j=1; j<=i; j++){
            v[i][j].clear();
        }
    }
    for (int i=1; i<=q; i++){
        int a,d,k;
        cin >> a >> d >> k;
        int l = a, r = a+d*(k), md = (a-1)%d+1;
        if (l>r) continue;
        v[d][md].push_back({l,r});
    }
    for (int i=1; i<=10; i++){
        for (int j=1; j<=i; j++){
            for (int idx=1; idx<=n; idx++){
                pre[idx] = 0;
            }
            for (auto in:v[i][j]){
                if (in.fi>0 && in.fi<=n) pre[in.fi]++;
                if (in.se>0 && in.se<=n) pre[in.se]--;
            }
            int cur = 0;
            for (int idx=j; idx<=n; idx+=i){
                cur+=pre[idx];
                if (cur && (idx+i<=n)) Union(idx,idx+i);
            }
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << Find(i) << " ";
//    }
//    cout << endl;
    cout << cnt << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
