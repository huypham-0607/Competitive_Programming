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
const int N = 20;
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
int n,t;
bool dp[N+2][(1<<20)+10];
vector<int> temp[N+2];


/*Solution*/
void solve(){
    cin >> t >> n;
    for (int i=1; i<=n+1; i++){
        int mask = (1<<i)-1;
        for (int j=0; j<n; j++){
            if (mask>(1<<n)-1){
                mask^=(1<<n);
                mask^=1;
            }
            temp[i].push_back(mask);
            mask = (mask<<1);
        }
    }
//    for (int mask=0; mask<(1<<n); mask++){
//        dp[mask] = INF;
//    }
    dp[0][0] = 1;
    for (int i=1; i<=n+1; i++){
        for (int mask=0; mask<(1<<n); mask++){
            int pre;
            for (auto tmp:temp[i]){
                pre = mask^tmp;
                if (dp[i-1][pre]) dp[i][mask] = true;
            }
        }
    }
    vector<int> pos;
    string s1,s2;
    for (int i=1; i<=t; i++){
        cin >> s1 >> s2;
        int rawr = 0;
        for (int idx=0; idx<n; idx++){
            if (s1[idx] == '1') rawr+=(1<<idx);
            if (s2[idx] == '1') pos.push_back(idx);
        }
        if (rawr == 0){
//            cout << i << " ";
            cout << 0 << endl;
            pos.clear();
            continue;
        }
        for (int idx=1; idx<=n+1; idx++){
            int mask = rawr;
            for (auto v:pos){
                mask^=temp[idx][v];
            }
//            for (int i=0; i<n; i++){
//                if (mask&(1<<i)) cout << 1;
//                else cout << 0;
//            }
//            cout << endl;
            if (dp[idx][mask]){
//                cout << i << " ";
                cout << idx << endl;
                break;
            }
        }
        pos.clear();
    }
//    for (int i=1; i<=n+1; i++){
//        for (auto mask:temp[i]){
//            for (int idx=0; idx<n; idx++){
//                if (mask&(1<<idx)) cout << 1;
//                else cout << 0;
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
