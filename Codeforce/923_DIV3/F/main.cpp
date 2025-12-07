#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,m,timedfs;
int num[maxn],low[maxn],bot[maxn],parent[maxn],top[maxn];
vector<piii> v;
vector<pii> a[maxn];

void dfs(int u, int p){
    parent[u] = p;
    num[u] = ++timedfs;
    low[u] = num[u];
    bot[u] = u;
    top[u] = u;
    for (auto in:a[u]){
        int v = in.fi;
        if (v == p) continue;
        if (!num[v]){
            dfs(v,u);
            if (low[u] > low[v]){
                low[u] = low[v];
                bot[u] = bot[v];
                top[u] = top[v];
            }
        }
        else{
            if (low[u] > num[v]){
                low[u] = num[v];
                bot[u] = u;
                top[u] = v;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    cout << endl;
    cin >> test;
//    int prevn = 0;
    while (test--){
        cin >> n >> m;
        v.clear();
        for (int i=1; i<=n; i++){
            a[i].clear();
            num[i] = 0;
            low[i] = 0;
            parent[i] = 0;
            bot[i] = i;
            top[i] = i;
        }
        for (int i=1; i<=m; i++){
            int x,y,z;
            cin >> x >> y >> z;
            a[x].push_back({y,z});
            a[y].push_back({x,z});
            v.push_back({z,{x,y}});
        }
        timedfs = 0;
        for (int i=1; i<=n; i++){
            if (!num[i]){
                dfs(i,0);
            }
        }
        sort(v.begin(),v.end());
        for (auto in:v){
            int w = in.fi;
            int u = in.se.fi;
            int v = in.se.se;
            if (num[u] > num[v]) swap(u,v);
//            cout << u << " " << v << " " << w << endl;
//            cout << low[v] << " " << bot[v] << endl;
            if (low[v] <= num[u]){
                int i,j;
                if (parent[v]!=u){
                    i = u;
                    j = v;
                }
                else{
                    i = top[v];
                    j = bot[v];
                }
                int cnt = 0;
                stack<int> s;
                while (j!=i){
                    cnt++;
                    s.push(j);
                    j = parent[j];
                }
                s.push(i);
                ++cnt;
                cout << w << " " << cnt << endl;
                while (!s.empty()){
                    cout << s.top() << " ";
                    s.pop();
                }
                cout << endl;
                break;
            }
        }
//        for (int i=1; i<=n; i++){
//            cout << num[i] << " " << low[i] << " " << top[i] << " " << bot[i] << endl;
//        }
    }

    return 0;
}
