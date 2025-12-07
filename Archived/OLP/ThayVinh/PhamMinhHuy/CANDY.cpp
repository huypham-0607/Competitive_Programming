#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 1e9+7;

int test;
int n;
bool vis[maxn];
int dist[maxn];
int h[maxn];
int a[maxn];
int length;

int epic(int u,int height){
    h[u] = height;
    vis[u] = true;
    int v = a[u];
    if (vis[v]){
        if (dist[v]){
            dist[u] = dist[v]+1;
            return INF;
        }
        else{
            dist[u] = h[u]-h[v]+1;
            return h[v];
        }
    }
    else{
        int height2 = epic(v,height+1);
        if (height >= height2){
            dist[u] = dist[v];
        }
        else dist[u] = dist[v]+1;
//        cout << u << " " << height2 << endl;
        return height2;
    }
}


//void FindCycle(int s){
//    int x = a[s];
//    int y = a[x];
//    while (x!=y){
//        x = a[x];
//        y = a[a[y]];
//    }
//    check[x] = true;
//    y = a[x];
//    int c = 1;
//    while (y!=x){
//        check[y] = true;
//        c++;
//        y = a[y];
//    }
//    do{
//        dist[y] = c;
//        for (auto v:b[y]){
//            if(check[v]) continue;
//            epic(v);
//        }
//        y = a[y];
//    } while (y!=x);
//}

int main(){
    freopen("CANDY.inp","r",stdin);
    freopen("CANDY.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            epic(i,1);
        }
    }

    for (int i=1; i<=n; i++){
        cout << dist[i] << endl;
    }
    return 0;
}
