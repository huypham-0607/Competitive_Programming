#include <bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define limit 1000000000
#define mp make_pair
using namespace std;

int di[4] = {0,1,0,-1},
    dj[4] = {1,0,-1,0},
    dist[110][110];

int m,n,a[110][110];

bool ib(int i,int j){
    return (i>0 && i<=n && j>0 && j<=m);
}

int dijkstra(int v){
    //int dist[110][110];
    priority_queue <iii,vector<iii>,greater<iii>> pq;
    //pq.push(mp(0,mp(1,1)));
    //memset(dist,limit,sizeof(dist));
    bool mark[110][110];
    memset(mark,0,sizeof(mark));
    //cout << "memset:" << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dist[i][j] = limit;
        }
        //cout << endl;
    }
    //cout << endl;
    dist[1][1] =abs(a[1][1] -v);
    pq.push(mp(dist[1][1],mp(1,1)));
    while (!pq.empty()){
        int d =pq.top().fi;
        int ui = pq.top().se.fi;
        int uj = pq.top().se.se;
        //cout << "main: " << d << " " << ui << " " << uj << endl;
        pq.pop();
        //if (ui==n && uj==m) return d;
        if (mark[ui][uj]) continue;
        mark[ui][uj] = true;
        for (int x=0; x<4; x++){
            int vi = ui+di[x];
            int vj = uj+dj[x];
            if (ib(vi,vj)){
                int dnew = dist[ui][uj]+abs(a[vi][vj] - v);
               // cout << dnew << " " << vi << " " << vj << endl;
                if (ib(vi,vj) && dnew < dist[vi][vj]){
                    dist[vi][vj] = dnew;
                    pq.push(mp(dnew,mp(vi,vj)));
                }
            }

        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            //cout << dist[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;
    return dist[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    int ans = limit;
    for (int i=1; i<=100; i++){
        ans = min(ans,dijkstra(i));
    }
    cout << ans;
    return 0;
}
