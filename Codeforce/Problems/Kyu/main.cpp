#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int t,n;
vector<ii> a[200100];
vector<int> ans;
bool visit[200100];

ii DFS(int u, int e){
    visit[u] = true;
    int t=0;
    int totalres = 0;
    for (auto in:a[u]){
        int v = in.fi;
        int edge = in.se;
        if (!visit[v]){
            ii res = DFS(v,edge);
            if (res.se == -1) return {t,-1};
            else{
                t+=res.fi;
                totalres+=res.se;
            }
        }
    }
    cout << u << " " << t << " " << totalres << "\n";
    if (t>2) return {t,-1};
    if (t==2){
        ans.push_back(e);
        return {0,totalres+1};
    }
    else return {t+1,totalres};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        ans.clear();
        cin >> n;
        for(int i=1; i<=n; i++){
            a[i].clear();
            visit[i] = false;
        }
        for (int i=1; i<n; i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back({v,i});
            a[v].push_back({u,i});
        }
        ii in = DFS(1,0);
        if (in.se>=0){
            cout << in.se-1 << "\n";
            for (int i=0; i<in.se-1; i++){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}
