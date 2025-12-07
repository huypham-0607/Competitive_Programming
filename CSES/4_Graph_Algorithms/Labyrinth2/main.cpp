#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e3+10;

int di[4] = {1,0,-1,0},
    dj[4] = {0,1,0,-1};
string dir[4] = {"D","R","U","L"};
int m,n;
ii parent[maxn][maxn];
string ploc[maxn][maxn];
int a[maxn][maxn];
ii s,e;

bool check(ii u){
    return (u.fi > 0 && u.fi <=n && u.se > 0 && u.se <=m);
}

void bfs(){
    queue<ii> q;
    q.push(s);
    parent[s.fi][s.se] = {-1,-1};
    while (!q.empty()){
        ii u = q.front();
        q.pop();
        for (int x=0; x<4; x++){
            ii v = {u.fi+di[x], u.se+dj[x]};
            if (check(v) && !a[v.fi][v.se] && parent[v.fi][v.se].fi == 0){
                parent[v.fi][v.se] = u;
                ploc[v.fi][v.se] = dir[x];
                q.push(v);
            }
        }
    }
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c;
            cin >> c;
            if (c == '#') a[i][j] = 1;
            else a[i][j] = 0;
            if (c == 'A') s = {i,j};
            if (c == 'B') e = {i,j};
        }
    }
    int tam;
//    cout << parent[1][1].fi << " " << parent[1][1].se;
    bfs();
    if (parent[e.fi][e.se].fi == 0){
        cout << "NO";
    }
    else{
        int c = 0;
        ii u = e;
        stack<string> st;
        while (u!=s){
            st.push(ploc[u.fi][u.se]);
            c++;
            u = parent[u.fi][u.se];
        }
        cout << "YES" << "\n";
        cout << c << "\n";
        while (!st.empty()){
            cout << st.top();
            st.pop();
        }
    }
    return 0;
}
