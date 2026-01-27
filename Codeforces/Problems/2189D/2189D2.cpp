/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,c;

int p2(int x) {
    int cnt = 0;
    while (x%2==0) {
        ++cnt;
        x/=2;
    }
    return cnt;
}

void solve(){
    cin >> n >> c;
    string s;
    cin >> s;
    if (s[0] == '?') s[0] = '1';
    if (s[n-1] == '?') s[n-1] = '1';
    if (s[1] == '?') s[1] = '0';
    // cout << s << endl;
    if (s[0] == '0' || s[n-1] == '0') {
        cout << -1 << endl;
        return;
    }
    int ans = 1%c;
    int lmeo = 1%c;

    for (int i=1; i<n; i++){
        if (s[i] == '0'){
            ans = (ans*i)%c;
            lmeo = (lmeo*i)%MD;
        }
        else {
            ans = (ans*2)%c;
            lmeo = (lmeo*2)%MD;
        }
    }
    if (ans != 0) {
        cout << lmeo << endl;
        return;
    }

    // cout << "meow: " << lmeo << endl;

    int target = p2(c);
    int init = 0;
    ans = 1;
    for (int i=1; i<n; i++){
        if (s[i] == '0') {
            init += p2(i);
            ans = (ans*i)%MD;
        }
        if (s[i] == '1') {
            init++;
            ans = (ans*2)%MD;
        }
        if (s[i] == '?') {
            int val = p2(i);
            if (val != 0) {
                init++;
                ans = (ans*2)%MD;
            }
        }
    }
    if (init >= target) {
        cout << -1 << endl;
        return;
    }
    for (int i=n-1; i>0; i--){
        if (s[i] == '?') {
            int val = p2(i);
            if (val == 0) {
                if (init+1<target) {
                    init++;
                    ans = (ans*2)%MD;
                }
                else {
                    ans = (ans*i)%MD;
                }
            }
        }
    }
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

