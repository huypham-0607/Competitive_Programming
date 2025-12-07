/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int n,q,m;
int a[N];

/*BIT*/
vector<pii> BIT[N];
void update(int idx, int val, int ver){
    while (idx<=n){
        pii temp = BIT[idx].back();
        BIT[idx].pb({ver,temp.se+val});
        idx+=(idx&(-idx));
    }
}

int query(int idx, int ver){
    int res = 0;
    while (idx>0){
        pii in = *--upper_bound(BIT[idx].begin(),BIT[idx].end(),make_pair(ver,INF));
        res+=in.se;
        idx-=(idx&(-idx));
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> q >> m;

    for (int i=1; i<=n; i++){
        BIT[i].pb({0,0});
    }
    int ver = 0;
    while (q--){
        int type,l,r,k;
        cin >> type;
        if (type==1){
            ++ver;
            cin >> l >> k;
            if (a[l]<m && a[l]+k>=m) update(l,1,ver);
            if (a[l]>=m && a[l]+k<m) update(l,-1,ver);
            a[l]+=k;
        }
        else{
            cin >> l >> r >> k;
            int res = query(r,k);
            if (l>1) res-=query(l-1,k);
            cout << res << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
