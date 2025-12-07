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

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 1e6+10;
const int MX = 1e6;
const int INF = 1e9+7;
const int LG = 6;
const int LG_2 = 20;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n;
int a[N];
int SOS_cnt[N], SOS_sum[N], SOS_sq[N], SOS[N];
int mag[6];


int bin_pow(int a, int b){
    int res = 1;
    for (int lg = LG_2-1; lg>=0; lg--){
        res = (res*res)%INF;
        if ((1<<lg)&b) res = (res*a)%INF;
    }
    return res;
}

/*Solution*/
void solve(){
    mag[0] = 1;
    for (int i=1; i<LG; i++){
        mag[i] = mag[i-1]*10;
    }
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        SOS_cnt[a[i]]++;
        SOS_sum[a[i]] = (SOS_sum[a[i]] + a[i])%INF;
        SOS_sq[a[i]] = (SOS_sq[a[i]]+a[i]*a[i])%INF;
    }

    for (int lg=0; lg<LG; lg++){
        for (int mask=MX-1; mask>=0; mask--){
            int idx = mask/mag[lg]%10;
//            cout << "{" << mask << " " << lg << " " << idx << "}" << " ";
            if (idx<9){
                SOS_cnt[mask] = SOS_cnt[mask] + SOS_cnt[mask+mag[lg]];
                SOS_sum[mask] = (SOS_sum[mask] + SOS_sum[mask+mag[lg]])%INF;
                SOS_sq[mask] = (SOS_sq[mask] + SOS_sq[mask+mag[lg]])%INF;
            }
        }
    }

    for (int i=0; i<MX; i++){
        if (SOS_cnt[i]){
            if (SOS_cnt[i]==1){
                SOS[i] = (SOS_sum[i]*SOS_sum[i])%INF*(bin_pow(2,SOS_cnt[i]-1))%INF;
            }
            else SOS[i] = ((SOS_sum[i]*SOS_sum[i])%INF*(bin_pow(2,SOS_cnt[i]-2))%INF + SOS_sq[i]*(bin_pow(2,SOS_cnt[i]-2))%INF)%INF;
        }
    }

//    for (int i=0; i<MX; i++){
//        cout << SOS[i] << endl;
//    }

    for (int lg=0; lg<LG; lg++){
        for (int mask=0; mask<MX; mask++){
            int idx = mask/mag[lg]%10;
            if (idx<9){
                SOS[mask] = (SOS[mask] - SOS[mask+mag[lg]] + INF)%INF;
            }
        }
    }

    int ans = 0;
    for (int i=0; i<MX; i++){
//        cout << SOS[i] << endl;
        ans^=(i*SOS[i]);
    }
//    for (int i=0; i<10; i++){
//        cout << SOS[i] << endl;
//    }
//    cout << SOS[MX-1] << endl;
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
