#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define i first
#define j second

using namespace std;

const int maxn = 1e3+10;
const int INF = 1e9;

int di[4] = {1,0,-1,0},
    dj[4] = {0,1,0,-1};
char dir[4] = {'D','R','U','L'};
int req[maxn][maxn], dist[maxn][maxn],parent[maxn][maxn],a[maxn][maxn];
int m,n;
ii s;
vector<ii> mons;

int check(ii x){
    int i = x.i;
    int j = x.j;
    return (i>0 && i<=n && j>0 && j<=m);
}

int check2(ii x){
    int i = x.i;
    int j = x.j;
    return (i==1 || i==n || j==1 || j==m);
}

void reqcalc(){
    queue<iii> q;
    for (auto in:mons){
        q.push({in,0});
        req[in.i][in.j] = -1;
    }

    while (!q.empty()){

        iii in = q.front();
        q.pop();

        ii u = in.i;
        //cout << u.i << " " << u.j << "\n";
        int t = in.j;
        req[u.i][u.j] = t;

//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=m; j++){
//                if (req[i][j]!=-1) cout << " ";
//                cout << req[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        for (int x=0; x<4; x++){
            ii v = {u.i+di[x],u.j+dj[x]};
            if (check(v) && !a[v.i][v.j] && req[v.i][v.j] == INF){
                req[v.i][v.j] = t+1;
                q.push({v,t+1});
            }
        }
    }
}

ii calc(){
    queue<iii> q;
    q.push({s,0});
    parent[s.i][s.j] = -1;
    dist[s.i][s.j] = 0;
    if (check2(s)) return s;
    while (!q.empty()){
        iii in = q.front();
        q.pop();

        ii u = in.i;
        int t = in.j;
        //req[u.i][u.j] = t;

//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=m; j++){
//                if (req[i][j]!=-1) cout << " ";
//                cout << req[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        for (int x=0; x<4; x++){
            ii v = {u.i+di[x],u.j+dj[x]};
            if (check(v) && parent[v.i][v.j] == -2 && !a[v.i][v.j] && t+1 < req[v.i][v.j]){
                parent[v.i][v.j] = x;
                dist[v.i][v.j] = t+1;
                if (check2(v)) return v;
                q.push({v,t+1});
            }
        }
    }
    return {0,0};
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            req[i][j] = INF;
            parent[i][j] = -2;
            char c;
            cin >> c;
            if (c == '#'){
                a[i][j] = 1;
                req[i][j] = -1;
            }
            if (c == 'M'){
                mons.push_back({i,j});
            }
            if (c == 'A'){
                s = {i,j};
            }
        }
    }
    reqcalc();
    ii des = calc();
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            if (parent[i][j]>-1) cout << " ";
//            cout << parent[i][j] << " ";
//        }
//        cout << "\n";
//    }
    if (des.i != 0){
        cout << "YES" << "\n";
        stack<char> s;
        int i = des.i;
        int j = des.j;
        cout << dist[i][j] << "\n";
        while (dist[i][j]!=0){
            int x = parent[i][j];
            s.push(dir[x]);
            i-=di[x];
            j-=dj[x];
        }
        while (!s.empty()){
            cout << s.top();
            s.pop();
        }
    }
    else cout << "NO" << "\n";
    return 0;
}
