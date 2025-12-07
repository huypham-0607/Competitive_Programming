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
const int MP = 316;
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
bitset<400> bs;
vector<int> prime;

void Sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i<=MP; i++){
        if (bs[i]){
            for (int i=j=i*i; j<=MP; j+=i){
                bs[j] = 0;
            }
        }
    }
    for (int i=1; i<=MP; i++){
        if (bs[i]) prime.push_back(i);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){}

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
