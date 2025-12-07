#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 265;
const int INF = 2e9;

int n;
pair<ll,ll> cord[maxn];
vector<int> parent,a[maxn*2];
int cap[maxn*2][maxn*2];

int NewFlow(){
    parent.assign(maxn*2,-1);
    parent[0] = -2;
    queue<ii> q;
    q.push({0,INF});
    while (!q.empty()){
        int u = q.front().fi;
        int flow = q.front().se;
        q.pop();

        for (auto v:a[u]){
            if (parent[v]==-1 && cap[u][v]){
                int newflow = min(flow,cap[u][v]);
                parent[v] = u;
                if (v == n*2+1) return newflow;
                q.push({v,newflow});
            }
        }
    }
    return 0;
}

int Solve(){
    int res = 0;
    int newflow;
    while ((newflow = NewFlow())){
        //cout << res << " meow " << "\n";
        res+=newflow;
        int u = n*2+1;
        while (u!=0){
            int v = parent[u];
            cap[v][u]-=newflow;
            cap[u][v]+=newflow;
            u = v;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l,r;
    cin >> l >> r >> n;
    for (int i=1; i<=n; i++){
        a[i].push_back(n+i);
        a[n+i].push_back(i);
        cap[i][n+i] = 1;
        int x,y;
        cin >> x >> y;
        cord[i] = {x,y};
        if (y<=100){
            a[0].push_back(i);
            a[i].push_back(0);
            cap[0][i] = 1;
        }
        if (y>=r-100){
            a[n+i].push_back(n*2+1);
            a[n*2+1].push_back(n+i);
            cap[n+i][n*2+1] = 1;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            ll x = cord[i].fi - cord[j].fi;
            x*=x;
            ll y = cord[i].se - cord[j].se;
            y*=y;
            if ((x+y) <= 40000){
                a[n+i].push_back(j);
                a[j].push_back(n+i);
                cap[n+i][j] = 1;
                a[n+j].push_back(i);
                a[i].push_back(n+j);
                cap[n+j][i] = 1;
            }
        }
    }
    cout << Solve();
//    cout << "\n";
//    for (int i=0; i<=n*2+1; i++){
//        cout << i << ": ";
//        for (auto j:a[i]){
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    return 0;
}
