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

    Point(int _x=0, int _y=0): x(_x), y(_y){}

    Point operator-(const Point a)const {return Point(x-a.x,y-a.y);}
    Point operator+(const Point a)const {return Point(x+a.x,y+a.y);}
    bool operator<(const Point a)const {
        if (x<a.x) return true;
        if (x==a.x && y<a.y) return true;
        return false;
    }
    bool operator==(const Point a)const{
        if (x==a.x && y==a.y) return true;
        return false;
    }
};

/*Global Variables*/
int n;
vector<Point> v;
vector<Point> Upper_Hull,Lower_Hull;

int dot(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}

int cross(Point a, Point b){
    return a.x*b.y-b.x*a.y;
}

/*Solution*/
void solve(){
//    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        v.push_back(Point(x,y));
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());

    Lower_Hull.push_back(v[0]);
    Upper_Hull.push_back(v[(int)v.size()-1]);

    for (int i=1; i<(int)v.size(); i++){
        while (Lower_Hull.size()>1 && cross(Lower_Hull.back()-Lower_Hull[Lower_Hull.size()-2],v[i]-Lower_Hull.back())<=0) Lower_Hull.pop_back();
        Lower_Hull.push_back(v[i]);
    }
    for (int i=(int)v.size()-2; i>=0; i--){
        while (Upper_Hull.size()>1 && cross(Upper_Hull.back()-Upper_Hull[Upper_Hull.size()-2],v[i]-Upper_Hull.back())<=0) Upper_Hull.pop_back();
        Upper_Hull.push_back(v[i]);
    }
    if (Lower_Hull.size() == 1){
        cout << 1 << endl;
        cout << Lower_Hull[0].x << " " << Lower_Hull[0].y << endl;
    }
    else{
        cout << Lower_Hull.size() + Upper_Hull.size() -2 << endl;
//        cout << "Lower Hull:" << endl;
        for (int i=1; i<(int)Lower_Hull.size(); i++){
            cout << Lower_Hull[i].x << " " << Lower_Hull[i].y << endl;
        }
//        cout << "Upper Hull:" << endl;
        for (int i=1; i<(int)Upper_Hull.size(); i++){
            cout << Upper_Hull[i].x << " " << Upper_Hull[i].y << endl;
        }
    }
    v.clear();
    Lower_Hull.clear();
    Upper_Hull.clear();
}

/*Driver Code*/
signed main(){
//    freopen("ConvexHull.inp","r",stdin);
//    freopen("ConvexHull.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    TestCases(0);

    while (true){
        cin >> n;
        if (n==0) break;
        solve();
    }

    return 0;
}
