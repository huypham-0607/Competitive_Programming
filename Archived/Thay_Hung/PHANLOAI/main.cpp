#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1100;
const int INF = 2e9;

int nk,np,t;
vector<int> parent;
int cap[maxn][maxn];
vector<int> a[maxn];

int Newflow(){
    parent.assign(maxn,-1);
    parent[0] = -2;
    queue<ii> q;
    q.push({0,INF});
    while (!q.empty()){
        int u = q.front().fi;
        int vol = q.front().se;
        q.pop();

        for (auto v:a[u]){
            if (parent[v]==-1 && cap[u][v]!=0){
                int newvol = min(cap[u][v],vol);
                parent[v] = u;

                if (v == nk+np+1){
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
    while ((vol = Newflow())){
        totalflow += vol;
        //cout << totalflow << " meow" << "\n";
        //cout << totalflow << "\n";
        int u = nk+np+1;
        while (u!=0){
            int v = parent[u];
            cap[u][v]+=vol;
            cap[v][u]-=vol;
            u = v;
        }
    }
    return totalflow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> nk >> np;
    while (nk){
        t = 0;
        for (int i=1; i<=nk; i++){
            int x;
            cin >> x;
            t+=x;
            a[0].push_back(i);
            a[i].push_back(0);
            cap[0][i] = x;
        }
        for (int i=1; i<=np; i++){
            int x,y;
            cin >> x;
            while (x--){
                cin >> y;
                a[y].push_back(nk+i);
                a[nk+i].push_back(y);
                cap[y][nk+i] = 1;
            }
            a[nk+i].push_back(nk+np+1);
            a[nk+np+1].push_back(nk+i);
            cap[nk+i][nk+np+1] = 1;
        }
        int res = Flow();
        if (res == t) cout << 1 << "\n";
        else cout << 0 << "\n";
        cin >> nk >> np;
    }
    return 0;
}
