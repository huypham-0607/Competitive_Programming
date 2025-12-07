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
const long long LLINF = 1e12+3;

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

/*Solution*/
void solve(){
    cin >> n >> m;
    cin >> l >> r;
    int lborder = -LLINF, rborder = LLINF;
    int x;
    for (int i=1; i<=m; i++){
        cin >> x;
        if (l<=x && x<=r){
            v.push_back(x);
        }
        else if (x<l){
            lborder = max(lborder,x);
        }
        else if (r<x){
            rborder = min(rborder,x);
        }
    }
    int res = 0;
    sort(v.begin(),v.end());
    if ((int)v.size() == 0){
        if (lborder == -LLINF){
            res = (rborder-l);
        }
        else if (rborder == LLINF){
            res = (r-lborder);
        }
        else{
            int dist = (rborder-lborder)/2;
            if (l<=lborder+dist && lborder+dist<=r) res = dist;
            else if (l<=rborder-dist && rborder-dist<=r) res = dist;
            else if (lborder+dist<l) res = (rborder-l);
            else if (rborder-dist>r) res = (r-lborder);
        }
    }
    for (int i=0; i<=(int)v.size(); i++){
        if (i==0){
            int dist = (v[i]-lborder)/2;
            if (lborder+dist<l) res = max(res,v[i]-l);
            else res = max(res,dist);
        }
        else if (i==(int)v.size()){
            int dist = (rborder-v[i-1])/2;
            if (rborder-dist>r) res = max(res,r-v[i-1]);
            else res = max(res,dist);
        }
        else{
            int dist = (v[i]-v[i-1])/2;
            res = max(res,dist);
        }
    }
//    cout << v[(int)v.size()] << endl;
    cout << res << " ";
    v.clear();
}

/*Driver Code*/
signed main(){
//    freopen(NAME".INP","r",stdin);
//    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    TestCases(1);

    return 0;
}
