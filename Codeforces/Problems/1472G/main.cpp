#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,m,t;
vector<int> a[maxn];
int num[maxn],low[maxn];
stack<int> s;

void bfs(){
    queue<pii> q;
    num[1] = 1;
    q.push({1,0});
    while (!q.empty()){
        int u = q.front().fi;
        //int p = q.front().se;
        q.pop();

        s.push(u);
        for (auto v:a[u]){
            if (!num[v]){
                num[v] = num[u]+1;
                q.push({v,u});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i=1; i<=n; i++){
            a[i].clear();
            num[i] = 0;
            low[i] = 0;
        }
        for(int i=1; i<=m; i++){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        bfs();
        while (!s.empty()){
            int u = s.top();
            //cout << u << endl;
            low[u] = num[u];
            for (auto v:a[u]){
                if (num[v] > num[u]){
                    low[u] = min(low[u],low[v]);
                }
                else low[u] = min(low[u],num[v]);
            }
            s.pop();
        }
        for (int i=1; i<=n; i++){
            cout << low[i]-1 << " ";
        }
        cout << endl;
    }
    return 0;
}
