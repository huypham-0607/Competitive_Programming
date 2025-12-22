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

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    map<int,int> mp;
    cin >> n;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    int a=0, b=0;
    vector<int> v;
    for (auto it=mp.begin(); it!=mp.end(); it++){
        int x = it->fi;
        int cnt = it->se;
        if (x%2){
            v.push_back(cnt);
        }
    }
    sort(all(v),greater<int>());
    for (int i=0; i<v.size(); i++){
        if (i%2==0) a+=v[i];
        else b+=v[i];
    }
    for (auto it=mp.begin(); it!=mp.end(); it++){
        int x = it->fi;
        int cnt = it->se;
        a += (x/2)*cnt;
        b += (x/2)*cnt;
    }
    cout << a << " " << b << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
