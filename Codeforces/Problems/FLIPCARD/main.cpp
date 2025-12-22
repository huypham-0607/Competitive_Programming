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

/*Global Variables*/
int n,q;
int a[N];

//Segment Tree
struct Node{
    int lval,rval,lcnt,rcnt;
    int best0, best1;
    int flip;
    Node(int _lval=0,int _rval=0,int _lcnt=0,int _rcnt=0,int _best0=0,int _best1=0, int _flip=0):
    lval{_lval}, rval{_rval}, lcnt{_lcnt}, rcnt{_rcnt}, best0{_best0}, best1{_best1}, flip{_flip} {};
};

Node IT[N*4];

void Flip(int idx){
    if (IT[idx].flip%2){
        IT[idx].lval = (IT[idx].lval+1)%2;
        IT[idx].rval = (IT[idx].rval+1)%2;
        swap(IT[idx].best0,IT[idx].best1);
        ++IT[idx*2].flip;
        ++IT[idx*2+1].flip;
    }
    IT[idx].flip = 0;
}

void Combine(int idx, int i, int j, int li, int ri, int lj, int rj){
    int leni = ri-li+1, lenj = rj-lj+1;
    IT[idx].lval = IT[i].lval;
    IT[idx].rval = IT[j].rval;
    if (IT[i].lcnt == leni && IT[i].lval == IT[j].lval){
        IT[idx].lcnt = IT[i].lcnt+IT[j].lcnt;
    }
    else IT[idx].lcnt = IT[i].lcnt;
    if (IT[j].rcnt == lenj && IT[j].rval == IT[i].rval){
        IT[idx].rcnt = IT[j].rcnt+IT[i].rcnt;
    }
    else IT[idx].rcnt = IT[j].rcnt;
    IT[idx].best0 = max(IT[i].best0,IT[j].best0);
    IT[idx].best1 = max(IT[i].best1,IT[j].best1);
    if (!IT[i].rval && !IT[j].lval){
        IT[idx].best0 = max(IT[idx].best0,IT[i].rcnt+IT[j].lcnt);
    }
    else if (IT[i].rval && IT[j].lval){
        IT[idx].best1 = max(IT[idx].best1,IT[i].rcnt+IT[j].lcnt);
    }
}

void Build(int idx, int l, int r){
    if (l==r){
        IT[idx].lval = a[l];
        IT[idx].rval = a[l];
        IT[idx].lcnt = 1;
        IT[idx].rcnt = 1;
        if (a[l] == 0) IT[idx].best0 = 1;
        else IT[idx].best1 = 1;
        return;
    }
    int mid = (l+r)/2;
    Build(idx*2,l,mid);
    Build(idx*2+1,mid+1,r);
    Combine(idx,idx*2,idx*2+1,l,mid,mid+1,r);
}

void Update(int idx, int l, int r, int x, int y){
    Flip(idx);
    if (r < x || y < l) return;
    if (x<=l && r<=y){
        ++IT[idx].flip;
        Flip(idx);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,y);
    Update(idx*2+1,mid+1,r,x,y);
    Combine(idx,idx*2,idx*2+1,l,mid,mid+1,r);
}

/*Solution*/
void solve(){

    cin >> n >> q;
    for (int i=1; i<=n; i++){
        char c;
        cin >> c;
        if (c == 'P') a[i] = 1;
        else a[i] = 0;
    }
    Build(1,1,n);
    while (q--){
        int x,y;
        cin >> x >> y;
        Update(1,1,n,x,y);
        cout << IT[1].best0 << " " << IT[1].best1 << endl;
    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    TestCases(0);
    return 0;
}
