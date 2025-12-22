#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define limit 200010

using namespace std;

int parent[limit];
int n,m,t;
vector<int> a[limit];
int point[limit];
bool cheese;
int val[limit];

void InitSet(int n){
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int FindSet(int x){
    return (parent[x] == x)? x : parent[x] = FindSet(parent[x]);
}

bool SameSet(int x, int y){
    return (FindSet(x) == FindSet(y));
}

void UnionSet2(int x,int y){
    if (!SameSet(x,y)){
        parent[x] = FindSet(y);
    }
}

void UnionSet (int x, int y){
    if (!SameSet(x,y)){
        val[y]+=val[parent[x]];
        val[parent[x]] = 0;
        parent[FindSet(x)] = FindSet(y);
    }
}

void BFS(int s){
    priority_queue<ii,vector<ii>,greater<ii>> q;
    int level = 0;
    q.push({point[s],s});
    while (!q.empty()){
        int u = q.top().se;
        int d = q.top().fi;
        q.pop();

        if (level<d) break;
        level+=val[parent[u]];
        UnionSet(u,s);

        for (auto v:a[u]){
            if (!SameSet(u,v)) q.push({point[v],v});
        }
    }
    //cout << level << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> m;
        InitSet(n);
        for (int i=1; i<=n; i++){
            val[i] = 1;
        }
        for (int i=1; i<=n; i++){
            cin >> point[i];
            a[i].clear();
        }
        while (m--){
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i=1; i<=n; i++){
            if (point[i] == 0){
                BFS(i);
            }
        }

        bool v = false;
        if (n==1 && point[1]!=0) v=true;
        for (int i=1; i<n; i++){
            if (!SameSet(i,i+1)){
                v = true;
                break;
            }
        }
        if (v) cout << "NO" << "\n";
        else cout << "YES" << "\n";
        /*for (int i=1; i<=n; i++){
            cout << val[i] << " ";
        }*/
    }
    return 0;
}
