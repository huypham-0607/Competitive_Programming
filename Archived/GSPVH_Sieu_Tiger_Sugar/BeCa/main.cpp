#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 2e6 + 5;

struct edge{
    int u,v,w;
    int x,y;
    edge(int a,int b,int c,int xx,int yy){
        u = a;
        v = b;
        w = c;
        x = xx;
        y = yy;
    }
    bool operator < (edge& a) const{
        return this->w < a.w;
    }
};

int n,m;
ll mst;
int p[N];
vector<vector<char> > a;
vector<vector<int> > wei;
vector<edge> e;

void init(){
    memset(p,-1,sizeof(p));
}

int root(int u){
    return (p[u] < 0 ? u : p[u] = root(p[u]));
}

bool join(int u,int v){
    u = root(u);
    v = root(v);
    if (u == v) return 0;
    if (p[u] > p[v]) swap(u,v);
    p[u] += p[v];
    p[v] = u;
    return 1;
}

void kruskal(){
    sort(e.begin(),e.end());
    int u,v,w;
    for (int i = 0; i < e.size(); i++){
        //cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
        if (join(e[i].u,e[i].v)){
            mst += e[i].w;
            a[e[i].x][e[i].y] = '.';
        }
    }
}

int main(){
    freopen("aquarium.INP","r",stdin);
    freopen("aquarium.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    char t;
    init();
    cin >> r >> c;
    int x = 1;
    a.assign(r, vector<char>(c));
    wei.assign(r, vector<int>(c));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> wei[i][j];
            //if (a[i][j] == '\');
            e.push_back(edge(x,x + 1,wei[i][j],i,j));
            if (a[i][j] == 92){
                if (i > 0){
                    if (a[i-1][j] == 92) join(x + 1,x - 2 * c);
                    else join(x + 1,x - 2 * c + 1);
                }
            }
            else{
                if (i > 0){
                    if (a[i-1][j] == 92) join(x,x - 2 * c);
                    else join(x,x - 2 * c + 1);
                }
            }
            if (j > 0) join(x,x - 1);
            x += 2;
        }
    }
    kruskal();
    cout << mst << "\n";
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) cout << a[i][j];
        cout << "\n";
    }
    return 0;
}
