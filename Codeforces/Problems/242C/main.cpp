#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5+10;

vector<vector<int>> lazy(4*maxn,vector<int>(21,0)), IT(4*maxn,vector<int>(21,0));
int a[maxn],n,m;

void build(int idx, int l, int r){
    if (l == r){
        for (int i=0; i<=19; i++){
            int bit = ((a[l] >> i) & 1);
            IT[idx][i] = bit;
        }
    }
    else{
        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        for (int i=0; i<20; i++){
            IT[idx][i] = IT[idx*2][i] + IT[idx*2+1][i];
        }
    }
}

void update(int idx, int l, int r, int upl, int upr, int x){
    if (r < upl || l > upr) return;

    if (upl <= l && upr >= r){
        for (int i=0; i<20; i++){
            int bit = ((x >> i)&1);
            if (bit) IT[idx][i] = (r-l+1) - IT[idx][i];
            lazy[idx][i] = (lazy[idx][i] + bit)%2;
        }
    }
    else{
        int mid = (l+r)/2;
        for (int i=0; i<20; i++){
            lazy[idx*2][i] = (lazy[idx*2][i] + lazy[idx][i])%2;
            if (lazy[idx][i]) IT[idx*2][i] = (mid-l+1) - IT[idx*2][i];
            lazy[idx*2+1][i] = (lazy[idx*2+1][i] + lazy[idx][i])%2;
            if (lazy[idx][i]) IT[idx*2+1][i] = (r-mid-1+1) - IT[idx*2+1][i];
            lazy[idx][i] = 0;
        }
        update(idx*2,l,mid,upl,upr,x);
        update(idx*2+1,mid+1,r,upl,upr,x);
        for (int i=0; i<20; i++){
            IT[idx][i] = IT[idx*2][i] + IT[idx*2+1][i];
        }
    }
}

int query(int idx, int l, int r, int upl, int upr){
    if (r < upl || l > upr) return 0;

    if (upl <= l && upr >= r){
        int t=0;
        for (int i=0; i<20; i++){
            t+=IT[idx][i] * (1 << i);
        }
        return t;
    }

    else{
        int mid = (l+r)/2;
        int t=0;
        for (int i=0; i<20; i++){
            lazy[idx*2][i] = (lazy[idx*2][i] + lazy[idx][i])%2;
            if (lazy[idx][i]) IT[idx*2][i] = (mid-l+1) - IT[idx*2][i];
            lazy[idx*2+1][i] = (lazy[idx*2+1][i] + lazy[idx][i])%2;
            if (lazy[idx][i]) IT[idx*2+1][i] = (r-mid-1+1) - IT[idx*2+1][i];
            lazy[idx][i] = 0;
        }
        t+=query(idx*2,l,mid,upl,upr);
        t+=query(idx*2+1,mid+1,r,upl,upr);
        return t;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    cin >> m;
    while (m--){
        int type;
        cin >> type;
        if (type == 1){
            int l,r;
            cin >> l >> r;
            cout << query(1,1,n,l,r) << "\n";
        }
        else{
            int l,r,x;
            cin >> l >> r >> x;
            update(1,1,n,l,r,x);
        }
    }
    return 0;
}
