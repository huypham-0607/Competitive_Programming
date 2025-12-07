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
const int N = 1e6;
const int INF = 1e9+7;
const int LG = 20;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,q;
vector<pii> v(N+10);
int ST[N+10][LG];

//int bin_pow(int a, int b){
//    int res = 1;
//    for (int lg = LG-1; lg>=0; lg--){
//        res = res*res%MD;
//        if ((1<<lg)&b) res = res*a%MD;
//    }
//    return res;
//}

/*Solution*/
void solve(){
    cin >> n >> q;

    priority_queue<pii> pq;
    for (int i=1; i<=n; i++){
        int l,r; cin >> l >> r;
        pq.push({l,r});
    }
    for (int lg=0; lg<LG; lg++){
        ST[N+1][lg] = N+1;
    }
    for (int i=N; i>0; i--){
        int rb = ST[i+1][0];
        while (!pq.empty() && pq.top().fi == i){
            rb = min(rb,pq.top().se);
            pq.pop();
        }
        ST[i][0] = rb;
        for (int lg=1; lg<LG; lg++){
            ST[i][lg] = ST[ST[i][lg-1]][lg-1];
        }
    }

    while (q--){
        int l,r; cin >> l >> r;

        int res = 0;
        for (int lg = LG-1; lg>=0; lg--){
            if (ST[l][lg]<=r){
                res += (1<<lg);
                l = ST[l][lg];
            }
        }

        cout << res << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
