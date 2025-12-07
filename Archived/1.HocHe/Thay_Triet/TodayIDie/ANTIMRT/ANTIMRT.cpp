/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ANTIMRT"

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
int n,m;
vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37};
vector<int> pfact[1000010];
ll adj[50];
int a[50];

bool check(int x){
    return (x>0 && x<=n);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        ll mask = 0;
        for (auto p:pfact[a[i]]){
            int pos = i+p;
            if (check(pos)){
                mask|=((ll)1<<pos);
            }
            pos = i-p;
            if (check(pos)){
                mask|=((ll)1<<pos);
            }
        }
        adj[i] = mask;
    }
    cin >> m;
    ll cur = 2, next;
    for (int step=1; step<=m; step++){
        next = 0;
        for (int i=1; i<=n; i++){
            if (cur&((ll)1<<i)){
                next|=(adj[i]);
            }
        }
        swap(cur,next);
    }
//    for (int i=1; i<=n; i++){
//        cout << dist[i] << " ";
//    }
//    cout << endl;
    if (cur&((ll)1<<n)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i=1; i<=1000000; i++){
        for (auto p:prime){
            if (i%p==0) pfact[i].push_back(p);
        }
    }

    TestCases(1);

    return 0;
}

