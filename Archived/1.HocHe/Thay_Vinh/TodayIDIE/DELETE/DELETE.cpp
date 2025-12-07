/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "DELETE"

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
int n;

int a[N],b[N],c[N];

//ST;
int ST[N*4];

void Init(int idx, int l, int r){
    if (l==r){
        ST[idx] = INF;
        return;
    }
    int mid = (l+r)/2;
    Init(idx*2,l,mid); Init(idx*2+1,mid+1,r);
    ST[idx] = min(ST[idx*2],ST[idx*2+1]);
}

void Update(int idx, int l, int r, int pos, int val){
    if (r<pos || pos<l) return;
    if (l==r){
        ST[idx] = min(val,ST[idx]);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,pos,val); Update(idx*2+1,mid+1,r,pos,val);
    ST[idx] = min(ST[idx*2],ST[idx*2+1]);
}

int Get(int idx, int l, int r, int val){
    if (l==r) return l;
    int mid = (l+r)/2;
    if (ST[idx*2+1]>=val) return Get(idx*2,l,mid,val);
    else return Get(idx*2+1,mid+1,r,val);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = INF;
        c[i] = 0;
    }
    c[0] = INF;
    a[n+1] = INF;
    int res = 0,cur = 0;
    for (int i=n; i>0; i--){
        if (a[i]<a[i+1]) ++cur;
        else cur = 1;
        c[i] = cur;
    }
    Init(1,1,n);
    cur = 0;
    for (int i=1; i<=n; i++){
        if (a[i]>a[i-1]) ++cur;
        else cur = 1;
        b[cur] = min(b[cur],a[i]);
        Update(1,1,n,cur,b[cur]);
//        for (int i=1; i<=10; i++){
//            cout << Get(1,1,n,i) << " ";
//        }
//        cout << endl;
        int pos = Get(1,1,n,a[i+1]);
        res = max(res,pos+c[i+1]);
    }
    cout << res << endl;
//    for (int i=1; i<=n; i++){
//        cout << c[i] << endl;
//    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
