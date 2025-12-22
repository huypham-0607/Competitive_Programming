/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
int n;
int a[N];
vector<piii> v;
priority_queue<piii,vector<piii>,greater<piii>> pq;
vector<int> ans;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pq.push({{a[i],i},1});
    }
    int curpos = 0;
    while (!pq.empty()){
        int val = pq.top().fi.fi;
        int ver = pq.top().se;
        int idx = pq.top().fi.se;
        pq.pop();

        if (!ver){
            ans.push_back(val);
            curpos = idx;
        }
        else{
            if (idx<curpos){
                pq.push({{val+1,n+1},0});
            }
            else{
                curpos = idx;
                ans.push_back(val);
            }
        }
    }
    for (auto x:ans) cout << x << " ";
    cout << endl;
    ans.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
