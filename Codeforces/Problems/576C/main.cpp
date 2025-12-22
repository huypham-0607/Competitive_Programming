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
const int K = 1000;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;

struct pts{
    int block,x,y,id;
    pts(int _x, int _y, int _id): x(_x), y(_y), id(_id){
        block = x/K;
    }
    bool operator<(const pts& b) const{
        if (block == b.block){
            if (block%2) return (y<b.y);
            else return (y>b.y);
        }
        else return (block < b.block);
    }
};

vector<pts> v;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        v.push_back(pts(x,y,i));
    }
    sort(all(v));
//    int res = 0;
//    for (int i=0; i<n-1; i++){
//        res+= abs(v[i].x-v[i+1].x) + abs(v[i].y-v[i+1].y);
//    }
    for (auto x:v){
        cout << x.id << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
