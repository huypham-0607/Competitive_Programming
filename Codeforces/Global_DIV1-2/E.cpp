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
const int N = 2e5+10;
const int LG = 31;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,q;

/*Solution*/
void solve(){
    int n;
    vector<int> a;
    vector<int> cnt(LG+10,0);
    vector<int> ans(LG+10,0);
    int sus = 0;
    int sieve = (1LL<<LG)-1;

//    cout << (1<<LG) << endl;

    cin >> n >> q;

    //Count bit occurence
    for (int i=0; i<n; i++){
        int x; cin >> x;
        a.push_back(x);
        for (int lg=0; lg<LG; lg++){
            if (x&(1<<lg)) ++cnt[lg];
        }
    }

    int lmao = 0;
    for (int lg=0; lg<LG; lg++){
        if (cnt[lg]) ++lmao;
        if (cnt[lg] == 1) sieve = sieve^(1<<lg);
    }

    int curcnt = 0;
    for (int lg=0; lg<LG; lg++){
        if (cnt[lg]) continue;
        ++curcnt;

        //Find largest
        int idx=-1; int val = LLINF;
        for (int i=0; i<n; i++){
            int tmp = 0;
            for (int lg2 = (lg-1); lg2>=0; lg2--){
//                cout << lg2 << " " << i << endl;
                if (!((1<<lg2)&a[i]) || cnt[lg2] == 1){
                    tmp += (1<<lg2);
                }
            }
            if (tmp<val){
                val = tmp;
                idx = i;
            }
        }

        ans[curcnt] += val;
        for (int lg2 = (lg-1); lg2>=0; lg2--){
            if (!((1<<lg2)&a[idx]) || cnt[lg2] == 1){
//                ans[curcnt] += (1<<lg2);
            }
            else{
                a[idx]^=(1<<lg2);
                cnt[lg2]--;
                if (cnt[lg2] == 1) sieve = sieve^(1<<lg2);
            }
        }

        a[idx]^=(1<<lg);
        cnt[lg]++;
        if (cnt[lg] == 1) sieve = sieve^(1<<lg);

        ans[curcnt]+=ans[curcnt-1]+1;
        sus = sus^(1<<lg);
    }

//    cout << curcnt << endl;
//
//    for (int i=0; i<=10; i++){
//        cout << ans[i] << " ";
//    }
//    cout << endl;

//    cin >> q;
    while (q--){
        int x; cin >> x;
        int idx = upper_bound(ans.begin(),ans.begin()+curcnt+1,x) - ans.begin()-1;
        cout << lmao+idx << endl;

    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
