/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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

vector<pii> v;
vector<pii> a;
int coef[N],cst[N];
vector<int> sus[N];
int dp[N];

long double intersect(int i, int j){ return (long double)(cst[j] - cst[i])/(coef[i]-coef[j]);};

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());

    for (int i=0; i<n; i++){
        while (!a.empty() && v[i].se>=a.back().se) a.pop_back();
        a.push_back(v[i]);
    }
    deque<int> dq;
    coef[0] = a[0].se;
    dq.push_back(0);
    for (int i=0; i<(int)a.size(); i++){
        while (dq.size()>1 && intersect(dq.front(),dq[1])<a[i].fi) dq.pop_front();

        int j = dq.front();
        dp[i] = coef[j]*a[i].fi+cst[j];
        if (i+1!=(int)a.size()){
            coef[i+1] = a[i+1].se;
            cst[i+1] = dp[i];

            while(dq.size()>1 && intersect(i+1,dq.back()) < intersect(i+1,dq[(int)dq.size()-2])) dq.pop_back();
            dq.push_back(i+1);
        }
    }
    cout << dp[(int)a.size()-1] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
