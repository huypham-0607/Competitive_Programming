/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
int a[N],d[N],val[N];
vector<pii> query;
priority_queue<pii,vector<pii>,greater<pii>> pq;

bool check(int x){
    while (!pq.empty()) pq.pop();
    int idx = 0;
    for (int i=1; i<=n; i++){
        val[i] = a[i];
    }
    for (int i=1; i<=n; i++){
        int tmp = 0;
        while (idx<query.size() && query[idx].fi <= i){
            int id = query[idx].se;
            pq.push({id + d[id],id});
            ++idx;
        }
        while (!pq.empty() && tmp<x){
            int id = pq.top().se;
            pq.pop();

            if (id + d[id] < i) continue;

            int delta = val[id];
            if (delta>(x-tmp)){
                val[id] -= (x-tmp);
                tmp = x;
                pq.push({id+d[id],id});
            }
            else{
                val[id] = 0;
                tmp+=delta;
            }
        }
//        for (int id=1; id<=n; id++){
//            cout << val[id] << " ";
//        }
//        cout << endl;
    }
    for (int i=1; i<=n; i++){
        if (val[i]!=0) return false;
    }
    return true;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> d[i];
        query.push_back({i-d[i],i});
//        query.push_back({i+d[i],1});
    }
    sort(all(query));
    int ans = INF;
    int l = 0; int r = (int)1e9;
    while (l<=r){
        int mid = (l+r)/2;
//        cout << "mid: " << mid << endl;
        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    freopen("1866G.inp","r",stdin);
//    freopen("1866G.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

