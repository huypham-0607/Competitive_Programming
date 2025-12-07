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
int n,m;
int a[N];
vector<int> nen;
int BIT[N];

void Update(int idx, int val){
    while (idx<=m){
        BIT[idx] = (BIT[idx]+val)%INF;
        idx+=(idx&(-idx));
    }
}

int Query(int idx){
    int ans = 0;
    while (idx>0){
        ans = (ans + BIT[idx])%INF;
        idx-=(idx&(-idx));
    }
    return ans;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }

    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    m = nen.size();

    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin()+1;
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        int x = Query(a[i]-1);
        x = (x+1)%INF;
        ans = (ans+x)%INF;
        Update(a[i],x);
    }

    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

