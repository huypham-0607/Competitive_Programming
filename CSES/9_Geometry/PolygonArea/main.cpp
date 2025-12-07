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

struct Point{
    int x,y;
    Point(int a=0, int b=0): x{a}, y{b} {};
    void read(){
        cin >> x >> y;
    }
};

int Cross(Point x, Point y){
    return (x.x*y.y - x.y*y.x);
}

/*Global Variables*/
int n;
Point a[N];

/*Solution*/
void solve(){
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++){
        a[i].read();
    }
    int prev = n;
    for (int i=1; i<=n; i++){
        ans+=Cross(a[i],a[prev]);
        prev = i;
    }
    cout << abs(ans);
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
