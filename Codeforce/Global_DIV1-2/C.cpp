/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    cin >> n;
//    string s; cin >> s;
//    int l = 0, r = s.size()-1;

    vector<int> a(n+10,0);
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = int(c)-48;
    }
    a[0] = a[1];
    a[n+1] = a[n];

    int pre = 1;
    int cnt = 0;
    int max0 = 0;
    int cur0 = 0;
    for (int i=0; i<=n+1; i++){
        if (a[i] == 1){
            if (pre == 1){
//                cout << i << " " << max0 << " " << cnt << endl;
                if (max0 == 1 && cnt%2){
                    cout << "NO" << endl;
                    return;
                }
                cnt = 0;
                max0 = 0;
            }
            pre = 1;
            cur0 = 0;
        }
        else{
            if (pre == 1){
                ++cnt;
            }
            pre = 0;
            cur0++;
            max0 = max(max0,cur0);
        }
    }
    cout << "YES" << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
