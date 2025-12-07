#include <bits/stdc++.h>
#define mx 100000
#define inf 100001
using namespace std;


int d[inf],ke[3],k,n;
bool visit[inf];

int bfs (int s){
    for (int i=0; i<inf; i++){
        visit[i] = false; d[i] = 100002;
    }
    queue<int> q;
    q.push(s); d[s] = 0; visit[s] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if (visit[k]) return d[k];
        ke[0] = u+1; ke[1] = u-1; ke[2] = u*2;
        for (int i=0; i<3; i++){
            int v = ke[i];
            if (v>=0 && v<=mx && !visit[v]){
                q.push(v);
                d[v] = d[u]+1; visit[v] = true;
            }
        }
    }
    return -1;
}
int main()
{
    freopen("CUUHOA.INP","r",stdin);
    freopen("CUUHOA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    bfs(n);
    cout << d[k];
    return 0;
}
