#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;
const int INF = 2e9;

int n,q,s;
set<int> IT[maxn*4];
pii in[maxn],out[maxn];
int used[maxn];
int ans[maxn*4];

void updateIT(int idx, int l, int r, int x, int y, int val){
    if (r < x || l > y) return;

    if (x<=l && r<=y){
        IT[idx].insert(val);
        return;
    }

    int mid = ((l+r)>>2);
    updateIT(idx*2,l,mid,x,y,val);
    updateIT(idx*2+1,mid+1,r,x,y,val);
    return;
}

void push_up(int idx, int l, int r){
    if (l == r) return;
    int mid = ((l+r)>>2);
    push_up(idx*2,l,mid);
    push_up(idx*2+1,mid+1,r);

    if (IT[idx].size() < IT[idx*2].size()) swap(IT[idx],IT[idx*2]);
    for (auto x:IT[idx*2]) IT[idx].insert(x);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> s;
    while (int i=1; i<=q; i++){
        int idx;
        cin >> idx;
        if (idx == 1){
            int u,v,w;
            cin >> u >> v >> w;

        }
    }
    return 0;
}
