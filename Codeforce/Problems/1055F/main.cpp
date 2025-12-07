/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e6+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;
const int LG = 62;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,k,ans=0;
vector<pii> adj[N];
vector<int> v;

//struct TRIE{
//    struct NODE{
//        NODE* child[2];
//        signed cnt[2];
//
//        NODE(){
//            child[0] = child[1] = NULL;
//            cnt[0] = cnt[1] = 0;
//        }
//    };
//
//    NODE* Root;
//
//    TRIE(){
//        Root = new NODE();
//    }
//
//    void AddString(int x){
//        NODE* cur = Root;
//        for (int lg = LG-1; lg>=0; lg--){
//            int idx = ((x>>lg)&1LL);
//            ++cur->cnt[idx];
//            if (cur->child[idx] == NULL) cur->child[idx] = new NODE();
//            cur = cur->child[idx];
//        }
//    }
//
//    void Magic(){
//        NODE* cur;
//        int idx,l,r,mid,i,lg;
//        int gcnt = 0,gidx;
//        int tmpcnt = 0;
//        queue<pair<int,pair<pair<NODE*,int>,pii>>> q;
//        mid = 0;
//        for (i=1; i<=n; i++){
//            if (((v[i]>>(LG-1))&1LL)) break;
//            mid = i;
//        }
//        if (mid>=1){
//            tmpcnt+=(mid-1+1)*(Root->cnt[0]);
//            q.push({LG-1,{{Root,0},{1,mid}}});
//        }
//        if (mid+1<=n){
//            tmpcnt+=(n-(mid+1)+1)*(Root->cnt[1]);
//            q.push({LG-1,{{Root,1},{mid+1,n}}});
//        }
//        for (lg=LG-1; lg>=0; lg--){
//            if (gcnt+tmpcnt<k){
//                gcnt+=tmpcnt;
//                gidx = 1;
//            }
//            else gidx = 0;
//            tmpcnt = 0;
//
//            ans = ans^(gidx<<lg);
//            if (lg == 0) break;
//
//            while (!q.empty() && q.front().fi==lg){
//                cur = q.front().se.fi.fi;
//                idx = q.front().se.fi.se;
//                l = q.front().se.se.fi;
//                r = q.front().se.se.se;
//                q.pop();
//
//                cur = cur->child[idx^gidx];
//
//                if (cur == NULL) continue;
//
//                mid = l-1;
//                for (i=l; i<=r; i++){
//                    if (((v[i]>>(lg-1))&1LL)) break;
//                    mid = i;
//                }
//                if (mid>=l){
//                    tmpcnt+=(mid-l+1)*(cur->cnt[0]);
//                    q.push({lg-1,{{cur,0},{l,mid}}});
//                }
//                if (mid+1<=r){
//                    tmpcnt+=(r-(mid+1)+1)*(cur->cnt[1]);
//                    q.push({lg-1,{{cur,1},{mid+1,r}}});
//                }
//            }
//        }
//    }
//};
//
//TRIE trie;

void Magic(){
    int idx,l1,r1,l2,r2,mid1,mid2,i,lg;
    int gcnt = 0,gidx;
    int tmpcnt = 0;
    queue<pair<pii,pair<pii,piii>>> q;
    mid1 = 0;
    for (i=1; i<=n; i++){
        if (((v[i]>>(LG-1))&1LL)) break;
        mid1 = i;
    }
    if (mid1>=1){
        tmpcnt+=(mid1-1+1)*(mid1-1+1);
        q.push({{LG-1,0},{{1,mid1},{{1,n},mid1}}});
    }
    if (mid1+1<=n){
        tmpcnt+=(n-(mid1+1)+1)*(n-(mid1+1)+1);
        q.push({{LG-1,1},{{mid1+1,n},{{1,n},mid1}}});
    }
    for (lg=LG-1; lg>=0; lg--){
        if (gcnt+tmpcnt<k){
            gcnt+=tmpcnt;
            gidx = 1;
        }
        else gidx = 0;
        tmpcnt = 0;

        ans = ans^(gidx<<lg);
        if (lg == 0) break;

        while (!q.empty() && q.front().fi.fi==lg){
            idx = q.front().fi.se;
            l1 = q.front().se.fi.fi;
            r1 = q.front().se.fi.se;
            l2 = q.front().se.se.fi.fi;
            r2 = q.front().se.se.fi.se;
            mid2 = q.front().se.se.se;
            q.pop();

            idx = idx^gidx;

            if (!idx){
                r2 = mid2;
            }
            else{
                l2 = mid2+1;
            }

            if (l2>r2) continue;

            mid2 = l2-1;
            for (i=l2; i<=r2; i++){
                if (((v[i]>>(lg-1))&1LL)) break;
                mid2 = i;
            }

            mid1 = l1-1;
            for (i=l1; i<=r1; i++){
                if (((v[i]>>(lg-1))&1LL)) break;
                mid1 = i;
            }
            if (mid1>=l1){
                tmpcnt+=(mid1-l1+1)*(mid2-l2+1);
                q.push({{lg-1,0},{{l1,mid1},{{l2,r2},mid2}}});
            }
            if (mid1+1<=r1){
                tmpcnt+=(r1-(mid1+1)+1)*(r2-(mid2+1)+1);
                q.push({{lg-1,1},{{mid1+1,r1},{{l2,r2},mid2}}});
            }
        }
    }
}

void DFS(int u, int p, int totalw, vector<int>& vec){
    vec.push_back(totalw);
//    trie.AddString(totalw);
    for (auto in:adj[u]){
        int v = in.fi;
        int w = in.se;
        if (v==p) continue;
        DFS(v,u,totalw^w,vec);
    }
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=2; i<=n; i++){
        int u,w;
        cin >> u >> w;
        adj[u].push_back({i,w});
        adj[i].push_back({u,w});
    }
    v.push_back(-1);
    DFS(1,0,0,v);
    sort(v.begin(),v.end());
//    for (auto x:v) cout << x << " ";
//    cout << endl;
    Magic();
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
