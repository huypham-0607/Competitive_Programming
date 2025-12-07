/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
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
int n,remain,q;
vector<int> Prime;
int a[N],b[N],pre[N];
int SOS[N], SOSFact[N];
bool Semi_Prime_Check = false;
map<int,int> mp;
vector<pii> dim;
vector<int> block;

void Sieve(){
    int LIM = 1000000;
    bitset<1000010> bs;
    bs.set();
    bs[0] = bs[1] = 0;

    for (int i=2; i*i<=LIM; i++){
        if (!bs[i]) continue;
        for (int j=i*i; j<=LIM; j+=i){
            bs[j] = 0;
        }
    }

    for (int i=2; i<=LIM; i++){
        if (bs[i]) Prime.push_back(i);
    }
}

void Check_Semiprime(int x){
    if (remain!=1 && !Semi_Prime_Check){
        int gcd = __gcd<long long>(remain,x);
        int low = min(gcd,remain/gcd);
        int high = max(gcd,remain/gcd);
        if (low != 1){
            Semi_Prime_Check = true;
            if (low == high){
                dim.push_back({low,2});
            }
            else{
                dim.push_back({low,1});
                dim.push_back({high,1});
            }
        }
    }
}

void Finalize_Semiprime(){
    if (remain!=1 && !Semi_Prime_Check){
        Semi_Prime_Check = true;
        dim.push_back({remain,1});
    }
}

/*Solution*/
void solve(){
    Sieve();
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pre[i] = a[i] + pre[i-1];
    }

    remain = pre[n];

    for (auto x:Prime){
        int cnt = 0;
        while (remain!=1 && remain%x==0){
            remain/=x;
            ++cnt;
        }
        if (cnt){
            dim.push_back({x,cnt});
        }
    }

    for (int i=1; i<=n; i++){
        Check_Semiprime(a[i]);
    }

    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> b[i];
        Check_Semiprime(b[i]);
    }

    Finalize_Semiprime();

    int LG = dim.size();
    block.resize(LG);
    int LIM = 1;
    for (int i=0; i<LG; i++){
        dim[i].se++;
        LIM*=dim[i].se;
    }

    int tmp = 1;
    for (int i=0; i<LG; i++){
        int tmp2 = tmp*dim[i].se;
        block[i] = tmp;
        tmp = tmp2;
    }

//    for (int i=0; i<LG; i++){
//        cout << dim[i].fi << " " << dim[i].se << " " << block[i] << endl;
//    }

    SOSFact[0] = 1;
    for (int i=0; i<LG; i++){
        SOSFact[block[i]] = dim[i].fi;
    }

    for (int mask=0; mask<LIM; mask++){
        SOSFact[mask] = 1;
        for (int i=0; i<LG; i++){
            int idx = (mask/block[i])%dim[i].se;
            for (int x=1; x<=idx; x++){
                SOSFact[mask]*=dim[i].fi;
            }

        }
    }

//    for (int i=0; i<LG; i++){
//        for (int mask=0; mask<LIM; mask++){
//            if (!((mask/block[i])%dim[i].se == 0)){
//                SOSFact[mask] = __gcd<long long>(SOSFact[mask],SOSFact[mask-block[i]]);
//            }
//        }
//    }

//    for (int mask=0; mask<LIM; mask++){
//        cout << SOSFact[mask] << " ";
//    }
//    cout << endl;

    for (int mask=0; mask<LIM; mask++){
        mp.insert({SOSFact[mask],mask});
    }

    for (int i=1; i<n; i++){
        int gcd = __gcd<long long>(pre[n],pre[i]);
        int mask = mp[gcd];
        SOS[mask]++;
    }

    for (int i=0; i<LG; i++){
        for (int mask=LIM-1; mask>=0; mask--){
            if (!((mask/block[i])%dim[i].se == dim[i].se-1)){
                SOS[mask]+=SOS[mask+block[i]];
            }
        }
    }

    for (int mask=0; mask<LIM; mask++){
        mp[SOSFact[mask]] = SOS[mask];
    }

    for (int i=1; i<=q; i++){
        if (pre[n]%b[i]!=0) cout << -1 << endl;
        else{
//            cout << n << " " << pre[n]/b[i] << " " << 2*mp[b[i]] << " ";
            cout << n+(pre[n]/b[i])-2-(2*mp[b[i]]) << endl;
        }
    }
//    cout << b[2413];
}

/*Driver Code*/
signed main(){
//    freopen("SleepingInClass.inp","r",stdin);
//    freopen("SleepingInClass.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
