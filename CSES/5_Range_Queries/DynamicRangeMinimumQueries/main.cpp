#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,q;
int a[maxn];
int BIT[maxn*4];

//SEGGSMENT TREE

void build(int idx, int l, int r){
    if (l == r){
        BIT[idx] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    BIT[idx] = min(BIT[idx*2],BIT[idx*2+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if (l > pos || r < pos){
        return;
    }
    if (l == r){
        BIT[idx] = val;
        return;
    }

    int mid = (l+r)/2;
    update(idx*2,l,mid,pos,val);
    update(idx*2+1,mid+1,r,pos,val);
    BIT[idx] = min(BIT[idx*2],BIT[idx*2+1]);
}

int query(int idx, int l, int r, int ql, int qr){
    if (l > qr || r < ql){
        return INF;
    }
    if (l >= ql && r <= qr){
        return BIT[idx];
    }
    int mid = (l+r)/2;
    return min(query(idx*2,l,mid,ql,qr),query(idx*2+1,mid+1,r,ql,qr));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    while (q--){
        int x,y,z;
        cin >> x >> y >> z;
        if (x==1){
            update(1,1,n,y,z);
        }
        else{
            cout << query(1,1,n,y,z) << endl;
        }
    }
    return 0;
}
