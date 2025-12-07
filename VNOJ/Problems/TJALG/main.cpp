#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 10010

using namespace std;

int n,m;
vector<int> a[lim];
bool mark[lim],vis[lim];
int id[lim],low[lim];
stack<int> s;
int c=0;
int ans;

void dfs(int u){
    s.push(u);
    vis[u] = true;
    mark[u] = true;
    c++;
    id[u] = c;
    low[u] = c;

    for (auto v:a[u]){
        if (!vis[v]){
            dfs(v);
            if (mark[v]) low[u] = min(low[u],low[v]);
        }
        else{
            if (mark[v]) low[u] = min(low[u],id[v]);
        }
    }
    if (id[u] == low[u]){
        ans++;
        while (s.top()!=u){
            mark[s.top()] = false;
            s.pop();
        }
        mark[u] = false;
        s.pop();
    }
    /*cout << "[" << u << "]" << " " << s.size() << endl;
    for (int i=1; i<=n; i++){
        cout << id[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << low[i] << " ";
    }
    cout << endl << endl;*/
}

void tarjan(){
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    tarjan();
    cout << ans;
    return 0;
}
