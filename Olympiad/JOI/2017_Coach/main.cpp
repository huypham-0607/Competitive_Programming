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

/*Global Variables*/
int n,m,maxdist,w,t;
int s[N],lidx[N],preC[N];
pii d[N];
int dp[N];
vector<pii> v;

struct Line{
    int m,n;

    Line(int _m=0, int _n=0): m(_m), n(_n){};

    int operator()(const int& x) const { return m*x+n;};

    friend ld intersect (Line a, Line b) {
        return (ld)(b.n-a.n)/(ld)(a.m-b.m);
    };
};

struct LineContainer{
    deque<Line> dq;

    void add(Line line){
        while ((int)dq.size()>1 && intersect(dq[dq.size()-1],dq[dq.size()-2]) > intersect(dq[dq.size()-1],line)){
            dq.pop_back();
        }
        dq.push_back(line);
    }

    int getLine(int x){
        int ans = 0, l=1, r=dq.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (intersect(dq[mid],dq[mid-1])<=x){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }

    int getVal(int x){
        int idx = getLine(x);
        return dq[idx](x);
    }
} CHT;

/*Solution*/
void solve(){
    // cout << __cplusplus << endl;
   cin >> maxdist >> n >> m >> w >> t;
   for (int i=1; i<=n; i++){
       cin >> s[i];
   }
   s[n+1] = maxdist;
   for (int i=1; i<=m; i++){
       cin >> d[i].fi >> d[i].se;
   }
   sort(d+1,d+1+m);
   sort(s+1,s+2+n);
   for (int i=1; i<=n+1; i++){
       v.push_back({s[i]%t,-i});
   }
   for (int i=1; i<=m; i++){
       v.push_back({d[i].fi,i});
       preC[i] = preC[i-1] + d[i].se;
   }
//   for (int i=1; i<=m; i++){
//        cout << preC[i] << endl;
//   }

   sort(all(v));
   int last = 0;
   for (const auto& [x,idx]:v){
       if (idx>0){
           last = idx;
       }
       else{
           if (!lidx[last]) lidx[last] = n+1;
           lidx[last] = min(lidx[last],-idx);
       }
//       cout << last << " " << idx << " " << lidx[last] << endl;
   }
//   for (int i=0; i<t; i++){
//        cout << lidx[i] << " ";
//   }
//   cout << endl;

   for (int i=1; i<=m; i++){
//        cout << i << ": ";
       CHT.add(Line(-(i-1),dp[i-1]-preC[i-1]));
       dp[i] = dp[i-1] + ((maxdist-d[i].fi)/t+1)*w;
//       cout << dp[i] << " ";
       if (lidx[i]){
           int cst = ((s[lidx[i]]-1)/t)*w;
           dp[i] = min(dp[i],i*cst+CHT.getVal(cst)+preC[i]);
//            cout << i*cst+CHT.getVal(cst)+preC[i] << " " << cst << " " << CHT.getVal(cst) << " " << CHT.getLine(cst) << " ";
       }
//        cout << endl;
   }
   cout << dp[m] + (maxdist/t+1)*w;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
