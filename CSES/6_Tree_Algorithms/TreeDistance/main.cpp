#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

int dist[maxn];
vector<int> a[maxn];
bitset<maxn> visit;

int BFS(int s){
    visit.set();
    int x;
    queue<ii> q;
    q.push({s,0});
    while(!q.empty()){
        int u = q.front().fi;
        int d = q.front().se;
        x = u;
        q.pop();
        dist[u] = max(dist[u],d);
        visit[u] = 0;
        for (auto v:a[u]){
            if (visit[v]){
                q.push({v,d+1});
            }
        }
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int x = BFS(1);
    x = BFS(x);
    x = BFS(x);
    for (int i=1; i<=n; i++){
        cout << dist[i] << " ";
    }
    return 0;
}
