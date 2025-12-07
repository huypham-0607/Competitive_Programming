/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
int n;
vector<pii> a,b;
bitset<1000010> bs;

void Sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i=2; i*i<=1000000; i++){
        if (bs[i]){
            for (int j=i*i; j<=1000000; j+=i){
                bs[j] = 0;
            }
        }
    }
}

/*Solution*/
void solve(){
    Sieve();
    n = 20;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        a.push_back({x,i});
    }
    sort(all(a));
    int res = 0;
    for (int i=10; i<n; i++){
        b.push_back(a[i]);
    }
    for (int i=10; i<n; i++){
        a.pop_back();
    }
    n = 10;
    while (next_permutation(all(a))){
        bool ver = 1;
        for (int i=1; i<n; i++){
            if (!bs[abs(a[i].fi-a[i-1].fi)]){
                ver = 0;
                break;
            }
        }
        if (ver == 1){
            ++res;
            break;
        }
    }
    while (next_permutation(all(b))){
        bool ver = 1;
        for (int i=1; i<n; i++){
            if (!bs[abs(b[i].fi-b[i-1].fi)]){
                ver = 0;
                break;
            }
        }
        if (ver == 1){
            ++res;
            break;
        }
    }
    if (res == 0){
        cout << "OH NO" << endl;
    }
    else if (res == 1){
        cout << "OKELA" << endl;
    }
    else cout << "OH YEAH" << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

