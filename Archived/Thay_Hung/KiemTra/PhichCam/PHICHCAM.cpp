#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 110;
int n,m,k,obj=0;
map<string,int> mp;
int out[N],dev[N];
vector<int> a[N],adj[N*4],mt;
int reach[N*4][N*4];
vector<bool> vis;

void incmp(string s){
    ++obj;
    mp[s] = obj;
}

//BIPARTITE MATCHING
bool match(int u){
    if (vis[u]) return false;
    vis[u] = true;
    for (auto v:a[u]){
        if (!mt[v] || match(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void calcreach(int start){
    queue<int> q;

    vis[start] = true;
    q.push(start);
    while (!q.empty()){
        int u = q.front();
        q.pop();

        reach[start][u] = 1;
        for (auto v:adj[u]){
            if (!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    freopen("PHICHCAM.inp","r",stdin);
    freopen("PHICHCAM.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        if (mp[s] == 0){
            incmp(s);
        }
        out[i] = mp[s];
    }
//    for (int i=1; i<=n; i++){
//        cout << out[i] << " ";
//    }
//    cout << "\n";
    cin >> m;
    for (int i=1; i<=m; i++){
        string s;
        cin >> s >> s;
        if (mp[s] == 0){
            incmp(s);
        }
        dev[i] = mp[s];
    }
//    for (int i=1; i<=m; i++){
//        cout << dev[i] << " ";
//    }
//    cout << "\n";
    cin >> k;
    for (int i=1; i<=k; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if (mp[s1] == 0){
            incmp(s1);
        }
        if (mp[s2] == 0){
            incmp(s2);
        }
        adj[mp[s1]].push_back(mp[s2]);
    }
    for (int i=1; i<=obj; i++){
        vis.assign(obj+10, false);
        calcreach(i);
    }
    for (int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if (reach[dev[i]][out[j]]){
                a[i].push_back(j);
            }
        }
    }
    int c=0;
    mt.assign(n+10,0);
    for (int i=1; i<=m; i++){
        vis.assign(m+10,false);
        if (match(i)) ++c;
    }
    cout << m-c;
    cout << "\n";
//    for(int i=1; i<=obj; i++){
//        for(auto j:a[i]){
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    return 0;
}
