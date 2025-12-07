/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;
vector<int> a[N];

//Seggs
int ST[N*4];
int lazy[N*4];

void PropagateST(int& idx){
    int t = lazy[idx];

    ST[idx*2]+=t;
    lazy[idx*2]+=t;
    ST[idx*2+1]+=t;
    lazy[idx*2+1]+=t;

    lazy[idx] = 0;
}

void UpdateST(int idx, int l, int r, int x, int y, int v){
    if (r<x || y<l) return;
    if (x<=l && r<=y){
        ST[idx]+=v;
        lazy[idx]+=v;
        return;
    }

    PropagateST(idx);

    int mid = (l+r)/2;
    UpdateST(idx*2,l,mid,x,y,v); UpdateST(idx*2+1,mid+1,r,x,y,v);
    ST[idx] = max(ST[idx*2],ST[idx*2+1]);
}

int QueryST(int idx, int l, int r, int x, int y){
    if (r<x || y<l) return 0;
    if (x<=l && r<=y){
        return ST[idx];
    }

    PropagateST(idx);

    int mid = (l+r)/2;
    return max(QueryST(idx*2,l,mid,x,y),QueryST(idx*2+1,mid+1,r,x,y));
}

//HLD
int CCur=1, timedfs=0;
int depth[N],parent[N],sz[N];
int CID[N],CHead[N],Pos[N];

void DFS(int u, int p){
    depth[u] = depth[p]+1;
    parent[u] = p;
    sz[u] = 1;

    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void GetHLD(int u, int p){
    if (!CHead[CCur]) CHead[CCur] = u;
    CID[u] = CCur;
    Pos[u] = ++timedfs;

    int nxt = 0;
    for (auto v:a[u]){
        if (v==p) continue;
        if (sz[v]>sz[nxt]) nxt = v;
    }

    if (nxt) GetHLD(nxt,u);

    for (auto v:a[u]){
        if (v==p || v==nxt) continue;
        ++CCur;
        GetHLD(v,u);
    }
}

void Query1(int u, int v, int val){
    while (CID[u]!=CID[v]){
        if (CID[u]>CID[v]){
            UpdateST(1,1,n,Pos[CHead[CID[u]]],Pos[u],val);
            u = parent[CHead[CID[u]]];
        }
        else{
            UpdateST(1,1,n,Pos[CHead[CID[v]]],Pos[v],val);
            v = parent[CHead[CID[v]]];
        }
    }
    if (depth[u]>depth[v]){
        UpdateST(1,1,n,Pos[v],Pos[u],val);
    }
    else{
        UpdateST(1,1,n,Pos[u],Pos[v],val);
    }
}

void Query2(int u, int val){
    UpdateST(1,1,n,Pos[u],Pos[u]+sz[u]-1,val);
}

int Query3(int u, int v){
    int res = 0;
    while (CID[u]!=CID[v]){
        if (CID[u]>CID[v]){
            res = max(res,QueryST(1,1,n,Pos[CHead[CID[u]]],Pos[u]));
            u = parent[CHead[CID[u]]];
        }
        else{
            res = max(res,QueryST(1,1,n,Pos[CHead[CID[v]]],Pos[v]));
            v = parent[CHead[CID[v]]];
        }
    }
    if (depth[u]>depth[v]){
        res = max(res,QueryST(1,1,n,Pos[v],Pos[u]));
    }
    else{
        res = max(res,QueryST(1,1,n,Pos[u],Pos[v]));
    }
    return res;
}

int Query4(int u){
    return QueryST(1,1,n,Pos[u],Pos[u]+sz[u]-1);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1,0);
    GetHLD(1,0);
    int id,x,y,z;
    while (q--){
        cin >> id;
        if (id == 1){
            cin >> x >> y >> z;
            Query1(x,y,z);
        }
        if (id == 2){
            cin >> x >> y;
            Query2(x,y);
        }
        if (id == 3){
            cin >> x >> y;
            cout << Query3(x,y) << endl;
        }
        if (id == 4){
            cin >> x;
            cout << Query4(x) << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
