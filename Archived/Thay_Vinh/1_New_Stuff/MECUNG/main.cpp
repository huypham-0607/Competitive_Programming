#include <bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,ii>
#define numlim 999999999
#define fi first
#define se second

using namespace std;

int di[4] = {1,0,-1,0}, dj[4] = {0,1,0,-1};
int dist[1000][1000], a[1000][1000];
int ans,n,m,k,si,sj;

bool oob(int x, int y){
    if ((x<1 || x>n) && (y<1 || y>m)) return true;
    else return false;
}

void dijkstra(int x,int y){

    priority_queue <iii, vector<iii>, greater<iii> > pq;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dist[i][j] = numlim;
        }
    }
    pq.push({0,x,y});

    while (!pq.empty()){
        int t = pq.top().fi;
        int ui = pq.top().se.fi;
        int uj = pq.top().se.se;

        if (oob(ui,uj)) return t+a[ui][uj];
        if (!a[ui][uj]) continue;
        a[ui][uj] = 0;

        pq.pop();

        for (int x=0; x<4; x++){
            int vi = ui+di[x];
            int vj = uj+dj[x];

            if (a[vi][vj]){
                if (dist[vi][vj]>t+a[vi][vj]){
                    dist[vi][vj] = t+a[vi][vj];
                    pq.push({t+a[vi][vj],vi,vj});
                }
            }
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i=0; i<=n+1 i++){
        for (int j=0; j<=m+1; j++){
            a[i][j] = 1;
            if (!oob(i,j)){
                cin >> c;
                if (c=='A'){
                    si = i;
                    sj = j;
                }
                else if (c=='#') a[i][j]--;
                else if (c=='C') a[i][j]+=k;
            }
        }
    }

    int ans = dijkstra(si,sj);
    cout << ans;

    return 0;
}
