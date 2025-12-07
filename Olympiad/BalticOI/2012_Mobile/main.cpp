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
int n;
int L;
vector<pii> a,v;

bool check(long double delta){
    long double x = 0;
    for (int i=0; i<(int)v.size(); i++){
        if (delta<v[i].se) continue;
        long double sus = sqrt((long double)(delta*delta - v[i].se*v[i].se));
        long double l = (long double) v[i].fi - sus;
        long double r = (long double) v[i].fi + sus;

        if (l<=x){
            x = max(x,r);
        }
    }
    if (x>=L) return true;
    else return false;
}

/*Solution*/
void solve(){
    cin >> n >> L;
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        a.push_back({x,abs(y)});
    }
    sort(all(a));
    for (int i=0; i<n; i++){
        v.push_back({a[i].fi,a[i].se});
    }

    long double l = 0, r = (int) 2e9;
    long double ans = r;
    for (int i=1; i<=50; i++){
        long double mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
