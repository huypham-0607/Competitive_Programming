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

int n;

int getidx(char c) {
    return c-'a';
}

void checkvalid(string s) {
    for (int i=3; i<s.size(); i+=2) {
    }
}

void solve(){
    cin >> n;
    string s;
    int par = n%2;
    cin >> s;
    s = "b"+s;
    
    for (int i=1; i<=n; i++){
        if (s[i] == '?') {
            if (i+1 > n || s[i+1] == '?' || s[i-1] == s[i+1]) {
                s[i] = char('a'+(getidx(s[i-1])+1)%2);
            }
            else {
                s[i] = char('a'+(getidx(s[i-1])+(i+1)%2+par)%2);
            }
        }
    }

    int lb = getidx(s[n])%2;
    int rb = lb;
    for (int i=n-1; i>0; i--){
        if (getidx(s[i])!=lb) {
            lb^=1;
        }
        else if (getidx(s[i])!=rb) {
            rb^=1;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }

    // cout << lb << " " << rb << endl;

    if (par) {
        if (lb != 0 || rb != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    else {
        if (lb == rb) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

