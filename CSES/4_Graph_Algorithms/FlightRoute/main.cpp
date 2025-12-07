#include <bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second

typedef long long ll;

using namespace std;

const int N = 2e5 + 5;
const ll inf = 1e16;

int n,m,k;
vector<pii> a[N];
ll d[N][11];

struct Node{
    int u;
    ll dis;
    bool operator > (const Node& a) const{
        return dis > a.dis;
    }
    Node(){}
    Node(int v,ll k){
        u = v;
        dis = k;
    }
};

void Update(int u, ll dist){
    int idx = k;
    while (idx>1 && d[u][idx-1] > dist){
        swap(d[u][idx],d[u][idx-1]);
        --idx;
    }
    d[u][idx] = dist;
}

void dijkstra(){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++) d[i][j] = inf;
    }
    d[1][1] = 0;
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push(Node(1,0));
    while(!pq.empty()){
        int u = pq.top().u;
        ll dis = pq.top().dis;
        pq.pop();
        if (dis > d[u][k]) continue;
        for (int i = 0; i < a[u].size(); i++){
            int v = a[u][i].fi;
            ll w = a[u][i].se;
            for (int j = 1; j <= k; j++){
                if (d[v][k] <= dis + w) continue;
                Update(v,dis+w);
                pq.push(Node(v,dis+w));
                break;
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(pii(v,w));
        //a[v].push_back(pii(u,w));
    }
    dijkstra();
    for (int i = 1; i <= k; i++) cout << d[n][i] << " ";
    return 0;
}
