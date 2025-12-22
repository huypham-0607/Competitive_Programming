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
vector<int> a,b;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    for (int i=1; i<=n; i++){
        a.push_back(b[i-1]);
    }
    sort(b.begin(),b.end());
    for (auto i:a){
        cout << i << " ";
    }
    cout << endl;
    for (auto i:b){
        cout << i << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++){
        bool v = true;
        for (int j=0; j<n; j++){
            if (a[i+j]!=b[j]){
                v = false;
                break;
            }
        }
        cout << v << " ";
        if (v){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
