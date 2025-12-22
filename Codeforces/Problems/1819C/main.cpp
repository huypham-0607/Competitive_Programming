#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;

struct{
    vector<int> light;
    int heavy;
} info[maxn];

int n,root,maxlvl;
int lvl[maxn],child[maxn];
vector<bool> vst(maxn,false);
vector<int> a[maxn];

int BFS(){
    queue<int> q;
    int cur;
    q.push(1);
    while (!q.empty()){
        int u = q.front();
        cur = u;
        vst[u] = true;
        q.pop();
        for (int v:a[u]){
            if (!vst[v]) q.push(v);
        }
    }
    return cur;
}

void DFScnt(int u, int p, int l){
    maxlvl = max(maxlvl,l);
    lvl[u] = l;
    child[u] = 1;
    for (auto v:a[u]){
        if (v==p) continue;
        DFScnt(v,u,l+1);
        child[u] += child[v];
    }
}

bool checkvalid(int u, int p){
    bool valid = true;
    int c = 0;
    for (auto v:a[u]){
        if (v == p) continue;
        if (child[v] == 1) continue;
        c++;
        if (c >= 2) valid = false;
        valid = (valid && checkvalid(v,u));
        if (!valid) return valid;
    }
    return valid;
}

void buildinfo(int u, int p){
    int l = lvl[u] + 1;
    info[l].heavy = 0;
    for (auto v:a[u]){
        if (v==p) continue;
        if (child[v] == 1) info[l].light.push_back(v);
        else{
            info[l].heavy = v;
            buildinfo(v,u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    root = BFS();
    DFScnt(root,0,1);
    if (!checkvalid(root,0)){
        cout << "No";
    }
    else {
        cout << "Yes" << "\n";
        info[1].heavy = root;
        buildinfo(root,0);
        queue<int> fwd;
        stack<int> bwd;
        for (int i=1; i<=maxlvl; i++){
            if (i%2 == 1){
                for (auto u:info[i].light){
                    fwd.push(u);
                }
                if (info[i].heavy) fwd.push(info[i].heavy);
            }
            else{
                for (auto u:info[i].light){
                    bwd.push(u);
                }
                if (info[i].heavy) bwd.push(info[i].heavy);
            }
        }
        while (!fwd.empty()){
            cout << fwd.front() << " ";
            fwd.pop();
        }
        while (!bwd.empty()){
            cout << bwd.top() << " ";
            bwd.pop();
        }
    }
    return 0;
}
