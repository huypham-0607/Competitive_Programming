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
vector<int> nen;
vector<int> BIT;
deque<int> dq[N];

void InitBIT(int n){
    BIT.clear();
    BIT.resize(n+10,0);
}

void UpdateBIT(int idx, int val){
    while (idx<=n){
        BIT[idx] = max(BIT[idx],val);
        idx += (idx&(-idx));
    }
}

int GetBIT(int idx){
    int res = 0;
    while (idx>0){
        res = max(res,BIT[idx]);
        idx -= (idx&(-idx));
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n;
    InitBIT(n);
    nen.clear();
    for (int i=1; i<=n; i++){
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.resize(unique(all(nen)) - nen.begin());
    for (int i=1; i<=n; i++){
        a[i] = lower_bound(all(nen),a[i]) - nen.begin();
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
//        cout << i << ": ";
        int pos = a[i];
        int val = nen[a[i]];
        if ((int)dq[pos].size()==val) dq[pos].pop_front();
        dq[pos].push_back(i);

        if ((int)dq[pos].size() == val){
//            cout << dq[pos].front() << " ";
            int res = GetBIT(dq[pos].front()-1);
//            cout << res << " ";
//            cout << ans << " ";
            ans = max(ans,res+val);
            UpdateBIT(i,res+val);
        }
//        cout << endl;
    }
    cout << ans << endl;
    for (int i=0; i<nen.size(); i++){
        dq[i].clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
