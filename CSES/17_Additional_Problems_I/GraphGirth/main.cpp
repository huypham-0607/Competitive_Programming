#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e4+520;
const int INF = 2e9;

int test;
int n,m;
vector<int> a[maxn];
int h[maxn];
bool visit[maxn];

int BFS(int s){
    int res = INF;
    visit[s] = 1;
    queue<piii> q;
    q.push({{s,0},0});
    while (!q.empty()){
        int u = q.front().fi.fi;
        int p = q.front().fi.se;
        int d = q.front().se;
        h[u] = d;
        q.pop();

        for (auto v:a[u]){
            if (v == p) continue;
            if (visit[v]) res = min(res,d+1+h[v]);
            if (!visit[v]){
                visit[v] = 1;
                q.push({{v,u},d+1});
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int res = INF;
    for (int i=1; i<=n; i++){
        for (int i=1; i<=n; i++){
            h[i] = INF;
        }
        memset(visit,0,sizeof(visit));
        int meow = BFS(i);
//        cout << meow << endl;
        res = min(res,meow);
    }
    if (res == INF) cout << -1;
    else cout << res;
    return 0;
}
