/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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

int n,x,k;
string s;

int calc(int tmx) {
    int ans = 0;
    int tcnt = 0;
    int erem = 0;
    int irem = x-tmx;
    int store = 0;
    for (int i=0; i<n; i++){
        if (s[i] == 'A') {
            if (tcnt != tmx) {
                ++tcnt;
                ++ans;
                erem += k-1;
            }
            else {
                if (erem) {
                    ++ans;
                    --erem;
                }
            }
        }
        else if (s[i] == 'E') {
            if (erem) {
                ++ans;
                --erem;
            }
        }
        else if (s[i] == 'I') {
            if (irem) {
                ++ans;
                --irem;
                erem += k-1;
            }
        }
    }
    ans += min(erem,store);
    return ans;
}

pii check (int mid) {
    int val = calc(mid);
    return {val - calc(mid-1),val};
}

void solve(){
    cin >> n >> x>>k;
    cin >> s;
    int ans = calc(0);
    int l = 1, r = x;
    while (l<=r) {
        int mid = (l+r)/2;
        // cerr << mid << endl;
        pii res = check(mid);
        if (res.fi>0) {
            ans = res.se;
            l = mid+1;
        }
        else r = mid-1;
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

