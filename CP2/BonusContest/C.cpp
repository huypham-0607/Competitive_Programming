/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;

struct Point {
    int x,y;
    Point (int _x=0, int _y=0) : x(_x), y(_y) {}
};

int cross(const Point& a, const Point& b) {
    int val = a.x*b.y - b.x*a.y;
    if (val > 0) return 1;
    if (val < 0) return -1;
    else return 0;
}

struct Rec {
    vector<Point> v;
    Rec(Point a, Point b, Point c, Point d) {
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
    }
};

int checkRec(Point& vec, Point& e, Rec& r) {
    int prev = 0;
    for (int id = 0; id < 4; id++){
        Point vec2 = Point(r.v[id].x - e.x, r.v[id].y - e.y);
        
        int cr = cross(vec,vec2);

        if (cr == 0) continue;
        if (prev != 0) {
            if ((prev > 0 && cr < 0) || (prev < 0 && cr > 0)) {
                return 0;
            }
        }
        prev = cr;
    }
    if (prev > 0) return 1;
    else return -1;
}

vector<Rec> v;

int recurse(vector<Rec> v) {
    if (v.size() == 1) {
        return 1;
    }
    vector<Point> pts;
    for (int i=0; i<v.size(); i++){
        pts.push_back(v[i].v[0]);
        pts.push_back(v[i].v[1]);
        pts.push_back(v[i].v[2]);
        pts.push_back(v[i].v[3]);
    }
    for (int i=0; i<pts.size(); i++){
        for (int j=i+1; j<pts.size(); j++){
            Point vec = Point(pts[j].x - pts[i].x, pts[j].y - pts[i].y);
            int flag2 = 0;
            int pos = 0;
            int neg = 0;
            for (int idx = 0; idx<v.size(); idx++){
                int val = checkRec(vec,pts[j],v[idx]);
                if (val == 0) {
                    flag2 = 1;
                    break;
                }
                else if (val > 0) ++pos;
                else ++neg;
            }
            if (!flag2 && (pos && neg)) {
                vector<Rec> v1;
                vector<Rec> v2;
                for (int idx = 0; idx<v.size(); idx++){
                    int val = checkRec(vec,pts[j],v[idx]);
                    if (val == 1) {
                        v1.push_back(v[idx]);
                    }
                    else v2.push_back(v[idx]);
                }
                if (!recurse(v1)) return 0;
                if (!recurse(v2)) return 0;
                return 1;
            }
        }
    }
    return 0;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        v.push_back(Rec(Point(a,b), Point(a,d), Point(c,b), Point(c,d)));
    }

    int res = recurse(v);
    if (res) {
        cout << n-1 << endl;
    }
    else {
        cout << "impossible" << endl;
    }
    
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

