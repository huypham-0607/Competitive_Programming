/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
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
int n,p,ans;
int a[N];
vector<pii> vertex;
bool vis[N];

//DSU
int parent[N];

int Find(int u){
    return (u==parent[u])? u : parent[u] = Find(parent[u]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        parent[y] = x;
    }
}

/*Solution*/
void solve(){
    vertex.clear();
    cin >> n >> p;
    ans = 0;
    for (int i=1; i<=n; i++){
        parent[i] = i;
        cin >> a[i];
        vertex.push_back({a[i],i});
    }
    sort(vertex.begin(),vertex.end());
    for (auto in:vertex){
        int val = in.fi;
        int idx = in.se;

        if (val>=p) break;

        int tmp = idx;
        while (tmp>1 && Find(tmp-1)!=Find(tmp) && a[tmp-1]%val == 0){
            Union(tmp,tmp-1);
            ans+=val;
            --tmp;
        }
        tmp = idx;
        while (tmp<n && Find(tmp+1)!=Find(tmp) && a[tmp+1]%val == 0){
            Union(tmp,tmp+1);
            ans+=val;
            ++tmp;
        }
    }
//    for (int i=1; i<=n; i++){
//        cout << parent[i] << " ";
//    }
//    cout << endl;
    for (int i=1; i<n; i++){
        if (Find(i)!=Find(i+1)){
            Union(i,i+1);
            ans+=p;
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
