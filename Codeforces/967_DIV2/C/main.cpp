/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e3+10;
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
int vis[N];
stack<int> s;
vector<pii> edges;

/*Solution*/
void solve(){
    cin >> n;
    int cnt = 1;
    vis[1] = true;
    while (cnt!=n){
        int strt = 0;
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                strt=i;
                break;
            }
        }
        int ontree = 1;
        s.push(strt);
        int mid;
        while (!s.empty()){
            cout << "? " << ontree << " " << s.top() << endl;
            cout.flush();
            cin >> mid;
            if (mid == ontree){
                edges.push_back({ontree,s.top()});
                vis[s.top()] = true;
                ++cnt;
                s.pop();
            }
            else if (vis[mid]){
                ontree = mid;
            }
            else {
                s.push(mid);
            }
        }
    }
    cout << "! ";
    for (auto in:edges){
        cout << in.fi << " " << in.se << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        vis[i] = false;
    }
    edges.clear();
    while (!s.empty()){
        s.pop();
    }
}

/*Driver Code*/
signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(1);

    return 0;
}
