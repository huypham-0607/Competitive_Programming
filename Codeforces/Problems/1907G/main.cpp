#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,test, timedfs,s,e,saves,savee,bridge;
vector<pii> a[maxn];
int parent[maxn];
int t[maxn];
int active[maxn];
int pre[maxn];
int cnt[maxn];
bool vis[maxn];
bool cyc[maxn];
bool on[maxn];
int swit[maxn];

int dfs(int u, int p){
    t[u] = ++timedfs;
//    cout << u << " " << t[u] << " " << p << endl;
    pre[u] = active[u];
    int c=active[u];
    parent[u] = p;
    for (auto in:a[u]){
        int v = in.fi;
        if (v==p) continue;
        else if (t[v] && t[v] < t[u]){
            s = v;
            e = u;
            saves = v;
            savee = u;
            cyc[in.se] = true;
            bridge = in.se;
//            cout << s << " " << e << endl;
        }
        else if (t[v]) continue;
        else{
            swit[v] = in.se;
            c+=dfs(v,u);
        }
    }
    pre[u] -= c/2*2;
    return c%2;
}

piii calc(int u, int p, int num){
    vis[u] = true;
    piii res = {0,{0,0}};
    cnt[u] = pre[u];
//    cout << u << " " << p << endl;
    for (auto in:a[u]){
        int v = in.fi;
        int pos = in.se;
        if (v == p) continue;
        else if (t[v] < t[u] || vis[v]) continue;
        else{
            piii in = calc(v,u,pos);
            res.fi += in.fi;
            res.se.fi += in.se.fi;
            res.se.se+= in.se.se;
            cnt[u]+=cnt[v];
        }
    }
    res.fi+=cnt[u];
    if (cnt[u]){
        on[num] = true;
    }
    if (u == e && u!=s){
        cyc[num] = true;
        res.se.fi += cnt[u];
        res.se.se++;
        e = parent[e];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=1; i<=n; i++){
            vis[i] = 0;
            pre[i] = 0;
            cnt[i] = 0;
            t[i] = 0;
            cyc[i] = false;
            on[i] = false;
            swit[i] = 0;
            a[i].clear();
        }
        for (int i=1; i<=n; i++){
            char c;
            cin >> c;
            if (c == '1') active[i] = 1;
            else active[i] = 0;
        }
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            a[i].push_back({x,i});
            a[x].push_back({i,i});
        }
        int ans = 0;
        timedfs = 0;
        int v = true;
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                dfs(i,0);
                piii res = calc(i,0,0);
//                cout << res.fi << " " << res.se.fi << " " << res.se.se << endl;
                if (cnt[i] == 1) v = false;
                if (res.fi > res.fi-res.se.fi+(res.se.se-res.se.fi)+1){
                    int u = savee;
                    while (u!=saves){
//                        cout << u << " " << on[swit[u]] << endl;
                        on[swit[u]] = !(on[swit[u]]);
                        u = parent[u];
                    }
                    on[bridge] = !on[bridge];
                    ans+=res.fi-res.se.fi+(res.se.se-res.se.fi)+1;
                }
                else ans+=res.fi;
            }
        }
//        for (int i=1; i<=n; i++){
//            cout << pre[i] << " ";
//        }
//        cout << endl;
//        for (int i=1; i<=n; i++){
//            cout << cnt[i] << " ";
//        }
//        cout << endl;
//        cout << s << " " << e << endl;
//        for (int i=1; i<=n; i++){
//            for(auto u:a[i]){
//                cout << u.fi << " ";
//            }
//            cout << endl;
//        }
        if (v){
            cout << ans << endl;
            for (int i=1; i<=n; i++){
                if (on[i]) cout << i << " ";
            }
            cout << endl;
        }
        else cout << -1 << endl;
//        for (int i=1; i<=n; i++){
//            cout << on[i] << " ";
//        }
//        cout << endl;
    }
    return 0;
}
