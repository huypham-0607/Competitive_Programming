/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct Node{
    int l, r, sz;

    Node(int _l=INF, int _r=INF, int _sz=0): l{_l}, r{_r}, sz{_sz} {};
};

/*Global Variables*/
int n,q;
int a[N];
Node IT[N*4];

void UptNode(int idx, int l, int r){
    IT[idx].sz = IT[l].sz + IT[r].sz;
    IT[idx].l = min(IT[l].l, IT[r].l+IT[l].sz);
    IT[idx].r = min(IT[r].r, IT[l].r+IT[r].sz);
}

void Build(int idx, int l, int r){
    if (l == r){
        IT[idx].l = a[l];
        IT[idx].r = a[l];
        IT[idx].sz = 1;
//        cout << idx << " " << l << " " << r << " " << IT[idx].l << " " << IT[idx].r << " " << IT[idx].sz << endl;
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid);
    Build(idx*2+1,mid+1,r);
    UptNode(idx,idx*2,idx*2+1);
//    cout << idx << " " << l << " " << r << " " << IT[idx].l << " " << IT[idx].r << " " << IT[idx].sz << endl;
}

void Update(int idx, int l, int r, int x, int val){
//    cout << idx << " " << l << " " << r << endl;
    if (x < l || r < x) return;
//    cout << "meow" << endl;
    if (l == r){
        IT[idx].l = val;
        IT[idx].r = val;
        IT[idx].sz = 1;
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val);
    Update(idx*2+1,mid+1,r,x,val);
    UptNode(idx,idx*2,idx*2+1);
}

int Query(int idx, int l, int r, int x){
    if (x < l || r < x) return INF;
    if (l == r) return IT[idx].l;
    int mid = (l+r)/2;
    int res = Query(idx*2,l,mid,x);
    if (res != INF){
        res = min(res,IT[idx*2+1].l+abs(x-(mid+1)));
        return res;
    }
    else{
        res = Query(idx*2+1,mid+1,r,x);
        res = min(res,IT[idx*2].r+abs(x-mid));
        return res;
    }
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    Build(1,1,n);
    while (q--){
        int tp;
        cin >> tp;
        if (tp == 1){
            int k,x;
            cin >> k >> x;
            Update(1,1,n,k,x);
        }
        else{
            int x;
            cin >> x;
            cout << Query(1,1,n,x) << endl;
//            for (int i=1; i<=n; i++){
//                cout << Query(1,1,n,i) << " ";
//            }
//            cout << endl;
        }
    }
//    for (int i=1; i<=4*n; i++){
//        cout << IT[i].l << " " << IT[i].r << " " << IT[i].sz << endl;
//    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
