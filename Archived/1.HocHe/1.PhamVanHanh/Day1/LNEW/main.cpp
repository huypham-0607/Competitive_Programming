/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "harvest"

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
bool solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m;
vector<int> a,b;


bool check(int x){
    int cur = 0;
    int l=a[cur],r=a[cur];
    int i = 0;
    while (i<m){
        l = min(l,b[i]);
        r = max(r,b[i]);
        int dl = abs(a[cur]-l);
        int dr = abs(a[cur]-r);
        int val = min(dl,dr)*2+max(dl,dr);

        if (val>x){
            ++cur;
            if (cur == n) return true;
            l=a[cur],r=a[cur];
        }
        else ++i;
    }
    return false;
}

/*Solution*/
bool solve(){
    cin >> n >> m;
    if (n==0 && m==0) return false;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = -1;
    int l = 0, r = 20000000000;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    cout << ans+1 << " ";
    a.clear();
    b.clear();
    return true;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve()){};

    return 0;
}
