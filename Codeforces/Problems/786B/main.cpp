#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int N = 1e5+10;
const int INF = 1e17;

int test;
int n,q,s;

bool edgevis[N];
vector<int> IT[4*N];
int dist[4*N];
int dist2[4*N];
bool vis[4*N];
pii path[N];
int weight[N];
vector<int> edgelist;

void Add(int idx, int l, int r, int x, int y, int val){
    if (r < x || l > y) return;
    if (x <= l && r <= y){
        IT[idx].push_back(val);
        return;
    }
    int mid = (l+r)/2;
    Add(idx*2,l,mid,x,y,val);
    Add(idx*2+1,mid+1,r,x,y,val);
}

bool IsVis(int idx, int l, int r, int x, int y){
    if (r < x || l > y) return true;
    if (x <= l && r <= y){
        return (vis[idx]);
    }
    int mid = (l+r)/2;
    return (IsVis(idx*2,l,mid,x,y) && IsVis(idx*2+1,mid+1,r,x,y));
}

void GetEdge(int idx, int l, int r, int x, int y){
    if (r < x || l > y) return;
    if (vis[idx]) return;
    for (auto in:IT[idx]){
        edgelist.push_back(in);
    }
//    cout << idx << " " << l << " " << r << " " << vis[idx] << endl;
//    for (auto in:edgelist){
//        cout << in << " ";
//    }
//    cout << endl;
    IT[idx].clear();
    if (x <= l && r<=y) vis[idx] = true;
    if (l != r){
        int mid = (l+r)/2;
        GetEdge(idx*2,l,mid,x,y);
        GetEdge(idx*2+1,mid+1,r,x,y);
    }
}

void build(int idx, int l, int r){
    for (int i=1; i<=n*4; i++){
        dist[i] = INF;
    }
}

int MaxQuery(int idx, int l, int r, int x, int y){
    if (r < x || l > y) return 0;
    if (x <= l && r <= y){
        return dist[idx];
    }
    int mid = (l+r)/2;
    return max(MaxQuery(idx*2,l,mid,x,y),MaxQuery(idx*2+1,mid+1,r,x,y));
}

int MinQuery(int idx, int l, int r, int x, int y){
    if (r < x || l > y) return INF;
    if (x <= l && r <= y){
        return dist[idx];
    }
    int mid = (l+r)/2;
    int res = dist[idx];
    return min({res,MinQuery(idx*2,l,mid,x,y),MinQuery(idx*2+1,mid+1,r,x,y)});
}

void update(int idx, int l, int r, int x, int y, int val){
    if (r < x || l > y) return;
//    if (val == 0) cout << idx << " " << l << " " << r << endl;
    if (x <= l && r <= y){
        dist[idx] = min(dist[idx],val);
//        cout << idx << " " << l << " " << r << " " << val << endl;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,x,y,val);
    update(idx*2+1,mid+1,r,x,y,val);
}

void BFS(int s){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    build(1,1,n);
//    cout << endl;
    pq.push({0,{s,s}});
    update(1,1,n,s,s,0);
//                for (int i=1; i<=n*3; i++){
//                    if (dist[i] == INF) cout << -1 << " ";
//                    else cout << dist[i] << " ";
//                }
//                cout << endl;
//    for (int i=1; i<=n*4; i++){
//        cout << dist[i] << " ";
//    }
//    cout << endl;
//    cout << "bruh" << endl;
    while (!pq.empty()){
        int d = pq.top().fi;
        int l = pq.top().se.fi;
        int r = pq.top().se.se;
        pq.pop();

        if (MaxQuery(1,1,n,l,r) < d) continue;

//        cout << l << " " << r << " " << d << endl;

        edgelist.clear();
        GetEdge(1,1,n,l,r);
        for (auto idx:edgelist){
//            cout << idx << " " << weight[idx] << " " << path[idx].fi << " " << path[idx].se << endl;
            if (edgevis[idx]) continue;
            int x = path[idx].fi;
            int y = path[idx].se;
            int d2 = d+weight[idx];
            edgevis[idx] = true;

            if (MaxQuery(1,1,n,x,y) > d2){
                update(1,1,n,x,y,d2);
//                for (int i=1; i<=n*3; i++){
//                    if (dist[i] == INF) cout << -1 << " ";
//                    else cout << dist[i] << " ";
//                }
//                cout << endl;
                pq.push({d2,{x,y}});
            }
        }
    }
}

signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> q >> s;

    for (int idx = 1; idx<=q; idx++){
        int meow,v,l,r,w;
        cin >> meow;
        if (meow == 1){
            cin >> v >> l >> w;
            path[idx] = {l,l};
            weight[idx] = w;
            Add(1,1,n,v,v,idx);
        }
        else if (meow == 2){
            cin >> v >> l >> r >> w;
            path[idx] = {l,r};
            weight[idx] = w;
            Add(1,1,n,v,v,idx);
        }
        else{
            cin >> v >> l >> r >> w;
            path[idx] = {v,v};
            weight[idx] = w;
            Add(1,1,n,l,r,idx);
        }
    }
//    cout << "bruh" << endl;
//    for (int i=1; i<=n*3; i++){
//        cout << i << ": ";
//        for (auto idx:IT[i]){
//            cout << idx << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    BFS(s);

    for (int i=1; i<=n; i++){
        int meow = MinQuery(1,1,n,i,i);
        if (meow == INF) cout << -1 << " ";
        else cout << meow << " ";
    }
//    for (int i=1; i<=n*4; i++){
//        for (auto idx:IT[i]){
//            cout << idx << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    return 0;
}
