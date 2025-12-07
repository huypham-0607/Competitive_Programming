/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<pii,int>
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
int n,k;
int a[N],b[N],c[N],d[N];
vector<piii> v;
priority_queue<int> pq;

/*Solution*/
void solve(){
    cin >> n >> k;
    int ans = 0;
    int t = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
        c[i] = b[i] - a[i];
        d[i] = c[i] + a[i];
//        cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
        if (c[i]>=0){
            t+=c[i];
            v.push_back({{d[i],-a[i]},i});
        }
    }
    if (k == 0){
        v.clear();
        while (!pq.empty()){
            pq.pop();
        }
        for (int i=1; i<=n; i++){
            a[i]=0;
            b[i]=0;
            c[i]=0;
            d[i]=0;
        }
        cout << max(ans,t) << endl;
        return;
    }
//    cout << t << endl;
    sort(v.begin(),v.end(),greater<piii>());
    for (int i=0; i<(int)v.size(); i++){
        int dist = v[i].fi.fi;
//        cout << v[i].fi.fi << " " <<v[i].fi.se << endl;
        if (i<k){
            t-=dist;
            pq.push(-v[i].fi.se);
            if (i == k-1) ans = max(ans,t);
        }
        else{
//            cout << i << " " << pq.top() << " ";
            t+=pq.top();
            pq.pop();
            t-=dist;
//            cout << t << endl;
            pq.push(-v[i].fi.se);
            ans = max(ans,t);
        }
    }
    cout << ans << endl;
    v.clear();
    while (!pq.empty()){
        pq.pop();
    }
    for (int i=1; i<=n; i++){
        a[i]=0;
        b[i]=0;
        c[i]=0;
        d[i]=0;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
