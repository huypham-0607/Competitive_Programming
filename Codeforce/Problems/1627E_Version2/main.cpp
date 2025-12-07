/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
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
priority_queue<int> pq;

/*Solution*/
void solve(){
//    cin >> n >> m >> k;
    fire.push_back(0);
    for (int i=1; i<=n; i++){
        cin >> fire[i];
    }
    for (int i=1; i<=k; i++){
        pii u,v;
        int w;
        cin >> u.fi >> u.se >> v.fi >> v.se >> w;
        cin >>
    }
    for (int i=1; i<=n; i++){

    }
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

