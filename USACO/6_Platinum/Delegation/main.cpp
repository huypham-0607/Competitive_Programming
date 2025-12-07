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
const int N = 1e5+10;
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
vector<int> a[N];

pair<int,bool> DFS(int u, int p, int k){
    multiset<int> ms;
    vector<int> cres;

    int mx = 0;
    int bigcnt = 0;
    int totalcnt = 0;

    for (auto v:a[u]){
        if (v==p) continue;
        auto tmp = DFS(v,u,k);

        ++totalcnt;
//        cout << tmp.fi << " " << tmp.se << endl;
        if (!tmp.se) return tmp;

        if (tmp.fi<k){
            cres.push_back(tmp.fi);
            ms.insert(tmp.fi);
        }
        else{
            mx = max(mx,tmp.fi);
            ++bigcnt;
        }
    }

    if (u==1 && totalcnt%2==1){
        cres.push_back(0);
        ms.insert(0);
    }
    else if (u!=1 && totalcnt%2==0){
        cres.push_back(0);
        ms.insert(0);
    }

    int cnt=0, cur=0;
    sort(cres.begin(),cres.end());
    for (auto oof:cres){
        auto itorg = ms.find(oof);
        if (itorg==ms.end()) continue;
        ms.erase(itorg);

        auto it = ms.lower_bound(k-oof);
        if (it!=ms.end()){
            ms.erase(it);
        }
        else if (bigcnt){
            --bigcnt;
        }
        else{
            ++cnt;
            cur=oof;
        }
    }

//    cout << k << " " << u << " " << bigcnt << " " << mx << " " << cnt << " " << cur << endl;
    if (u==1){
        if (cnt==0) return make_pair(0,true);
        else return make_pair(0,false);
    }
    else{
        if (bigcnt) return make_pair(mx+1,true);
        else if (cnt<=1) return make_pair(cur+1,true);
        else return make_pair(0,false);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    m = n-1;
    for (int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans = 1;
    int l=1, r=m;
    while (l<=r){
        int mid = (l+r)/2;
        pair<int,bool> tmp = DFS(1,0,mid);
//        if (tmp.se && (tmp.fi>=mid || tmp.fi==1)){
        if (tmp.se){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
//        cout << endl;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
