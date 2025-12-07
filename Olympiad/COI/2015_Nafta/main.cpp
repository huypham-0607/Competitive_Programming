/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2000;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/

//Fenwick
struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        BIT.resize(n+10);
    }

    void Init(int _n, int val=0){
        n = _n;

        BIT.resize(n+10,0);
        for (int i=1; i<=n; i++){
            BIT[i] = 0;
//            cout << BIT[i] << " ";
        }
//        cout << endl;
    }

    void updatePoint(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    void updateRange(int l, int r, int val){
        updatePoint(l,val);
        updatePoint(r+1,-val);
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }
} BIT;



int n,m;
int val[N+1][N+1];
int precalc[N+1][N+1];
vector<pair<pii,pii>> v;
int dp[N+1], dpPrev[N+1];

void DnC (int k){
    deque<pair<int,pair<pii,pii>>> dq;
    int lvl = 0;
    dq.push_back({1,{{k,m},{k,m}}});
//    int idx = 0;
    while (!dq.empty()){
        auto in = dq.front();
        int curlvl = in.fi;
        int l = in.se.fi.fi;
        int r = in.se.fi.se;
        int optl = in.se.se.fi;
        int optr = in.se.se.se;
        dq.pop_front();

        if (curlvl!=lvl){
            lvl = curlvl;
            BIT.Init(m);
//            idx = 0;
        }

        int mid = (l+r)/2;

//        cout << "mid " << mid << endl;

        pii best = {0,-INF};

        for (int i = optl; i<=min(mid,optr); i++){
            int sum = dpPrev[i-1] - precalc[mid][i-1] + precalc[mid][mid];
//            cout << i << " " << sum << " " << BIT.getPoint(i-1) << " " << BIT.getPoint(mid) << endl;

            if (sum > best.se){
                best.fi = i;
                best.se = sum;
            }
        }
        dp[mid] = best.second;
        int opt = best.first;

        if (l<=mid-1) dq.push_back({lvl+1,{{l,mid-1},{optl,opt}}});
        if (mid+1<=r) dq.push_back({lvl+1,{{mid+1,r},{opt,optr}}});
    }
}

int vis[N+1][N+1];
int di[4] = {0,1,0,-1},
    dj[4] = {1,0,-1,0};

pair<int,pii> BFS(int si, int sj){
    int t = 0, l = INF, r = -INF;
    queue<pii> q;
    q.push({si,sj});
    vis[si][sj] = true;
    while (!q.empty()){
        auto [i,j] = q.front();
//        cout << i << " " << j << endl;
        q.pop();
        vis[i][j] = true;
        t+=val[i][j];
        l = min(l,j);
        r = max(r,j);
        for (int idx=0; idx<4; idx++){
            int x = i+di[idx];
            int y = j+dj[idx];
            if (x<=0 || x>n || y<=0 || y>m) continue;
            if (!vis[x][y] && val[x][y] != -1){
                vis[x][y] = true;
                q.push({x,y});
            }
        }
    }

    return make_pair(r,make_pair(t,l));
}

/*Solution*/
void solve(){

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c; cin >> c;
            if (c == '.') val[i][j] = -1;
            else val[i][j] = c-'0';
//            cout << val[i][j] << " ";
        }
//        cout << endl;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (!vis[i][j] && val[i][j]!=-1){
//                cout << "{" << i << "," << j << "}" << endl;
                auto in = BFS(i,j);
                int r = in.fi;
                int t = in.se.fi;
                int l = in.se.se;
                v.push_back({{l,t},{l,r}});
                v.push_back({{r+1,-t},{l,r}});
            }
        }
    }

    sort(all(v));

    BIT.Init(m);

    int idx = 0;
    for (int i=1; i<=n; i++){
        while (idx!=(int)v.size() && v[idx].fi.fi <= i){
            auto in = v[idx];
//            int pos = in.fi.fi;
            int t = in.fi.se;
            int l = in.se.fi;
            int r = in.se.se;
            BIT.updateRange(l,r,t);
            ++idx;
        }
        for (int j=0; j<=i; j++){
            precalc[i][j] = BIT.getPoint(j);
        }
    }

//    for (int i=0; i<v.size(); i++){
//        cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se.fi << " " << v[i].se.se << endl;
//    }

    dp[0] = 0;
    for (int i=1; i<=m; i++){
        dp[i] = -INF;
    }

    for (int idx=1; idx<=m; idx++){
        swap(dp,dpPrev);
        for (int i=0; i<=m; i++){
            dp[i] = -INF;
        }
        DnC(idx);
        int ans = -INF;
        for (int i=idx; i<=m; i++){
            ans = max(ans,dp[i]);
        }
//        for (int i=0; i<=m; i++){
//            cout << dp[i] << " ";
//        }
//        cout << endl;
        cout << ans << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
