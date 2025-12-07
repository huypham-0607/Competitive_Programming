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
const int N = 2e5+100;
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

//SegmentTree

void ST[N*4];
vector<int> cmp;
priority_queue<piii,vector<piii>,greater<piii>> query;
vector<piiii> info;
priority_queue<pii> mxdq[N];
priority_queue<pii,vector<pii>,greater<pii>> mndq[N];

//Seggs

int ST[N*4];

pii Comb(pii l, pii r){
    pii res;
    res.fi = max(l.fi,r.fi);
    res.se = min(l.se,r.se);
    return res;
}

void Update(int idx, int l, int r, int x, pii val){
    if (x<l || r<x) return;
    if (l==r){
        ST[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
    ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
}

pii Query(int idx, int l, int r, int x, int y){
    if (y<l || r<x) return make_pair(-INF,+INF);
    if (x<=l && r<=y) return ST[idx];
    int mid = (l+r)/2;
    return Comb(Query(idx*2,l,mid,x,y),Query(idx*2+1,mid+1,r,x,y));
}

/*Solution*/
void solve(){
    cin >> n;

    cmp.push_back(0);
    int x1=0, y1=0;
    for (int i=1; i<=n; i++){
        char c;
        int d,x2,y2;
        cin >> c >> d;
        if (c == 'U'){
            x2 = x1;
            y2 = y1+d;
            cmp.push_back(x2);
            cmp.push_back(y2);
            tpe[i] = 0;
            info[i] = {{x1,y1},{x2,y2}};
            x1=x2; y1=y2;
        }
        if (c == 'D'){
            x2 = x1;
            y2 = y1-d;
            cmp.push_back(x2);
            cmp.push_back(y2);
            tpe[i] = 1;
            info[i] = {{x1,y1},{x2,y2}};
            x1=x2; y1=y2;
        }
        if (c == 'R'){
            x2 = x1+d;
            y2 = y1;
            cmp.push_back(x2);
            cmp.push_back(y2);
            tpe[i] = 2;
            info[i] = {{x1,y1},{x2,y2}};
            x1=x2; y1=y2;
        }
        if (c == 'L'){
            x2 = x1-d;
            y2 = y1;
            cmp.push_back(x2);
            cmp.push_back(y2);
            tpe[i] = 3;
            info[i] = {{x1,y1},{x2,y2}};
            x1=x2; y1=y2;
        }
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp))-cmp.end());
    for (int i=0; i<=n; i++){
        info[i].fi.fi = lower_bound(all(cmp),info[i].fi.fi)-cmp.begin()+1;
        info[i].fi.se = lower_bound(all(cmp),info[i].fi.se)-cmp.begin()+1;
        info[i].se.fi = lower_bound(all(cmp),info[i].se.fi)-cmp.begin()+1;
        info[i].se.se = lower_bound(all(cmp),info[i].se.se)-cmp.begin()+1;
    }
    int n = cmp.size();
    for (int i=0; i<=2; i+=2){

        for (int i=1; i<=)

        for (int i=1; i<=n; i++){
            while (!query.empty() && query.front().fi.fi == i){
                int x,y,id,ver;
                id = query.front().fi.se;
                ver = query.front().se;
                x = info[id].fi;
                y = info[id].se;
                pq.pop();

                if (ver<=0){
                    if (ver==0){
                        mndq[x].push({id,y});
                        query.push({{y+1,-1},id});
                    }
                    while (!mndq[x].empty() && mndq[x].top().se<i) mndq[x].pop();
                    Update(1,1,n,x,{mxdq.top(),mndq.top()});
                }
                else{
                    pii res = Query(1,1,n,x,y);
                    if (abs(i-res.fi)>1){
                        ans = min(ans,i);
                    }
                    if (abs(i-res.se)>1){
                        ans = min(ans,)
                    }
                }
            }
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
