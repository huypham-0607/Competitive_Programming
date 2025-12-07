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
ll k;
ll a[N];

/*Solution*/
void solve(){
    cin >> n >> k;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        for (int lg=0; lg<61; lg++){
            if (!(((ll)1<<lg) & a[i])){
                pq.push({((ll)1<<lg),i});
//                cout << ((ll)1<<lg) << " ";
                break;
            }
        }
    }
//    cout << endl;

    while (k>=pq.top().fi){
//        cout << pq.top().fi << endl;
        int i = pq.top().se;
        a[i]+=pq.top().fi;
        k-=pq.top().fi;
        pq.pop();
        for (int lg=0; lg<61; lg++){
            if (!(((ll)1<<lg) & a[i])){
                pq.push({((ll)1<<lg),i});
                break;
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int lg=0; lg<61; lg++){
            if ((((ll)1<<lg) & a[i])){
                ++ans;
            }
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
