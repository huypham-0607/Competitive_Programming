#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,ans;
int a[maxn],b[maxn];
vector<int> adj[maxn];
queue<int> order;
queue<int> q;
stack<int> s;
priority_queue<int> pq;
//bool visit[maxn];

void dfs(int u, int p){
//    visit[u] = true;
    for (auto v:adj[u]){
        dfs(v,u);
    }
    if (a[u] >= 0){
        ans+=a[u];
        order.push(u);
        a[p]+=a[u];
    }
    else{
        ans+=a[u];
        s.push(u);
    }
}

void dfs2(int u){
    ans+=a[u];
    order.push(u);
    for (auto v:adj[u]){
        dfs2(v);
    }
}

void process(int u, int val){

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans = 0;
    cin >> n;
    queue<int> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
//        pq.push({a[i],i});
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        if (b[i] == -1){
            q.push(i);
        }
        else adj[b[i]].push_back(i);
    }
    while (!q.empty()){
        dfs(q.front(),0);
        q.pop();
    }
    cout << ans << endl;
    while (!order.empty()){
        cout << order.front() << " ";
        order.pop();
    }
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
