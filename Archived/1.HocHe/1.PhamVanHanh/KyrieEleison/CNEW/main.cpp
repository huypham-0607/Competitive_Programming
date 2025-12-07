/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "ex"

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 2e18+7;
const long long LLL = 1e18;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int t,x;
vector<pii> v;
vector<int> CBT[(int)1e6+10];

int mul(int a, int b){
    if (a==0 || b==0) return 0;
    return LLINF/a<b? LLINF:a*b;
}

int getsqrt(int x){
    int rawr = sqrt(x);
    for (int i=-3; i<=3; i++){
        if ((rawr+i)*(rawr+i)==x) return rawr;
    }
    return 0;
}

/*Solution*/
void solve(){
    cin >> t;

    for (int i=1; i<=(int)1e6; i++){
        CBT[i].push_back(1);
        for (int j=1; j<=60; j++){
            int val = mul(CBT[i][(int)(j>>1)],CBT[i][(int)(j>>1)]);
            if ((j&1)) val = mul(val,i);
            if (val>LLL) break;
            CBT[i].push_back(val);
        }
    }

//    for (int i=1; i<=20; i++){
//        for (int j=1; j<min((int)10,(int)CBT[i].size()); j++){
//            cout << CBT[i][j] << " ";
//        }
//        cout << endl;
//    }

    while (t--){
        cin >> x;
        int l = 1, r = (int)1e6;
        v.push_back({x,1});
        int cock = getsqrt(x);
        if (cock){
            cout << -cock << " " << 2 << endl;
            v.push_back({cock,2});
        }
        for (int i=3; i<=60; i++){
            int rawr = 1;
            while (l<=r){
                int mid = (l+r)/2;
                if (i<(int)CBT[mid].size() && CBT[mid][i]<=x){
                    rawr = mid;
                    l = mid+1;
                }
                else r = mid-1;
            }
            if (CBT[rawr][i]==x){
                if (i%2==0){
                    cout << -rawr << " " << i << endl;
                }
                v.push_back({rawr,i});
            }
            l = 1;
            r = rawr;
            rawr = 1;
        }
        while (!v.empty()){
            cout << v.back().fi << " " << v.back().se << endl;
            v.pop_back();
        }
        cout << endl;
    }
//    cout << binpow(1000000000000000000,30) << endl;
}

/*Driver Code*/
signed main(){
//    freopen(NAME".INP","r",stdin);
//    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
