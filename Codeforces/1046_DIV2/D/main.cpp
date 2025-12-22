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
const int maxdist = 1e9;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct Coord{
    int x,y;

    Coord(int _x = 0, int _y = 0): x(_x),y(_y){};
};

/*Global Variables*/
int n;
Coord a[N];

void Ask(char dir, int weight){
    cout << "? " << dir << " " << weight << endl;
    cout.flush();
}

/*Solution*/
void solve(){
    cin >> n;
    int miny=INF,minx=INF,maxx=-INF;
    for (int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].y;
        miny = min(miny,a[i].y);
        minx = min(minx,a[i].x);
        maxx = max(maxx,a[i].x);
    }
    int deltax = maxx-minx;

    int distL=LLINF, distR = LLINF;
    for (int i=1; i<=n; i++){
        distL = min(distL,abs(a[i].x - minx)+abs(a[i].y - miny));
        distR = min(distR,abs(a[i].x - maxx)+abs(a[i].y - miny));
    }

    int coord1,coord2;

    Ask('D',maxdist);
    Ask('D',maxdist);
    Ask('L',maxdist);
    Ask('L',maxdist);
    for (int tmp=1; tmp<=4; tmp++){
        cin >> coord1;
    }

    for (int i=1; i<=4; i++){
        Ask('R',maxdist);
        cin >> coord2;
    }

    int delta = maxdist*4 - deltax;
    int dist1,dist2;
    dist1 = coord1 - distL;
    dist2 = coord2 - distR;
    int lmaoX = dist1-(dist1+dist2-delta)/2;
    int lmaoY = dist1-lmaoX;
    Coord org (minx - lmaoX +maxdist*2,miny-lmaoY+maxdist*2);
    cout << "! " <<  org.x << " " << org.y << endl;
    cout.flush();
//    cout << miny << " " << minx << " " << maxx << " " << delta << endl;
//    cout << dist1 << " " << dist2 << " " << lmaoX << " " << lmaoY << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
