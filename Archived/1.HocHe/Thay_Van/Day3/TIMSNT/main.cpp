/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
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
vector<int> prime;
string s;

void sieve(){
    bitset<1000010> bs;
    bs.set();
    bs[1] = bs[0] = false;
    for (int i=2; i*i<=1000000; i++){
        if (bs[i]){
            for (int j=i*i; j<=1000000; j+=i){
                bs[j] = false;
            }
        }
    }
//    for (int i=0; i<=100; i++){
//        cout << bs[i] << endl;
//    }
    for (int i=1; i<=1000000; i++){
        if (bs[i]) prime.push_back(i);
    }
}

bool check(int& idx, int x){
    int cnt = 0, tmp = x;
    int rawr = 1;
    while (tmp!=0){
        ++cnt;
        tmp/=10;
        rawr*=10;
    }
//    cout << rawr << endl;
    while (rawr!=1){
        if (idx==(int)s.size()) return false;
        int c = (x%rawr)/(rawr/10);
        if (c!=(s[idx]-'0')) return false;
        ++idx;
        rawr/=10;
    }
    return true;
}

/*Solution*/
void solve(){
    sieve();
    cin >> s;
    int idx = 0;
    int i = 0;
    while (idx!=(int)s.size()){
        if (!check(idx,prime[i])){
            cout << "-1" << endl;
            return;
        }
//        cout << idx << " " << i << endl;
        ++i;
    }
    cout << prime[i-1] << endl;
}

/*Driver Code*/
signed main(){
    freopen("TIMSNT.inp","r",stdin);
    freopen("TIMSNT.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
