#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "mmgraph"

using namespace std;

/*Constants*/
const int N = 500+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int test;
int sb;
int n,m;
int w[N];
int dist[N][N];

/*Inititalization*/
void Init(){
    cin >> sb;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> w[i];
        for (int j=1; j<=n; j++){
            dist[i][j] = LLINF;
        }
    }
    while (m--){
        int u,v,x;
        cin >> u >> v >> x;
        dist[u][v] = x;
        dist[v][u] = x;
    }
}

/*Subtask1*/
bool CheckSub1(){
    if (sb==1) return true;
    return false;
}

void SolveSub1(){
    for (int i=1; i<=n; i++){
        cout << n-1 << " ";
    }
}

/*Subtask2*/
bool CheckSub2(){
    if (sb == 2) return true;
    return false;
}

void SolveSub2(){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i==j) continue;
                dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));
            }
        }
    }
    for (int i=1; i<=n; i++){
        int cnt = 0;
        for (int j=1; j<=n; j++){
            if (dist[i][j]!=LLINF) cnt+=dist[i][j];
        }
        cout << cnt << " ";
    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            if (dist[i][j] == LLINF) cout << 0 << " ";
//            else cout << dist[i][j] << " ";
//        }
//        cout << endl;
//    }
}

/*Subtask3*/
bool CheckSub3(){
    if (sb == 3) return true;
    return false;
}

void SolveSub3(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (dist[i][j] == INF) continue;
            dist[i][j] = max(w[i],w[j]);
        }
    }
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i==j) continue;
                dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));
            }
        }
    }
    for (int i=1; i<=n; i++){
        int cnt = 0;
        for (int j=1; j<=n; j++){
            if (dist[i][j]!=LLINF) cnt+=dist[i][j];
        }
        cout << cnt << " ";
    }
}

/*Subtask4*/
bool CheckSub4(){
    if (sb == 4) return true;
    return false;
}

void SolveSub4(){

}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;


    return 0;
}

