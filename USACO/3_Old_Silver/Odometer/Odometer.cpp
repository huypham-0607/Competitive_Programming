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
int l,r;
int dp[20][50][2][2];
int sz;
int num;

void reset(){
    memset(dp,-1,sizeof(dp));
}

int Getpos(int pos){
    int lvl = 1;
    for (int i=1; i<sz-pos; i++){
        lvl*=10;
    }
    return ((num/lvl)%10);
}

int calldp(int pos, int k, bool under, bool started, int idx1, int idx2){
    if (pos == sz){
        if (!started) return 0;
        if (idx2!=-1){
            if (k==20) return 1;
            else return 0;
        }
        else{
            if (k>=20) return 1;
            else return 0;
        }
    }

    if (dp[pos][k][under][started]!=-1) return dp[pos][k][under][started];

    bool n_under, n_started;
    int n_k;
    int res = 0;

    for (int i=0; i<=9; i++){
        int dig = Getpos(pos);

        if (!under && i>dig) break;

        n_started = (started||(i!=0));
        n_under = under;
        if (i<dig) n_under = true;

        if (n_started && idx2!=-1 && (i!=idx1 && i!=idx2)) continue;

        n_k = k;
        if (n_started){
            if (i == idx1) n_k+=1;
            else n_k-=1;
        }
        res+=calldp(pos+1,n_k,n_under,n_started,idx1,idx2);
    }
    return dp[pos][k][under][started] = res;
}

int GetAns(int x){
    num = x;
    sz = 0;
    int tmp = x;
    while (tmp!=0){
        ++sz;
        tmp/=10;
    }

    int res = 0;
    for (int i=0; i<=9; i++){
        reset();
        res += calldp(0,20,0,0,i,-1);
    }

    int dup = 0;
    for (int i=0; i<=9; i++){
        for (int j=i+1; j<=9; j++){
            reset();
            dup += calldp(0,20,0,0,i,j);
        }
    }

    return res-dup;
}

/*Solution*/
void solve(){
    cin >> l >> r;
    cout << GetAns(r) - GetAns(l-1) << endl;
}

/*Driver Code*/
signed main(){
    freopen("odometer.in","r",stdin);
    freopen("odometer.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
