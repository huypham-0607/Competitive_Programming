/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<pii,int>
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
int n,m;
vector<int> cmp;
vector<pii> query;
int a[N];


struct FenwickTree{
    int BIT[N];
    FenwickTree(){
        for (int i=0; i<N; i++){
            BIT[i] = 0;
        }
    }
    void clear(){
        for (int i=0; i<N; i++){
            BIT[i] = 0;
        }
    }
    void Update(int x, int val){
        while (x<N){
            BIT[x]+=val;
            x+=(x&(-x));
        }
    }
    int tmpGet(int x){
        int res = 0;
        while (x>0){
            res+=BIT[x];
            x-=(x&(-x));
        }
        return res;
    }
    int Get(int l, int r){
        if (l>r) return 0;
        return tmpGet(r)-tmpGet(l-1);
    }
};
FenwickTree up,down;

bool valid(int l1, int l2, int r1, int r2){
    if (max(l1,l2) <= min(r1,r2)) return true;
    return false;
}

bool check(int n, int m, int x){
    up.clear();
    down.clear();
    for (int i=1; i<=n; i++){
        up.Update(i,a[i]);
    }
    int ul = 0, ur = n+1, dl = n, dr = 1;
    while (ul<n && up.Get(1,ul+1)<=x)++ul;
    while (ul>1 && up.Get(ur-1,n)<=x)--ur;

    if (valid(ur-1,dr-1,ul,dl)) return true;

//    cout << "i = 0: " << ul << " " << ur << " " << dl << " " << dr << endl;

    int idx = 0;
    for (int i=1; i<=n; i++){
        while (idx!=m && query[idx].fi == i){
//            cout << query[idx].fi << " " << query[idx].se << endl;
            int pos = query[idx].se;
            ++idx;

            up.Update(pos,-1);
            down.Update(pos,1);
        }
        while (ul<n && up.Get(1,ul+1)<=x)++ul;
        while (ur>1 && up.Get(ur-1,n)<=x)--ur;
        while (down.Get(1,dl)>x)--dl;
        while (down.Get(dr,n)>x)++dr;

//        cout << "i = " << i << ": " << ul << " " << ur << " " << dl << " " << dr << endl;
//        for (int i=1; i<=cmp.size(); i++){
//            cout << up.Get(1,i) << " ";
//        }
//        cout << endl;

        if (valid(ur-1,dr-1,ul,dl)) return true;
    }
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        cmp.push_back(x);
        cmp.push_back(y);
        query.push_back({y,x});
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp))-cmp.begin());
    for (int i=0; i<n; i++){
        query[i].fi = lower_bound(all(cmp),query[i].fi)-cmp.begin()+1;
        query[i].se = lower_bound(all(cmp),query[i].se)-cmp.begin()+1;
    }
//    for (int i=0; i<cmp.size(); i++){
//        cout << i << " " << cmp[i] << endl;
//    }
//    cout << endl;
    sort(all(query));
    for (int i=0; i<n; i++){
        a[query[i].se]++;
    }
    int ans = n;
    int l = 1, r = n;
    while (l<=r){
        int mid = (l+r)/2;
//        cout << "mid: " << mid << endl;
        if (check(cmp.size(),query.size(),mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
