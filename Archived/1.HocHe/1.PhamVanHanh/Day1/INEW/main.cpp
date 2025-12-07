/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "cauluong"

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
int n,m,l,r;
vector<int> v;

bool In(int x){
    return (l<=x && x<=r);
}

bool Out(int x){
    return (x<l || r<x);
}

bool OutL(int x){
    return (x<l);
}

bool OutR(int x){
    return (r<x);
}

/*Solution*/
void solve(){
    cin >> n >> m >> l >> r;
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    v.push_back(-LLINF);
    v.push_back(LLINF);
    sort(v.begin(),v.end());
    int res = 0;
    for (int i=1; i<(int)v.size(); i++){
        int x = v[i-1];
        int y = v[i];
        if (In(x) && In(y)){
            int dist = (y-x)/2;
            res = max(res,dist);
        }
        else if (In(x) && Out(y)){
            int dist = (y-x)/2;
            if (y-dist>r) res = max(res,r-x);
            else res = max(res,dist);
        }
        else if (Out(x) && In(y)){
            int dist = (y-x)/2;
            if (x+dist<l) res = max(res,y-l);
            else res = max(res,dist);
        }
        else if ((OutL(x) && OutL(y)) || (OutR(x) && OutR(y))){
            continue;
        }
        else if (OutL(x) && OutR(y)){
            int dist = (y-x)/2;
            if (In(x+dist) || In(y-dist)) res = max(res,dist);
            else res = max(res,min(r-x,y-l));
        }
    }
    v.clear();
    cout << res << " ";
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    TestCases(1);

    return 0;
}
