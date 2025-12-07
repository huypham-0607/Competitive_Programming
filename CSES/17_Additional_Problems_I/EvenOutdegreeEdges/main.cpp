#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 3e5+10;
const int INF = 2e9;

int n,m,timedfs=0;
int c[maxn],remain[maxn],out[maxn];
int num[maxn],low[maxn],meow[maxn];
bool odd[maxn];
bool vis[maxn],vis2[maxn];
vector<int> a[maxn];
vector<pii> ans;
priority_queue<pii,vector<pii>,greater<pii>> pq;

int DFS(int u,int p){
    num[u] = ++timedfs;
    meow[timedfs] = u;
    vis[u] = true;
    int cnt = a[u].size();
//    c[u] = a[u].size();
//    remain[u] = a[u].size();
//    pq.push({a[u].size(),u});
    for (auto v:a[u]){
        if (v == p) continue;
        if (!num[v]){
            cnt+=DFS(v,u);
            if (odd[v]){
                odd[v] = !odd[v];
                ans.push_back({v,u});
            }
            else{
                odd[u] = !odd[u];
                ans.push_back({u,v});
            }
        }
        else{
            if (num[u] > num[v]){
                remain[u]--;
                remain[v]--;
                odd[u] = !odd[u];
                ans.push_back({u,v});
            }
        }
    }
    return cnt;
}


int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
     n = 100000;
    cin >> n >> m;
    bool ver = true;
    while (m--){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
//    int c = 0;
//    for (int i=1; i<=n; i++){
//        if (!vis[i]){
////            ++c;
//            int cnt = DFS(i);
//            cnt/=2;
//            if (cnt%2){
//                ver = false;
//                break;
//            }
//            while (!pq.empty()){
//                int u = pq.top().se;
//                pq.pop();
////                cout << "[" << u << "]" << endl;
//                vis2[u] = true;
////                cout << c[u] << " " << remain[u] << " " << out[u] << " ";
//                int cnt = 0;
//                int lim = remain[u] - remain[u]%2;
//                if (out[u]%2){
//                    if (remain[u]%2) lim+=1;
//                    else lim-=1;
//                }
////                cout << lim << endl;
//                for (auto v:a[u]){
//                    if (!vis2[v]){
//                        ++cnt;
//                        if (cnt <= lim){
//                            remain[v]-=1;
//                            remain[u]-=1;
//                            out[u]+=1;
//                            ans.push_back({u,v});
//                        }
//                        else{
//                            remain[v]-=1;
//                            remain[u]-=1;
//                            out[v]+=1;
//                            ans.push_back({v,u});
//                        }
//                        pq.push({remain[v],v});
//                    }
//                }
//            }
//        }
//    }
    for (int i=1; i<=n; i++){
        if (!num[i]){
            int cnt = DFS(i,0);
            cnt = cnt/2;
            if (cnt%2){
                ver = false;
                break;
            }
        }
    }
    if (ver){
        for (auto in:ans){
            cout << in.fi << " " << in.se << endl;
        }
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
