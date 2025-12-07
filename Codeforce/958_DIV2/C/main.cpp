/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
vector<int> v;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=60; i>=0; i--){
        if (n&((int)1<<i)){
            v.push_back(i);
        }
    }
//    for (auto i:v){
//        cout << i << " ";
//    }
//    cout << endl;
    if ((int)v.size() == 1){
        cout << 1 << endl << n << endl;
        v.clear();
        return;
    }
    cout << (int)v.size()+1 << endl;
    int cur = 0;
    for (int i=0; i<(int)v.size(); i++){
        int res = cur;
        for (int j=1; i+j<(int)v.size(); j++){
            if (j%2){
                res+=((int)1<<v[i+j]);
            }
        }
        cout << res << " ";
        cur+=((int)1<<v[i]);
    }
    cout << n << endl;
    v.clear();
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
