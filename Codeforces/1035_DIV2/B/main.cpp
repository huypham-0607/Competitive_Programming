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
int n,px,py,qx,qy;
vector<double> v;
vector<int> v2;

/*Solution*/
void solve(){
    v2.clear();
    v.clear();
    cin >> n;
    cin >> px >> py >> qx >> qy;
    double dist = sqrt((px-qx)*(px-qx)+(py-qy)*(py-qy));
    v.push_back(dist);
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        v.push_back(x);
        v2.push_back(x);
    }
    sort(all(v),greater<double>());
    sort(all(v2),greater<int>());
    if (dist == v[0]){
        int t=0;
        for (int i=0; i<n; i++) t+=v2[i];
        if (t>=dist) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else{
        double t = 0;
        for (int i=1; i<n; i++){
            t+=v2[i];
        }
        t+=dist;
        if (t>=v2[0]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
//    cout << t << " " << v[0] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
