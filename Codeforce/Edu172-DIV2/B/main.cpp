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
int a[N];
int colcnt[N];

/*Solution*/
void solve(){
    cin >> n;
    int cnt1=0,cnt2=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        colcnt[a[i]]++;
        if (colcnt[a[i]] == 1){
            ++cnt1;
//            ++cnt;
        }
        else if (colcnt[a[i]] == 2){
            --cnt1;
            ++cnt2;
        }
    }
    int ans = ((cnt1+1)/2)*2;
//    if (cnt1%2==1){
//        ans+=cnt2/2;
//    }
//    else{
//        ans+=(cnt2+1)/2;
//    }
    ans+=cnt2;
    cout << ans << endl;
    for (int i=1; i<=n; i++){
        a[i] = 0;
        colcnt[i] = 0;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
