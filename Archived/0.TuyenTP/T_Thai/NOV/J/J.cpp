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

int n;

struct Node(){
    vector<int> val,a;
    int sum;

    Node(){
        val.resize(N,0);
        a.resize(N,0);
    }
};

Node Comb(Node x, Node y){
    Node res;

    for (int i=1; i<=n; i++){
        res.val[i] = res
    }
}

/*Global Variables*/
int n;

/*Solution*/
void solve(){

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
