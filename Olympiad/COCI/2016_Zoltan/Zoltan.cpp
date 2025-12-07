/*Author: KawakiMeido*/
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
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7;
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
vector<int> cmp;
vector<pair<pii,pii>> query;

//SEGG
pii STLDS[N*4], STLIS[N*4];
pii ansLDS[N],ansLIS[N];
ll prelg2[N];

pii Comb(pii x, pii y){
    if (x.fi!=y.fi){
        return max(x,y);
    }
    else return make_pair(x.fi,(x.se+y.se)%MD);
}

void Update(int idx, int l, int r, int x, pii val, pii ST[N*4]){
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = Comb(val,ST[idx]);
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val,ST); Update(idx*2+1,mid+1,r,x,val,ST);
    ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
}

pii Get(int idx, int l, int r, int x, int y, pii ST[N*4]){
    if (y<l || r<x) return make_pair(0,0);
    if (x<=l && r<=y) return ST[idx];
    int mid = (l+r)/2;
    return Comb(Get(idx*2,l,mid,x,y,ST),Get(idx*2+1,mid+1,r,x,y,ST));
}

/*Solution*/
void solve(){
    cin >> n;
    prelg2[0] = 1;
    for (int i=1; i<=n+10; i++){
        prelg2[i] = (prelg2[i-1]*2)%MD;
    }
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        cmp.push_back(x);
        query.push_back({{i,0},{x,i}});
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp))-cmp.begin());
    for (int i=0; i<(int)query.size(); i++){
        query[i].se.fi = lower_bound(all(cmp),query[i].se.fi) - cmp.begin()+1;
    }
    sort(all(query),greater<pair<pii,pii>>());
    int mx = 0;
    int idx = 0;
    for (int i=n; i>0; i--){
        while (idx!=(int)query.size() && query[idx].fi.fi == i){
            int x = query[idx].se.fi;
            int ver = query[idx].fi.se;
            int id = query[idx].se.se;

            pii tmpLIS = Get(1,1,cmp.size(),1,x-1,STLIS);
            pii tmpLDS = Get(1,1,cmp.size(),x+1,cmp.size(),STLDS);

            if (tmpLIS.fi == 0) ++tmpLIS.se;
            if (tmpLDS.fi == 0) ++tmpLDS.se;

            tmpLIS.fi++;
            tmpLDS.fi++;

//            cout << tmpLIS.fi << " " << tmpLIS.se << " " << tmpLDS.fi << " " << tmpLDS.se << endl;

            mx = max(tmpLIS.fi+tmpLDS.fi-1,mx);

            Update(1,1,cmp.size(),x,tmpLIS,STLIS);
            Update(1,1,cmp.size(),x,tmpLDS,STLDS);

            ansLIS[id] = tmpLIS;
            ansLDS[id] = tmpLDS;

            ++idx;
        }
    }

    long long res = 0;
    for (int i=1; i<=n; i++){
        if (ansLIS[i].fi+ansLDS[i].fi-1 == mx){
            res = (res+(((ll)ansLIS[i].se*ansLDS[i].se)%MD*prelg2[n-mx])%MD)%MD;
//            cout << res << endl;
        }
    }
    cout << mx << " " << res << endl;
}

/*Driver Code*/
signed main(){
//    freopen("Zoltan.inp","r",stdin);
//    freopen("Zoltan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
