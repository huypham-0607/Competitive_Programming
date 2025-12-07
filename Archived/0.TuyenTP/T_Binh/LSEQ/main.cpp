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
const int N = 2e6+10;
const int INF = 1e9+7;
const int pivot = 1e6;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,tmp;
int pre[N];

////DSU
//int parent[N];
//int sz[N];
//
//int Find(int x){
//    return (x==parent[x])? x : parent[x] = Find(parent[x]);
//}
//
//void Union(int x, int y){
//    if (x>y) swap(x,y);
//    int u = Find(x);
//    int v = Find(y);
//    if (u!=v){
//        sz[u]+=sz[v];
//        parent[v] = u;
//    }
//}

//bool check(int x){
//    int t = 0;
//    for (int i=1; i<=1000000; i++){
//        t+=pre[i];
//        if (i-x>0) t-=pre[i-x];
//        if (i>=x && t<=tmp) return true;
//    }
//    return false;
//}

/*Solution*/
void solve(){
    cin >> n;
    tmp = 0;
    for (int i=0; i<=2000000; i++){
        pre[i] = 1;
    }
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        x+=pivot;
        if (x==pivot) ++tmp;
        else{
            pre[x] = 0;
        }
    }
//    for (int i=1; i<=1000000; i++){
//        pre[i] += pre[i-1]
//    }
    int ans = 0;
    int l = 0;
    int t = 0;
    for (int r=0; r<=2000000; r++){
        t+=pre[r];
        while (t>tmp){
            t-=pre[l];
            ++l;
        }
        ans = max(ans,r-l+1);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("LSEQ.inp","r",stdin);
    freopen("LSEQ.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
