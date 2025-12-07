#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SUMPROD"

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,q,k;
int a[N];

/*Inititalization*/
void Init(){
    cin >> n >> q >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
}

/*Subtask1*/
bool CheckSub1(){
    return false;
}

void SolveSub1(){

}

/*Subtask2*/
bool CheckSub2(){
    return (true);
}

//struct SegmentTree{
//    int n;
//    vector<int> ST;
//    vector<int> lazy;
//
//    void Propagate(int idx, int l, int r){
//        int mid = (l+r)/2;
//        int sz1 = mid-l+1;
//        int sz2 = r-(mid+1)+1;
//        int delta = lazy[idx];
//        ST[idx*2] = (ST[idx*2]+(delta*sz1)%MD)%MD;
//        lazy[idx*2] = (lazy[idx*2]+delta)%MD;
//        ST[idx*2+1] = (ST[idx*2+1]+(delta*sz2)%MD)%MD;
//        lazy[idx*2+1] = (lazy[idx*2+1]+delta)%MD;
//        lazy[idx] = 0;
//    }
//
//    void Build(int idx, int l, int r){
//        if (l==r){
//            ST[idx] = a[l];
//            return;
//        }
//        int mid = (l+r)/2;
//        Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
//        ST[idx] = (ST[idx*2]+ST[idx*2+1])%MD;
//    }
//
//    SegmentTree(int _n): n(_n){
//        ST.resize(4*n+10);
//        Build(1,1,n);
//    }
//    void Update(int idx, int l, int r, int x, int y, int val){
//        if (y<l || r<x) return;
//        if (x<=l && r<=y){
//            int sz = r-l+1;
//            ST[idx] = (ST[idx]+(val*sz)%MD)%MD;
//            lazy[idx] = (lazy[idx]+(val*sz)%MD)%MD;
//            return;
//        }
//
//        Propagate(idx,l,r);
//
//        int mid = (l+r)/2;
//        Update(idx*2,l,mid,x,y,val); Update(idx*2+1,mid+1,r,x,y,val);
//        ST[idx] = (ST[idx*2]+ST[idx*2+1])%MD;
//    }
//
//    int Get(int idx, int l, int r, int x, int y){
//        if (y<l || r<x) return 0;
//        if (x<=l && r<=y){
//            return ST[idx];
//        }
//
//        Propagate(idx,l,r);
//
//        int mid = (l+r)/2;
//        return (Get(idx*2,l,mid,x,y)+Get(idx*2+1,mid+1,r,x,y))%MD;
//    }
//};

void SolveSub2(){
//    SegmentTree ST();
    while (q--){
        int id, x, y, val;
        cin >> id >> x >> y;
        if (id == 1){
            cin >> val;
            for (int i=x; i<=y; i++){
                a[i] = (a[i]+val)%MD;
            }
//            ST.Update(1,1,n,x,y,val);
        }
        else{
            if (x+k>y){
                cout << 0 << endl;
                continue;
            }
            int ans = 0;
            int val = 0;
            for (int i=x+k; i<=y; i++){
                val = (val+a[i])%MD;
            }
            for (int i=x; i+k<=y; i++){
                ans = (ans+(a[i]*val)%MD)%MD;
                val = (val-a[i+k]+MD)%MD;
            }
//            int val = Get(1,1,n,l+k,)
            cout << ans << endl;
        }
    }
}

/*Subtask3*/
bool CheckSub3(){
    return false;
}

void SolveSub3(){

}

/*Subtask4*/
bool CheckSub4(){
    return false;
}

void SolveSub4(){

}

/*Driver Code*/
signed main(){
//    freopen(NAME".inp","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();

    if (CheckSub1()) return SolveSub1(),0;
    if (CheckSub2()) return SolveSub2(),0;
    if (CheckSub3()) return SolveSub3(),0;
    if (CheckSub4()) return SolveSub4(),0;

    return 0;
}
