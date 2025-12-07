/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

#define X real()
#define Y imag()

template <typename T>
class Point {
public:
    static constexpr double EPS = 1e-6;

    std::complex<T> p;

    // Contructors
    Point(T x = 0, T y = 0) : p(x, y) {}
    explicit Point(const std::complex<T>& val) : p(val) {}

    // Accessors
//    T real() { return p.real(); }
    T real() const { return p.real(); }
//    T imag() { return p.imag(); }
    T imag() const { return p.imag(); }

    // Comparisons
    bool operator==(const Point& other) const {
        if constexpr (std::is_floating_point_v<T>) {
            return (std::abs(p.real() - other.p.real()) < EPS) &&
                   (std::abs(p.imag() - other.p.imag()) < EPS);
        } else {
            return p == other.p;
        }
    }
    bool operator!=(const Point& other) const { return !(*this == other); }

    // Arithmetics
    Point& operator+=(const Point& other) { p += other.p; return *this; }
    Point& operator-=(const Point& other) { p -= other.p; return *this; }
    friend Point operator+(Point a, const Point& b) { a += b; return a; }
    friend Point operator-(Point a, const Point& b) { a -= b; return a; }

    // Helper Functions
    friend T dot(const Point& a, const Point& b)   { return (std::conj(a.p) * b.p).real(); }
    friend T cross(const Point& a, const Point& b) { return (std::conj(a.p) * b.p).imag(); }
    friend T sqdist(const Point& a, const Point& b){ return std::norm(a.p - b.p); }
    friend T dist(const Point& a, const Point& b)  { return std::abs(a.p - b.p); }
    friend long double angle(const Point& a, const Point& b) { return std::arg(b.p - a.p); }
    friend long double slope(const Point& a, const Point& b) { return std::tan(std::arg(a.p - b.p)); }
};

int n;
vector<Point<int>> v;

void solve(){
    cin >> n;
    v.resize(n+1);
    for (int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        v[i] = Point(x,y);
//        cout << v[i].X << " " << v[i].Y << endl;
    }
    v[n] = v[0];
//    cout << v[n].X << " " << v[n].Y << endl;

    int s = 0;

    for (int i=0; i<n; i++){
        s += cross(v[i],v[i+1]);
//        cout << s << endl;
    }

    s = abs(s);

    int cnt = 0;
    for (int i=0; i<n; i++){
        Point tmp = v[i] - v[i+1];
        if (tmp.X < 0) tmp = Point<int>(-tmp.X, tmp.Y);
        if (tmp.Y < 0) tmp = Point<int>(tmp.X, -tmp.Y);
        if (tmp.X == 0) cnt += tmp.Y;
        else if (tmp.Y == 0) cnt += tmp.X;
        else cnt += __gcd<ll>(tmp.X, tmp.Y);
//        cout << tmp.X << " " << tmp.Y << " " << cnt << endl;
    }

    int ans = s-cnt+2;
//    cout << s << " " << cnt << endl;
    cout << ans/2 << " " << cnt << endl;
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
