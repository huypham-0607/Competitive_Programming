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
    Point(int a=0, int b=0): x{a},y{b} {};
    void read(){
        cin >> x >> y;
    }
    Point operator - (Point &other){
        return Point(x-other.x,y-other.y);
    }
    bool operator == (const Point &other) const{
        return (x==other.x && y == other.y);
    }
    bool operator < (const Point &other) const{
        if (x==other.x) return y<other.y;
        else return x<other.x;
    }
    friend int Cross(Point x, Point y){
        return (x.x*y.y - x.y*y.x);
    }

    friend bool Turn_Left(Point x, Point y, Point z){
        return (Cross(y-x,z-y) > 0);
    }
};

/*Global Variables*/
int n;
vector<Point> a,hull;

/*Solution*/
void solve(){
    hull.clear();
    a.clear();
    for (int i=0; i<n; i++){
        Point tmp;
        tmp.read();
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for (int i=0; i<n; i++){
        while (hull.size()>1 && Turn_Left(hull[hull.size()-2],hull.back(),a[i])){
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }
    int bruhlmao = hull.size();
    for (int i=n-2; i>=0; i--){
        while (hull.size()>bruhlmao && Turn_Left(hull[hull.size()-2],hull.back(),a[i])){
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }
//    for (auto in:a){
//        cout << "{" << in.x << "," << in.y << "}" << "  ";
//    }
//    cout << endl;
    hull.pop_back();
    cout << hull.size() << endl;
    for (int i=hull.size()-1; i>=0; i--){
        cout << hull[i].x << " " << hull[i].y << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    solve();
//    while (n){
//        solve();
//        cin >> n;
//    }

    return 0;
}
