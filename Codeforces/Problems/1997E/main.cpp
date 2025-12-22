/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
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
int n,q;
int a[N];
priority_queue<piii,vector<piii>,greater<piii>> query;
bool ans[N];

//BIT
int BIT[N];

void UpdateBIT(int pos){
    while (pos<=n){
        ++BIT[pos];
        pos+=(pos&(-pos));
    }
}

int GetBIT(int pos){
    int res = 0;
    while (pos>0){
        res+=BIT[pos];
        pos-=(pos&(-pos));
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=q; i++){
        int idx,x;
        cin >> idx >> x;
        query.push({idx,{x,i}});
    }
//    cout << endl;
    for (int i=1; i<=n; i++){
        int res = 0;
        int l = 1;
        int r = n;
        while (l<=r){
            int mid = (l+r)/2;
            int cnt = GetBIT(mid);
            if (cnt/mid+1>a[i]){
                res = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
//        cout << i << " " << res << endl;
//        for (int j=1; j<=n; j++){
//            cout << GetBIT(j) << " ";
//        }
//        cout << endl;
        while (!query.empty() && query.top().fi<=i){
            if (query.top().se.fi>res) ans[query.top().se.se] = true;
            else ans[query.top().se.se] = false;
            query.pop();
        }
        UpdateBIT(res+1);
    }
//        for (int j=1; j<=n; j++){
//            cout << GetBIT(j) << " ";
//        }
//        cout << endl;
    for (int i=1; i<=q; i++){
        if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
