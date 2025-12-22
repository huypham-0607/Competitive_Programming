#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+100;
const int INF = 2e9;

int n,t,m;
vector<int> a[maxn],remain[maxn];
vector<int> startnode,lvl(maxn,0);
vector<bool> visit1,visit2,visit3;
int parent[maxn],memcnt[maxn];

void InitSet(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        memcnt[i] = 1;
    }
}

int FindSet(int x){
    return (parent[x] == x)? x : parent[x] = FindSet(parent[x]);
}

bool SameSet(int x, int y){
    return (FindSet(x) == FindSet(y));
}

void UnionSet(int x,int y){
    if (!SameSet(x,y)){
        memcnt[FindSet(x)] += memcnt[FindSet(y)];
        memcnt[FindSet(y)] = 0;
        parent[FindSet(y)] = FindSet(x);
    }
}

int BFS(){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    int maxpower = 0;
    for (auto s:startnode){

        if (visit1[s]) continue;
        pq.push({0,s});
        int power = 0;
        while (!pq.empty() && pq.top().fi <= power){
            int u = pq.top().se;
            pq.pop();

            if (visit1[u]) continue;
            visit1[u] = true;
            power+=memcnt[u];
            UnionSet(s,u);

            for (auto v:a[u]){
                if (visit1[v] && FindSet(v)!=s && !visit3[FindSet(v)]){
                    power+=memcnt[FindSet(v)];
                    visit3[FindSet(v)] = true;
                    for (auto x:remain[FindSet(v)]){
                        pq.push({lvl[x],x});
                    }
                    UnionSet(s,v);
                }
                pq.push({lvl[v],v});
            }
        }
        maxpower = max(maxpower,power);
        while (!pq.empty()){
            remain[s].push_back(pq.top().se);
            pq.pop();
        }
    }
    return maxpower;
}

int checkgraph(){
    queue<int> q;
    q.push(1);
    int c = 0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (visit2[u]) continue;
        visit2[u] = true;
        c++;

        for (auto v:a[u]){
            if (!visit2[v]){
                q.push(v);
            }
        }
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m;
        InitSet(n);
        startnode.clear();
        visit1.assign(n+10,false);
        visit2.assign(n+10,false);
        visit3.assign(n+10,false);
        for (int i = 1; i<=n; i++){
            a[i].clear();
            cin >> lvl[i];
            if (lvl[i] == 0){
                startnode.push_back(i);
            }
        }
        while (m--){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if (checkgraph()<n) cout << "NO" << "\n";
        else{
            int cnt = 0;
            cnt = BFS();
            if (cnt<n) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }
    return 0;
}
