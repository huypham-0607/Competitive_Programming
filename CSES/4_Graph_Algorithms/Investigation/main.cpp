#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 1e18;
const int DIV = 1e9 + 7;

int n,m,mindist;
vector<vector<ii>> a(maxn),b(maxn);
vector<int> sdist,fdist,maxflight,minflight,cntflight;

void dijkstra(int s,vector<int>& dist,vector<vector<ii>>& a){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    dist.assign(n+10,INF);
    pq.push({0,s});
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;

        pq.pop();

        for (auto in:a[u]){
            int v = in.fi;
            int dnew = d + in.se;

            if (dnew < dist[v]){
                dist[v] = dnew;
                pq.push({dnew,v});
            }
        }
    }
}

void dijkstra2(int s){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    vector<int> visit,vis;
    minflight.assign(n+10,INF);
    maxflight.assign(n+10,0);
    cntflight.assign(n+10,0);
    visit.assign(n+10,false);
    vis.assign(n+10,false);
    pq.push({0,s});
    visit[s] = true;
    minflight[s] = 0;
    maxflight[s] = 0;
    cntflight[s] = 1;
    while(!pq.empty()){
        int u = pq.top().se;
        //int d = pq.top().fi;
        vis[u] = true;
        pq.pop();

        for (auto in:a[u]){
            int v = in.fi;
            int path = in.se;
            if (!vis[v] && sdist[v] + fdist[v] == mindist){
                if (!visit[v]){
                    visit[v] = true;
                    pq.push({sdist[v],v});
                }
                if (sdist[u] + path == sdist[v]){
                minflight[v] = min(minflight[u]+1, minflight[v]);
                maxflight[v] = max(maxflight[u]+1, maxflight[v]);
                cntflight[v] = (cntflight[u] + cntflight[v])%DIV;
                }
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        b[y].push_back({x,z});
    }
    dijkstra(1,sdist,a);
    dijkstra(n,fdist,b);
//    for (int i=1; i<=n; i++){
//        cout << fdist[i] << "\n";
//    }
    mindist = sdist[n];
    dijkstra2(1);
    cout << mindist << " ";
    cout << cntflight[n] << " " << minflight[n] << " " << maxflight[n];
//    cout << "\n" << "\n";
//    for (int i=1; i<=n; i++){
//        cout << minflight[i] << " " << maxflight[i] << " " << cntflight[i] << "\n";
//    }
    return 0;
}
