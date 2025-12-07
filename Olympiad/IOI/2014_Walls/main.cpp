/*Author: KawakiMeido*/
#include "wall.h"
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
//int n,k;
//int id[N], l[N], r[N], height[N], finalHeight[N];

//SEGG

struct SegmentTree{
    vector<int> mx;
    vector<int> mn;
    vector<pii> lazyup;
    vector<pii> lazylow;

    SegmentTree(int n){
        mx.resize(4*n+10);
        mn.resize(4*n+10);
        lazyup.resize(4*n+10);
        lazylow.resize(4*n+10);
        for (int i=1; i<=4*n+5; i++){
            lazyup[i] = {INF,0};
            lazylow[i] = {0,0};
            mx[i] = 0;
            mn[i] = 0;
        }
    };

    void PropMX(int idx, pii val){
        lazyup[idx] = min(val,lazyup[idx]);
        if (val < lazylow[idx]){
            lazylow[idx] = {0,0};
        }
        mx[idx] = min(mx[idx],val.fi);
        mn[idx] = min(mn[idx],val.fi);
    }

    void PropMN(int idx, pii val){
        if (val > lazyup[idx]){
            lazyup[idx] = {INF,0};
        }
        lazylow[idx] = max(lazylow[idx],val);
        mx[idx] = max(mx[idx],val.fi);
        mn[idx] = max(mn[idx],val.fi);
    }

    void Propagate(int idx){
        pii upbound = lazyup[idx];
        pii lowbound = lazylow[idx];
        lazyup[idx] = {INF,0};
        lazylow[idx] = {0,0};

        for (int i=0; i<=1; i++){
            if (upbound.se>lowbound.se){
                PropMN(idx*2+i,lowbound);
                PropMX(idx*2+i,upbound);
            }
            else{
                PropMN(idx*2+i,lowbound);
                PropMX(idx*2+i,upbound);
            }
        }
    }

    void Update(int idx, int l, int r, int x, int y, pii val, int id){
        if (r<x || y<l) return;
        if (x<=l && r<=y){
            if (id == 1) PropMN(idx, val);
            else PropMX(idx, val);
            return;
        }
        int mid = (l+r)/2;
        Propagate(idx);

        Update(idx*2,l,mid,x,y,val,id);
        Update(idx*2+1,mid+1,r,x,y,val,id);
        mx[idx] = max(mx[idx*2],mx[idx*2+1]);
        mn[idx] = min(mn[idx*2],mx[idx*2+1]);
    }

    pii Get(int idx, int l, int r, int x){
        if (r<x || x<l) return make_pair(0,INF);
        if (l==r) return make_pair(mx[idx],mn[idx]);

        int mid = (l+r)/2;
        Propagate(idx);

        pii tmp1 = Get(idx*2,l,mid,x), tmp2 = Get(idx*2+1,mid+1,r,x);
        return make_pair(max(tmp1.fi,tmp2.fi),min(tmp1.se,tmp2.se));
    }
};


/*Solution*/
void buildWall(int n, int k, int id[], int l[], int r[], int height[], int finalHeight[]){
//signed main(){
//    cin >> n >> k;
//    for (int i=0; i<k; i++){
//        cin >> id[i] >> l[i] >> r[i] >> height[i];
//    }
    SegmentTree ST(n);
    for (int i=0; i<k; i++){
        ST.Update(1,0,n-1,l[i],r[i],make_pair(height[i],i),id[i]);
    }
    for (int i=0; i<n; i++){
        pii tmp = ST.Get(1,0,n-1,i);
        finalHeight[i] = tmp.fi;
    }
//    for (int i=0; i<n; i++){
//        cout << finalHeight[i] << " ";
//    }
//    return 0;
//}
}

