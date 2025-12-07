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
    Point(int _x=0, int _y=0): x{_x},y{_y} {};
};

/*Global Variables*/
int n;

Point GetVec(Point a, Point b){
    return Point(b.x-a.x,b.y-a.y);
}

int CProduct(Point a, Point b){
    return (a.x*b.y - a.y*b.x);
}

bool check(int x, int y){
    if (x<0) x=-1;
    if (x>0) x=1;
    if (y<0) y=-1;
    if (y>0) y=1;
    int bruh = x*y;
    if (bruh>0) return 0;
    else return 1;
}

bool funni(Point a, Point b, Point c, Point d){
    int x1,x2,y1,y2;
    x1 = min(a.x,b.x);
    x2 = max(c.x,d.x);
    if (x1 > x2) return false;
    x1 = max(a.x,b.x);
    x2 = min(c.x,d.x);
    if (x1 < x2) return false;
    y1 = min(a.y,b.y);
    y2 = max(c.y,d.y);
    if (y1 > y2) return false;
    y1 = max(a.y,b.y);
    y2 = min(c.y,d.y);
    if (y1 < y2) return false;
    return true;
}

/*Solution*/
void solve(){
    Point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if (!funni(a,b,c,d)){
        cout << "NO" << endl;
        return;
    }
    int meow = CProduct(GetVec(a,b),GetVec(b,c));
    int woof = CProduct(GetVec(a,b),GetVec(b,d));
    int meow2= CProduct(GetVec(c,d),GetVec(d,a));
    int woof2= CProduct(GetVec(c,d),GetVec(d,b));
    if (check(meow,woof) && check(meow2,woof2)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
