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
const int N = 1e6+10;
const int LG = 20;
const int INF = 1e9+7;
const int MD = 1e9+7;
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
int a[N];
int cnt[(1<<LG)+10];
int SOScnt[(1<<LG)+10];
int SOS[(1<<LG)+10];

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=19; lg>=0; lg--){
        res = (res*res)%MD;
        if (b&(1<<lg)) res = (res*a)%MD;
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        ++SOScnt[a[i]];
    }

    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if (!(mask&(1<<i))){
                SOScnt[mask] = SOScnt[mask]+SOScnt[mask^(1<<i)];
            }
        }
    }

    for (int mask=0; mask<(1<<LG); mask++){
        cnt[mask] = bin_pow(2,SOScnt[mask]);
        SOS[mask] = cnt[mask];
    }

    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if (!(mask&(1<<i))){
                SOS[mask] = (SOS[mask]-SOS[mask^(1<<i)]+MD)%MD;
            }
        }
    }

//    for (int mask=0; mask<(1<<LG); mask++){
//        cout << SOScnt[mask] << " ";
//    }
//    cout << endl;
//
//    for (int mask=0; mask<(1<<LG); mask++){
//        cout << SOS[mask] << " ";
//    }
//    cout << endl;
//
//    for (int mask=0; mask<(1<<LG); mask++){
//        cout << cnt[mask] << " ";
//    }
//    cout << endl;


    cout << SOS[0] << endl;
}

/*Driver Code*/
signed main(){
//    freopen("449D.inp","r",stdin);
//    freopen("449D.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
