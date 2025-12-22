/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pdi pair<long double,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 2e9+10;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
vector<pii> v;
set<pdi> st;

bool check(long double mid){
    long double rbound = -LLINF;
    st.clear();
    for (int i=0; i<n; i++){
        long double tmp = v[i].fi+(v[i].se*mid);
        st.insert(make_pair(tmp,i));
    }
    if (st.begin()->fi>v[n-1].fi) return true;
    for (int i=n-1; i>=0; i--){
        if (i==0){
            long double tmp = v[i].fi-(v[i].se*mid);
            rbound = max(rbound,tmp);
            while (!st.empty() && st.begin()->se>=i) st.erase(st.begin());
        }
        else{
            long double tmp = v[i].fi-(v[i].se*mid);
            rbound = max(rbound,tmp);
            while (!st.empty() && st.begin()->se>=i) st.erase(st.begin());
            long double lbound = st.begin()-> fi;
            if (lbound<v[i-1].fi || rbound>v[i].fi) continue;
            if (lbound > rbound) return true;
        }
    }
    if (rbound<v[0].fi) return true;
    return false;
}

/*Solution*/
void solve(){
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++){
        cin >> v[i].fi;
    }
    for (int i=0; i<n; i++){
        cin >> v[i].se;
    }
    sort(v.begin(),v.end());
    long double ans = LLINF;
    long double l=0, r = LLINF;
    for (int epoch=1; epoch<=100; epoch++){
        long double mid = (l+r)/2;
//        cout << mid << endl;
        if (check(mid)){
            ans = mid;
            r = mid;
        }
        else l = mid;
    }
    cout << fixed << setprecision(12) << ans << endl;
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
