/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int n,Marisa,Kirisame;
int a[N];

bool check(int mid){
    int rawr = Kirisame*mid;
    int diff = Marisa - Kirisame;
    int tmp = mid;

    if (diff>0){
        for (int i=1; i<=n; i++){
            int val = a[i]-rawr;
            if (val>=0){
                tmp-=val/diff+1;
            }
        }
        if (tmp>=0) return false;
        else return true;
    }
    else if (diff==0){
        for (int i=1; i<=n; i++){
            int val = a[i]-rawr;
            if (val>=0) return true;
        }
        return false;
    }
    else{
        diff = abs(diff);
        for (int i=1; i<=n; i++){
            int val = a[i]-rawr;
            if (val<0){
                val = abs(val);
                tmp-=(val-1)/diff;
            }
            else return true;
        }
        if (tmp<=0) return false;
        else return true;
    }
}

/*Solution*/
void solve(){
    int mx = -LLINF;
    cin >> n >> Marisa >> Kirisame;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    if (mx<0){
        cout << 0 << endl;
        return;
    }
    sort(a+1,a+1+n);
    int ans = 0;
    int l=1, r=(mx/min(Marisa,Kirisame)+1);
    while (l<=r){
        int mid = (l+r)/2;
//        cout << mid << endl;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans+1 << endl;
}

/*Driver Code*/
signed main(){
    freopen("DAYSO2.inp","r",stdin);
    freopen("DAYSO2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

