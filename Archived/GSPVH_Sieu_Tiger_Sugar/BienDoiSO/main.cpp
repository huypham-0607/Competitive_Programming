#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int d[1000005];
vector<int> di[1000005];
bitset<1000005> visited;

void sieve(int n){
    for (int i = 2; i * i <= n; i++){
        di[i * i].push_back(i);
        for (int j = i + 1; i * j <= n; j++){
            di[i * j].push_back(i);
            di[i * j].push_back(j);
        }
    }
}

int bfs(int u,int s){
    visited.reset();
    queue<int> q;
    q.push(u);
    d[u] = 0;
    visited[u] = 1;
    while(!q.empty()){
        u = q.front();
        if (u == s) return d[s];
        q.pop();
        for (int v : di[u]){
            if (u + v > s || visited[u + v]) continue;
            visited[u + v] = 1;
            d[u + v] = d[u] + 1;
            q.push(u + v);
        }
    }
    return -1;
}

int main(){
    freopen("divisors.INP","r",stdin);
    freopen("divisors.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s,t;
    cin >> s >> t;
    sieve(1000000);
    cout << bfs(s,t);
    return 0;
}
