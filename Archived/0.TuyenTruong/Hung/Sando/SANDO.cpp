#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SANDO"

using namespace std;

const int N = 1010;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,q;
int pre[N][N];
int ans[N][N];
int a[N][N];
vector<pii> lvlpos[N];
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

//DSU
pii parent[N][N];
set<int> qr[N][N];
int res[300030];

void Init(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            parent[i][j] = {i,j};
        }
    }
}

pii Find(pii x){
    return (x==parent[x.fi][x.se])? x : parent[x.fi][x.se] = Find(parent[x.fi][x.se]);
}

void Union(pii u, pii v, int val){
    pii x = Find(u);
    pii y = Find(v);
    if (qr[x.fi][x.se].size()<qr[y.fi][y.se].size()) swap(x,y);
    if (x!=y){
        for (auto vl:qr[y.fi][y.se]){
            if (qr[x.fi][x.se].count(vl)){
                res[vl] = max(res[vl],val);
            }
            qr[x.fi][x.se].insert(vl);
        }
        qr[y.fi][y.se].clear();
        parent[y.fi][y.se] = x;
    }
}

bool check(pii x){
    int i = x.fi;
    int j = x.se;
    return (i>0 && i<=n && j>0 && j<=n);
}

void UnionMat(pii u){
    for (int idx=0; idx<4; idx++){
        pii v = {u.fi+di[idx],u.se+dj[idx]};
        if (check(v) && ans[v.fi][v.se] == ans[u.fi][u.se]){
            Union(u,v,ans[u.fi][u.se]);
        }
    }
}

void Solve(){
    cin >> n;
    Init();
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c;
            cin >> c;
            if (c=='#'){
                a[i][j] = 0;
                pre[i][j] = 0;
            }
            else{
                a[i][j] = 1;
                pre[i][j] = 1;
            }
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        qr[x1][y1].insert(i);
        qr[x2][y2].insert(i);
    }

    vector<int> st;
    vector<int> idx;
    int cur, nxt;
    for (int i=1; i<=n; i++){
        st.clear();
        st.push_back(0);
        idx.clear();
        idx.push_back(0);
        cur = 0;
        for (int j=1; j<=n; j++){
//            cout << i << " " << j << endl;
            if (!a[i][j]) pre[i][j] = 0;
            else pre[i][j]+=pre[i-1][j];

            int sz = (pre[i][j]+1)/2;
//            cout << sz;
            int luu = j;
            while (st.back()>sz){
                st.pop_back();
                luu = idx.back();
                idx.pop_back();
            }
            if (st.back()!=sz){
                st.push_back(sz);
                idx.push_back(luu);
            }

            cur = min(cur,st.back());
            int pos = upper_bound(idx.begin(),idx.end(),j-cur*2)-idx.begin();
//            cout << cur << " " << pos << " " << st[pos] << endl;
//            for (auto x:st){
//                cout << x << " ";
//            }
//            cout << endl;
//            for (auto x:idx){
//                cout << x << " ";
//            }
//            cout << endl << endl;
            if (pos>0 && st[pos-1]>=cur+1) ++cur;
            int delta = max(0,cur-1);
            ans[i-delta][j-delta] = cur;
            if (cur!=0) lvlpos[cur].push_back({i-delta,j-delta});
//            if (cur!=0) UnionMat(make_pair(i-delta,j-delta));
        }
//        cout << endl;
    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << ans[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << pre[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    for (int lvl=n; lvl>1; lvl--){
        for (auto in:lvlpos[lvl]){
            ans[in.fi][in.se] = lvl-1;
            pii in2 = make_pair(in.fi+1,in.se+1);
            if (check(in2)){
                ans[in2.fi][in2.se] = lvl-1;
            }
        }
        for (auto in:lvlpos[lvl-1]){
            UnionMat(in);
//            pii in2 = make_pair(in.fi+1,in.se+1);
        }
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=n; j++){
//                cout << ans[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }
    for (int i=1; i<=q; i++){
        if (res[i] == 0) cout << 0 << endl;
        else cout << (res[i]-1)*2+1 << endl;
    }
}

signed main(){
//    freopen(NAME".inp","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Solve();

    return 0;
}
