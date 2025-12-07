/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 30013;
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
vector<int> cmpx,cmpy;
vector<piiii> query;

//SEGG
pii ST[N*4];
pii ans[N];

pii Comb(pii x, pii y){
    if (x.fi!=y.fi){
        return max(x,y);
    }
    else return make_pair(x.fi,(x.se+y.se)%MD);
}

void Update(int idx, int l, int r, int x, pii val){
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = Comb(val,ST[idx]);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
    ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
}

pii Get(int idx, int l, int r, int x, int y){
    if (y<l || r<x) return make_pair(0,0);
    if (x<=l && r<=y) return ST[idx];
    int mid = (l+r)/2;
    return Comb(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x1,x2,y1,y2; cin >> x1 >> x2 >> y1 >> y2;
        cmpx.push_back(x1);
        cmpx.push_back(x2);
        cmpy.push_back(y1);
        cmpy.push_back(y2);
        query.push_back({{y1,1},{x1,i}});
        query.push_back({{y2,0},{x2,i}});
    }
    sort(all(cmpx));
    sort(all(cmpy));
    for (int i=0; i<(int)query.size(); i++){
        query[i].fi.fi = lower_bound(all(cmpy),query[i].fi.fi)-cmpy.begin()+1;
        query[i].se.fi = lower_bound(all(cmpx),query[i].se.fi)-cmpx.begin()+1;
    }
    sort(all(query));
    int idx = 0;
    for (int i=1; i<=(int)cmpy.size(); i++){
        while (idx!=(int)query.size() && query[idx].fi.fi == i){
//            int y = i;
            int x = query[idx].se.fi;
            int ver = query[idx].fi.se;
            int id = query[idx].se.se;

            if (ver){
                pii res = Get(1,1,(int)cmpx.size(),1,x-1);
                if (res == make_pair(0,0)) res.se++;
                res.fi++;
                ans[id] = res;
            }
            else{
                Update(1,1,(int)cmpx.size(),x,ans[id]);
            }
            ++idx;
        }
    }
    pii res = make_pair(0,0);
    for (int i=1; i<=n; i++){
        res = Comb(res,ans[i]);
    }
    cout << res.fi << " " << res.se << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
