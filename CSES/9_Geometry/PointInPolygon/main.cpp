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
int n,m;

struct Point{
    int x,y;
    Point() {x = y = 0;};
    Point(int _x, int _y): x(_x), y(_y) {};
    void Print(){
        cout << "{" << x << "," << y << "}";
    }
};

Point GetVec(Point p1, Point p2){
    return Point(p2.x-p1.x,p2.y-p1.y);
}

int Dot (Point p1, Point p2){
    return p1.x*p2.x + p1.y*p2.y;
}

int Cross (Point p1, Point p2){
    return p1.x*p2.y - p2.x*p1.y;
}

int getsign(int x){
    if (x>0) return 1;
    if (x<0) return -1;
    return 0;
}

struct Line{
    int A,B,C;
    Point u,v;

    Line(Point _u, Point _v): u(_u), v(_v){
        A = v.y - u.y;
        B = u.x - v.x;
        C = Cross(u,v);
    }

    bool OnLine(Point p){
        if (A*p.x + B*p.y == C){
            if (min(u.x,v.x) > p.x || p.x > max(u.x,v.x)) return false;
            if (min(u.y,v.y) > p.y || p.y > max(u.y,v.y)) return false;
            return true;
        }
        return false;
    }
    int Check(Point p){
        Point q(-1000000001,p.y);

        Point PQ = GetVec(p,q), PU = GetVec(p,u), PV = GetVec(p,v);
        Point UV = GetVec(u,v), UP = GetVec(u,p), UQ = GetVec(u,q);
        int PQxPU = getsign(Cross(PQ,PU));
        int PQxPV = getsign(Cross(PQ,PV));
        int UVxUP = getsign(Cross(UV,UP));
        int UVxUQ = getsign(Cross(UV,UQ));
        if (PQxPU == 0 || PQxPV == 0 || UVxUP == 0 || UVxUQ == 0){
            int cnt = 0;
            if (PQxPU == 0 && PQxPV<0 && Dot(GetVec(u,p),GetVec(u,q)) <= 0) ++cnt;
            if (PQxPV == 0 && PQxPU<0 && Dot(GetVec(v,p),GetVec(v,q)) <= 0) ++cnt;
//            if (UVxUP == 0 && Dot(GetVec(p,u),GetVec(p,v)) <= 0) ++cnt;
//            if (UVxUQ == 0 && Dot(GetVec(q,u),GetVec(q,v)) <= 0) ++cnt;
            return cnt;
        }
        if (PQxPU*PQxPV<0 && UVxUP*UVxUQ<0) return 1;
        else return 0;
    }
};



vector<Point> plist;
vector<Line> llist;

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        plist.push_back(Point(x,y));
    }
    for (int i=1; i<n; i++){
        llist.push_back(Line(plist[i-1],plist[i]));
    }
    llist.push_back(Line(plist[n-1],plist[0]));

//    for (int i=0; i<n; i++){
//        llist[i].u.Print();
//        cout << " ";
//        llist[i].v.Print();
//        cout << endl;
//    }
    for (int idx=0; idx<m; idx++){
        int x,y; cin >> x >> y;
        Point p(x,y);
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (llist[i].OnLine(p)) ++cnt;
        }

        if (cnt){
            cout << "BOUNDARY" << endl;
            continue;
        }

        cnt = 0;
        for (int i=0; i<n; i++){
//            cout << llist[i].A << " " << llist[i].B << " " << llist[i].C << " ";
            cnt+=llist[i].Check(p);
//            cout << llist[i].Check(p) << endl;
//            cout << endl;
        }
//        cout << cnt << endl;
        if (cnt%2==0) cout << "OUTSIDE" << endl;
        else cout << "INSIDE" << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
