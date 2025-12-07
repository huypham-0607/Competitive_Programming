#include <bits/stdc++.h>

using namespace std;

const int N = 105;

struct point{
    double x,y;
};

bool visited[2 * N];
vector<int> a[2 * N];
int match[2 * N];
int n,m,s,v;
point mouse[N];
point cave[N];

double dis(point& a,point& b){
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

int aug(int u){
    if (visited[u]) return 0;
    visited[u] = 1;
    for (int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if (match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("chuotchui.inp","r",stdin);
    freopen("chuotchui.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> s >> v;
    for (int i = 1; i <= n; i++){
        cin >> mouse[i].x >> mouse[i].y;
    }
    for (int i = 1; i <= m; i++){
        cin >> cave[i].x >> cave[i].y;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (dis(mouse[i],cave[j]) <= s * v){
                a[i].push_back(j + n);
            }
        }
    }
    memset(match,-1,sizeof(match));
    int res = n;
    for (int i = 1; i <= n; i++){
        memset(visited,0,sizeof(visited));
        res -= aug(i);
    }
    cout << res;
}
