#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 510;
const int INF = 1e15;

int n,m;
vector<int> a[maxn],parent;
int cap[maxn][maxn];

int Newflow(){
    parent.assign(maxn,0);
    parent[1] = -1;
    queue<ii> q;
    q.push({1,INF});
    while (!q.empty()){
        int u = q.front().fi;
        int vol = q.front().se;
        //cout << u << " " << vol << "\n";
        q.pop();

        for (auto v:a[u]){
            if (parent[v]==0 && cap[u][v]!=0){
                int newvol = min(cap[u][v],vol);
                parent[v] = u;

                if (v == n){
                    return newvol;
                }
                q.push({v,newvol});
            }
        }
    }
    return 0;
}

int Flow(){
    int totalflow = 0;
    int vol;
    while (vol = Newflow()){
        totalflow += vol;
        //cout << totalflow << "\n";
        int u = n;
        while (u!=1){
            int v = parent[u];
            cap[u][v]+=vol;
            cap[v][u]-=vol;
            u = v;
        }
    }
    return totalflow;
}

signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(y);
        a[y].push_back(x);
        cap[x][y] += z;
    }
    cout << Flow();
    return 0;
}
