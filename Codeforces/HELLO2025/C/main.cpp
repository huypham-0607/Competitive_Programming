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
const int LG = 30;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int l,r;

bool check(int x, int y, int l, int r){
    if (l<=x && y<=r) return true;
    return false;
}

/*Solution*/
void solve(){
    cin >> l >> r;
    int cur = 0;
    for (int lg=LG-1; lg>=0; lg--){
        int vu = 1, vd = 0;
        int delta = (1<<lg);
        if (cur+delta<=r) vu = 0;
        if (l<=cur+delta-1) vd = 1;
        if ((vu^vd)){
//            cout << delta << " ";
//            cout << cur << " ";
//            cout << ((1<<(lg+1))-1)*2 << endl;
            if (check(cur+delta-2,cur+delta,l,r)){
                cout << cur+delta << " " << cur+delta-1 << " " << cur+delta-2 << endl;
                return;
            }
            if (check(cur+delta-1,cur+delta+1,l,r)){
                cout << cur+delta+1 << " " << cur+delta << " " << cur+delta-1 << endl;
                return;
            }
        }
        if (!vu) cur+=delta;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
