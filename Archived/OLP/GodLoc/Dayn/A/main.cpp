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
const int N = 1e6+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct rect{
    int x,y,a;
    rect (int _x=0, int _y=0, int _a=0): x{_x}, y{_y}, a{_a} {};
    bool operator < (rect tmp) const {
        return (y < tmp.y);
    }
};

/*Global Variables*/
int n;
rect v[N];
int dp[N];
//vector<pair<double,int>> point;
set<pair<double,int>> point;


double intersect(int i, int j){
    return ((double)(dp[j]-dp[i]))/(v[j].x-v[i].x);
}
/*Solution*/

void solve(){
    int bruh = 0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> v[i].x >> v[i].y >> v[i].a;
        bruh = max(bruh,v[i].x*v[i].y-v[i].a);
        v[i].y = -v[i].y;
//        cout << v[i].x << " " << v[i].y << " " << v[i].a << endl;
    }
    sort(v+1,v+n+1);

    for (int i=1; i<=n; i++){
        v[i].y = -v[i].y;
        if (i == 1){
            dp[i] = (v[i].x*v[i].y)-v[i].a;
//            dp[i] = -dp[i];
//            cout << dp[i] << endl;
            point.insert({LLINF,i});
        }
        else{
            auto idx = *point.lower_bound(make_pair((double)v[i].y,0));
            int j = idx.se;
            dp[i] = (v[i].x*v[i].y)-v[i].a;
            dp[i] = max(dp[i], v[i].x*v[i].y - v[i].a -v[j].x*v[i].y + dp[j]);
//            cout << i << " " << j << " " << dp[i] << endl;
////            dp[i] = -dp[i];
            while (point.size()>1 && (*point.begin()).fi <= intersect(i,(*point.begin()).se)){
                point.erase(point.begin());
            }
            auto temp = (*point.begin());
//            cout << intersect(i,(*point.begin()).se) << endl;
            point.insert({intersect(i,temp.se),i});
//            for (auto in:point){
//                cout << in.fi << " ";
//            }
//            cout << endl;
        }
    }
    int meow = 0;
    for (int i=1; i<=n; i++){
//        cout << dp[i] << " ";
        meow = max(dp[i],meow);
    }
//    cout << endl;
    cout << max(bruh,meow);
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
