/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define ld long double
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

struct Line{
    ll m,n;

    Line(int _m=0, int _n=0): m(_m), n(_n){};

    ll operator()(ll x) const {return (ll)m*x + n;}

    friend ld intersect(Line a, Line b) {return (ld)(b.n-a.n)/(ld)(a.m-b.m);}
};

/*Global Variables*/
int n;
int a[N];
ll pre[N],pre2[N],dp[N];
deque<Line> dq;

void AddLine(Line line){
    while (dq.size() > 1 && intersect(dq[dq.size()-1],dq[dq.size()-2]) > intersect(dq[dq.size()-2],line)){
        dq.pop_back();
    }
    dq.push_back(line);
}

ll Bin_Search(ll x){
    int pos = 0;
    int l = 1, r = dq.size()-1;
    while (l<=r){
        int mid = (l+r)/2;
        if (intersect(dq[mid],dq[mid-1])<x){
            pos = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return dq[pos](x);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1] + a[i];
        pre2[i] = pre2[i-1] + (ll)a[i]*i;
    }
    AddLine(Line());
    ll ans = 0;
    for (int i=1; i<=n; i++){
       ans = max(ans,Bin_Search(-pre[i])+pre2[i]);
       AddLine(Line(i,-pre2[i]+(ll)i*pre[i]));
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
