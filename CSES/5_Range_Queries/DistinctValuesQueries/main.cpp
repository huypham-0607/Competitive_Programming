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
int IT[N*4];
int ans[N];
int a[N];
map<int,int> mp;
vector<pair<pii,int>> v;

void update(int idx, int l, int r, int x, int val){
    if (x < l || r < x) return;
    if (l == r){
        IT[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,x,val);
    update(idx*2+1,mid+1,r,x,val);
    IT[idx] = IT[idx*2] + IT[idx*2+1];
}

int query(int idx, int l, int r, int x, int y){
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return IT[idx];
    int mid = (l+r)/2;
    return query(idx*2,l,mid,x,y) + query(idx*2+1,mid+1,r,x,y);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=q; i++){
        int l,r;
        cin >> l >> r;
        v.push_back({{r,l},i});
    }
    v.push_back({{INF,INF},INF});
    int idx = 0;
    sort(v.begin(),v.end());
//    for (int i=1; i<=100; i++){
//        cout << query(1,1,n,i,i) << " ";
//    }
    for (int i=1; i<=n; i++){
        if (mp.find(a[i]) != mp.end()){
            update(1,1,n,mp[a[i]],0);
        }
        mp[a[i]] = i;
        update(1,1,n,i,1);
        while(v[idx].fi.fi<=i){
            int l = v[idx].fi.se;
            int r = v[idx].fi.fi;
            int bruh = v[idx].se;
//            cout << bruh << " " << l << " " << r << endl;
            ++idx;
            ans[bruh] = query(1,1,n,l,r);
        }
    }
//    cout << endl;
    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
//    for (int i=1; i<=100; i++){
//        cout << query(1,1,n,i,i) << " ";
//    }
//    cout << endl;
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
