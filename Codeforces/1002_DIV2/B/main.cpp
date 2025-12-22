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
int n,k;
map<int,vector<int>> mp;

/*Solution*/
void solve(){
    cin >> n >> k;
    int delta = n-k;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    int sus = 1;
    for (int i=1; i<=k; i++){
        int cnt = 0;
        int l = i*2;
        int r = i*2+delta;
        if (!mp.count(i)) break;
        for (auto x:mp[i]){
            if (l<=x && x<=r) ++cnt;
        }
        if (cnt < delta+1) break;
        ++sus;
    }
    cout << sus << endl;
    mp.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
