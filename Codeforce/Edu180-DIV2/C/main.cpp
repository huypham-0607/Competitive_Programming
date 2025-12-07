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
const int N = 2e5;
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
int a[5010];

int BIT[N+10];

//void Init(){
//    for (int i=1; i<=n; i++){
//        BIT[i] = 0;
//    }
//}

void Update(int idx, int val){
    while (idx<=N){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int QPoint(int idx){
    int res = 0;
    while (idx>0){
        res+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return res;
}

int Query(int l){
    return QPoint(N)-QPoint(l-1);
}

/*Solution*/
void solve(){

//    memset(BIT,0,sizeof(BIT));
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n);

    int mx = a[n];

    ll ans = 0;

    for (int i=1; i<n; i++){
        for (int j=1; j<i; j++){
            Update(a[i] + a[j],1);
        }
        int idx = i+1;
        int lim = max(a[idx]+1,mx-a[idx]+1);
        int cnt = Query(lim);
        ans += cnt;
    }

    for (int i=1; i<n; i++){
        for (int j=1; j<i; j++){
            Update(a[i] + a[j],-1);
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
