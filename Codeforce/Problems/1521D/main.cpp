#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,start;
vector<int> a[maxn];
vector<piiii> ans;

int kamisatoayaka(){
    queue<pii> q;
    int meow;
    q.push({1,0});
    while (!q.empty()){
        int u = q.front().fi;
        int p = q.front().se;
        q.pop();
        meow = u;
//        cout << u << endl;
        for (auto v:a[u]){
            if (v == p) continue;
            q.push({v,u});
        }
    }
    return meow;
}

pii dfs(int u, int p){
    int bot = u;
    int cnt = 0;
    int res = 0;
    for (auto v:a[u]){
        if (v==p) continue;
        auto in = dfs(v,u);
        if (in.se == 0) continue;
        ++cnt;
        if (cnt == 1){
            res = in.fi;
            bot = in.se;
        }
        if (cnt == 2){
            ans.push_back({{u,p},{start,bot}});
            start = in.se;
            bot = 0;
        }
        if (cnt > 2){
            ans.push_back({{v,u},{start,v}});
            start = in.se;
        }
    }
//    cout << u << " " << cnt << " " << res << " " << bot << endl;
    return make_pair(res+1,bot);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        ans.clear();
        for (int i=1; i<=n; i++){
            a[i].clear();
        }
        for (int i=1; i<n; i++){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        start = kamisatoayaka();
        dfs(start,0);
        cout << ans.size() << endl;
        for (auto in:ans){
            cout << in.fi.fi << " " << in.fi.se << " " << in.se.fi << " " << in.se.se << endl;
        }
    }

    return 0;
}
