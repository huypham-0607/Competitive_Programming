/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define fi first
#define se second

typedef int int2;
//#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

//mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,k;
int pref[N][N];
int dp[2][N];

inline int getDigit(){
    char ch = getchar();
    while (ch<'0' || ch>'9') ch = getchar();
    return ch-'0';
}

inline int getCost(int l, int r){
    return pref[r][r] - pref[r][l-1] - pref[l-1][r] + pref[l-1][l-1];
}

void DnC(int k, int l, int r, int optl, int optr){
    if (l>r) return;
    int mid = (l+r)/2;
    int optm = optl;
    dp[k&1][mid] = INF;
//    cout << l << " " << r << " " << mid << " " << optl << " " << optr << endl;
    for (int i=optl; i<=min(optr,mid); i++){
//        update(i,mid);
        int val = dp[(k-1)&1][i-1]+getCost(i,mid);
        if (val<dp[k&1][mid]){
            dp[k&1][mid] = val;
            optm = i;
        }
    }
    DnC(k,l,mid-1,optl,optm);
    DnC(k,mid+1,r,optm,optr);
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    scanf("%d %d",&n,&k);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            pref[i][j] = getDigit();
            pref[i][j] = pref[i][j] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
        }
    }

    for (int i=1; i<=n; i++){
        dp[0][i] = INF;
    }
    dp[0][0] = 0;

    for (int idx=1; idx<=k; idx++){
        DnC(idx,1,n,1,n);
    }

    cout << dp[k&1][n]/2;
    return 0;
}
