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
int sz,l,r;
pii dp[20][2][2][2];

int Getidx(int x, int pos){
    int lvl = 1;
    for (int i=1; i<sz-pos; i++){
        lvl*=10;
    }
//    cout << pos << " " << lvl << endl;
    return ((x/lvl)%10);
}

pii Call_DP(int pos, bool started, bool over, bool under){
    if (pos == sz){
        return make_pair(0,1);
    }

    if (dp[pos][started][over][under].se!=-1) return dp[pos][started][over][under];

    int digl = Getidx(l,pos);
    int digr = Getidx(r,pos);
//    cout << pos << " " << digl << " " << digr << endl;
    bool n_started,n_over,n_under;
    pii res = {0,0};
    for (int i=0; i<10; i++){
        if (!over && i<digl) continue;
        if (!under && i>digr) break;

        n_started = started||(i!=0);
        n_over = over||(i>digl);
        n_under = under||(i<digr);

        pii tmp = Call_DP(pos+1,n_started,n_over,n_under);
        if (n_started){
            tmp.fi+=i*tmp.se;
        }
//        cout << pos << " "  << i << " " << tmp.fi << " " << tmp.se << endl;
        res.fi+=tmp.fi;
        res.se+=tmp.se;
    }
    return dp[pos][started][over][under] = res;
}

/*Solution*/
void solve(){
    cin >> l >> r;
    memset(dp,-1,sizeof(dp));
    int tmp = r;
    sz = 0;
    while (tmp){
        ++sz;
        tmp/=10;
    }
//    cout << sz << endl;
    pii rawr = Call_DP(0,0,0,0);
    cout << rawr.fi << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
