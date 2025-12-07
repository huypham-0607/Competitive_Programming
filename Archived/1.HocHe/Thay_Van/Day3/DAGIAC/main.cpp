/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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

int nxt(int i, int x){
    return (i+1)%x;
}

struct Point{
    int x,y;

    Point() {
        x = y = 0;
    }
};

struct Vec{
    int x,y;

    Vec(Point u, Point v){
        x = v.x - u.x;
        y = v.y - u.y;
    }

    void Set(Point u, Point v){
        x = v.x - u.x;
        y = v.y - u.y;
    }

    int Dist(){
        return abs(x+y);
    }

    bool Turn(Point u, Point v){
        int dir = (x==0)? 1 : 0;
        Vec tmp(u,v);
//        cout << (x+y) << " " << tmp.x + tmp.y << endl;
        if (!dir){
            return ((x+y)*(tmp.x+tmp.y) < 0);
        }
        else{
            return ((x+y)*(tmp.x+tmp.y) > 0);
        }
    }
};

int GetDist(Point u, Point v){
    return abs(u.x-v.x + u.y-v.y);
}

/*Global Variables*/
int n;
vector<vector<Point>> model;
vector<Point> v;

bool cmp(vector<Point>& u, vector<Point>& v, int idx, bool inv){
    int i = idx;
    int n = u.size(), m = v.size();
    int j = 0;
    Vec vecu(u[i],u[nxt(i,n)]), vecv(v[j],v[nxt(j,m)]);
    int du = vecu.Dist(), dv = vecv.Dist();
    int a = du/(__gcd(du,dv));
    int b = dv/(__gcd(du,dv));
    i = nxt(i,n), j = nxt(j,m);
    while (i!=idx){
        bool ru = vecu.Turn(u[i],u[nxt(i,n)]);
        bool rv = vecv.Turn(v[j],v[nxt(j,m)]);

        bool ver = !(ru^rv);
//        cout << ver << endl;
        if (((inv)? ver : !ver)) return false;

        vecu.Set(u[i],u[nxt(i,n)]); vecv.Set(v[j],v[nxt(j,m)]);
        du = vecu.Dist(); dv = vecv.Dist();
//        cout << a << " " << b << " " << du << " " << dv << endl;
        if (a != du/(__gcd(du,dv)) || b != dv/(__gcd(du,dv))) return false;

        i = nxt(i,n), j = nxt(j,m);
    }
    return true;
}

void check(){
    for (int i=0; i<(int)model.size(); i++){
        if ((int)model[i].size() == (int)v.size()){
            int n = (int)v.size();
            for (int idx=0; idx<n; idx++){
                if (cmp(v,model[i],idx,0)) return;
//                cout << endl;
            }
        }
    }
    vector<Point> cock = v;
    reverse(cock.begin(),cock.end());
    for (int i=0; i<(int)model.size(); i++){
        if ((int)model[i].size() == (int)cock.size()){
            int n = (int)cock.size();
            for (int idx=0; idx<n; idx++){
                if (cmp(cock,model[i],idx,1)) return;
//                cout << endl;
            }
        }
    }
//    for (int i=0; i<(int)model.size(); i++){
//        if (cmp(v,model[i],0,0)) return;
//    }
    model.push_back(v);
}

/*Solution*/
void solve(){
    cin >> n;
    Point tmp;
    for (int i=1; i<=n; i++){
        int k;
        cin >> k;
        for (int i=1; i<=k; i++){
            cin >> tmp.x >> tmp.y;
            v.push_back(tmp);
        }
        check();
        v.clear();
    }
    cout << (int) model.size() << endl;
}

/*Driver Code*/
signed main(){
    freopen("DAGIAC.inp","r",stdin);
    freopen("DAGIAC.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
