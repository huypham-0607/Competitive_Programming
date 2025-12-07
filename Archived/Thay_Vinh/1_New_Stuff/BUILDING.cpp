#include <bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second

using namespace std;

const int maxn = 5e2 + 2;
const int INF = 2e9;

int a[maxn][maxn];
int di[4] = {0,0,1,-1},
    dj[4] = {1,-1,0,0};
bool visit[maxn][maxn];
int n,m;

bool check(int i, int j)
{
    return (i <= n && i >= 1 && j <= m && j >= 1);
}

void BFS(int si, int sj){
    queue<ii> q;
    q.push({si,sj});
    while (!q.empty()){
        int ui = q.front().fi;
        int uj = q.front().se;
        q.pop();
        for (int i = 0; i <= 3; i++){
            int vi = ui + di[i];
            int vj = uj + dj[i];
            if (!visit[vi][vj] && a[si][sj]>=a[vi][vj] && a[vi][vj]!=0 && check(vi, vj))
            {
                visit[vi][vj] = true;
                q.push({vi, vj});
            }
        }
    }
}

int main()
{
    freopen("BUILDING.INP", "r", stdin);
    freopen("BUILDING.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<iii> pq;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1) a[i][j] = 0;
            if (a[i][j] != 0) pq.push({a[i][j], {i,j}});
        }
    }
    int res = 0;
    while (!pq.empty())
    {
            int i = pq.top().se.fi;
            int j = pq.top().se.se;
            pq.pop();
            if (a[i][j]!=0 && !visit[i][j])
            {
                BFS(i,j);
                res++;
            }
        }
        cout << res;
    return 0;
}
