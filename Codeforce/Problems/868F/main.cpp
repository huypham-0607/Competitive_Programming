/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k,m;

int a[N];
int dppre[N],dpcur[N];

struct state{
    int lvl,l,r,optl,optr;

    state(int lvl, int l, int r, int optl, int optr){
        this->lvl = lvl;
        this->l = l;
        this->r = r;
        this->optl = optl;
        this->optr = optr;
    }
};

queue<pair<int,pair<pii,pii>>> dq;
vector<int> cntr;
vector<int> cntl;

void DnC(int k){
    dq.push({1,{{1,n},{1,n}}});
    int curlvl = 0;

    int t = 0;
    int lidx = 1;
    int ridx = 0;


    while (!dq.empty()){
        auto in = dq.front();

        dq.pop();

        int lvl = in.fi;
        int l = in.se.fi.fi;
        int r = in.se.fi.se;
        int optl = in.se.se.fi;
        int optr = in.se.se.se;
        assert(lvl<=20);
        if (curlvl!=lvl){
            for (int i=0; i<=m; i++){
                cntl[i] = cntr[i] = 0;
            }
            lidx = 1;
            ridx = 0;
            t = 0;
            curlvl = lvl;
        }

        pii best = {LLINF,0};

        int mid = (l+r)/2;

//        cout << mid << " " << l << " " << r << " " << optl << " " << optr << endl;

        while (ridx < mid){
            ridx++;
            t += cntr[a[ridx]]*2 - cntl[a[ridx]]*2;
            cntr[a[ridx]]++;
        }
        if (lidx >= optl){
            best = min(best,make_pair(dppre[lidx-1]+t/2,lidx));
        }
        while (lidx < min(optr,mid)){
            t += - cntr[a[lidx]]*2 + cntl[a[lidx]]*2 +2;
            cntl[a[lidx]]++;
            lidx++;
//            cout << lidx << " " << dppre[lidx-1] + t/2 << " " << lvl << endl;
            if (lidx >= optl){
                best = min(best,make_pair(dppre[lidx-1]+t/2,lidx));
            }
        }
//        cout << "best: " << best.fi << " " << best.se << endl;
        dpcur[mid] = best.fi;
        if (l<=mid-1) dq.push({lvl+1,{{l,mid-1},{optl,best.se}}});
        if (mid+1<=r) dq.push({lvl+1,{{mid+1,r},{best.se,optr}}});
    }
}

/*Solution*/
void solve(){
    cin >> n >> k;
    vector<int> nen;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());
    m = nen.size();
    cntl.resize(m+1);
    cntr.resize(m+1);
    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i])-nen.begin();
    }
    for (int i=1; i<=n; i++){
        dppre[i] = (int)1e12;
    }
    dppre[0] = 0;
    for (int idx=1; idx<=k; idx++){
        for (int i=0; i<=n; i++){
//            cout << dppre[i] << " ";
            dpcur[i] = (int)1e12;
        }
//        cout << endl;
        DnC(idx);
        swap(dpcur,dppre);
    }


//    for (int i=0; i<=n; i++){
//        cout << dppre[i] << " ";
//    }
//    cout << endl;
    cout << dppre[n] << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
