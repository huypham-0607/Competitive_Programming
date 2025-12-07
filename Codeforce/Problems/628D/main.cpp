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
int m,d;
int dp[2010][2010][2][2];
string a,b;
int sz;

int Call_DP(int pos, int rem, bool over, bool under){
    if (pos == sz){
        if (!rem) return 1;
        else return 0;
    }

    if (dp[pos][rem][over][under]!=-1) return dp[pos][rem][over][under];

    int digl = a[pos]-'0';
    int digr = b[pos]-'0';
    int n_rem,res=0;
    bool n_over,n_under;

    for (int i=0; i<10; i++){
        if (!over && i<digl) continue;
        if (!under && i>digr) break;

        if (pos%2){
            if (i!=d) continue;
        }
        else if (i==d) continue;

        n_rem = (rem*10+i)%m;
        n_over = over||(i>digl);
        n_under = under||(i<digr);

        res = (res+Call_DP(pos+1,n_rem,n_over,n_under))%INF;
    }
    return dp[pos][rem][over][under] = res;
}

/*Solution*/
void solve(){
    cin >> m >> d;
    cin >> a >> b;
    sz = a.size();
    memset(dp,-1,sizeof(dp));
    int rawr = Call_DP(0,0,0,0);
    cout << rawr << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
