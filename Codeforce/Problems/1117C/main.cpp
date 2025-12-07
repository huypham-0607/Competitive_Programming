/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e15;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
pii s,e;
int prex[N];
int prey[N];

bool check(int mid){
    pii cur = s;
    cur.fi+=(prex[n]*(mid/n));
    cur.se+=(prey[n]*(mid/n));
    cur.fi+=(prex[mid%n]);
    cur.se+=(prey[mid%n]);
    int deltax = abs(cur.fi-e.fi);
    int deltay = abs(cur.se-e.se);
    if (mid>=deltax+deltay) return true;
    else return false;
}

/*Solution*/
void solve(){
    cin >> s.fi >> s.se;
    cin >> e.fi >> e.se;
    cin >> n;
    for (int i=1; i<=n; i++){
        char c;
        cin >> c;
        prex[i] = prex[i-1];
        prey[i] = prey[i-1];
        if (c=='U') prey[i]+=1;
        if (c=='D') prey[i]-=1;
        if (c=='R') prex[i]+=1;
        if (c=='L') prex[i]-=1;
    }
    int ans = LLINF+1;
    int l = 0, r = LLINF;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    if (ans > LLINF) cout << -1 << endl;
    else cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
