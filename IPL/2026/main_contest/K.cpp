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

int n;

void ask(int l, int r) {
    cout << "?" << " " << l << " " << r << endl;
    cout.flush();
}

void answer(int x) {
    cout << "!" << " " << x << endl;
    cout.flush();
}

int binary_search(int l, int r, int window) {
    int ans = l-1;
    while (l<=r) {
        int mid = (l+r)/2;
        ask(mid-window+1,mid);
        int res; cin >> res;
        if (!res) {
            ans = mid;
            l = mid+1;
        } 
        else {
            r = mid-1;
        }
    }
    return ans;
}

void solve(){
    cin >> n;
    ask(1,1);
    int res; cin >> res;
    if (res == 1) {
        answer(1);
        return;
    }
    int l = 1;
    int delta = 1;
    while (l+delta <= n) {
        ask(l+1,l+delta);
        cin >> res;
        if (res == 1) {
            int ans = binary_search(l+1,l+delta,delta);
            answer(ans+1);
            return;
        }
        l = l+delta;
        delta*=2;
    }
    int ans = binary_search(l+1,n,delta);
    answer(ans+1);
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

