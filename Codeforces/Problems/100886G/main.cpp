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
int l,r,sz;
int lvl[20];
pii dp[20][2][2][2];

int Getidx(int x, int pos){
    return ((x/lvl[sz-pos])%10);
}

pii Call_DP(int pos, bool started, bool over, bool under){
    if (pos == sz){
        if (!started) return {0,0};
        else return {1,0};
    }

    if (dp[pos][started][over][under].fi != -1) return dp[pos][started][over][under];

    pii res = {-1,-1};
    bool n_started, n_over, n_under;
    for (int i=0; i<10; i++){
        int digl = Getidx(l,pos);
        int digr = Getidx(r,pos);

        if (!over && i<digl) continue;
        if (!under && i>digr) break;

        n_started = started||(i!=0);
        n_over = over||(i>digl);
        n_under = under||(i<digr);

        pii tmp = Call_DP(pos+1,n_started,n_over,n_under);
        if (n_started){
            tmp.fi*=i;
            tmp.se+=i*lvl[sz-pos];
        }
//        cout << pos << " " << i << " " << tmp << endl;
        res = max(res,tmp);
    }
    return dp[pos][started][over][under] = res;
}

/*Solution*/
void solve(){
    cin >> l >> r;
    sz = 0;
    int tmp = r;
    while (tmp!=0){
        ++sz;
        if (sz == 1) lvl[sz] = 1;
        else lvl[sz] = lvl[sz-1]*10;
        tmp/=10;
    }
//    cout << sz << endl;
    memset(dp,-1,sizeof(dp));
    pii rawr = Call_DP(0,0,0,0);
    cout << rawr.se << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
