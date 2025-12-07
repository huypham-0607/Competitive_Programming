/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
//#define int long long
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 22;
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
int a[N],b[N];
vector<long long> nen;
vector<pair<long long,int>> sta,stb;
vector<int> cnta[2000];
set<int> cntb[2000];
int sus[2000][2000];

void DP(int n, int val[], vector<pair<long long,int>>& st){
    for (int mask=1; mask<(1<<n); mask++){
        long long t = 0;
        for (int idx=0; idx<n; idx++){
            if ((mask>>idx)&(int)1) t+=val[idx];
        }
        int fixidx = __builtin_ctz(mask);
//        cout << fixidx << endl;
        for (int submask = mask; submask; submask = (submask-1)&mask){
            if (!(submask&((int)1<<fixidx))) continue;
            long long t1 = 0;
            for (int idx=0; idx<n; idx++){
                if ((submask>>idx)&(int)1) t1+=val[idx];
            }
            long long t2 = t - t1;
            long long sus = abs(t1-t2);
            nen.push_back(sus);
            st.push_back({sus,mask});
        }
    }
    nen.push_back(0);
    st.push_back({0,0});
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=0; i<n/2; i++){
        cin >> a[i];
    }
    for (int i=n/2; i<n; i++){
        cin >> b[i-n/2];
    }
    DP(n/2,a,sta);
    DP(n-(n/2),b,stb);

//    for (auto x:sta) cout << x.fi << " "; cout << endl;
//    for (auto x:stb) cout << x.fi << " "; cout << endl;

    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());

    for (int i=0; i<(int)sta.size(); i++){
        sta[i].fi = lower_bound(all(nen),sta[i].fi) - nen.begin();
    }
    for (int i=0; i<(int)stb.size(); i++){
        stb[i].fi = lower_bound(all(nen),stb[i].fi) - nen.begin();
    }

    sort(all(sta));
    sta.resize(unique(all(sta))-sta.begin());
    sort(all(stb));
    stb.resize(unique(all(stb))-stb.begin());

    for (auto x:sta){
        cnta[x.se].push_back(x.fi);
    }
    for (auto x:stb){
        cntb[x.se].insert(x.fi);
    }
    int ans = 0;
    for (int maska=0; maska<(1<<(n/2)); maska++){
        for (int maskb=0; maskb<(1<<(n-n/2)); maskb++){
            for (auto x:cnta[maska]){
                if (cntb[maskb].count(x)){
                    sus[maska][maskb] = true;
                    break;
                }
            }
            if (sus[maska][maskb]) ++ans;
        }
    }
//    for (int i=0; i<(int)nen.size(); i++){
//        ans+=cnta[i]*cntb[i];
//    }

    cout << (ans-1) << endl;
}

/*Driver Code*/
signed main(){
//    freopen("subsets.in","r",stdin);
//    freopen("subsets.out","w",stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    TestCases(0);

    return 0;
}
