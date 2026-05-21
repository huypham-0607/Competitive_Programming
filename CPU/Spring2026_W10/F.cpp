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

int n,d;
int a[N];

void solve(){
    cin >> n >> d;
    multiset<int> st;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=n; i++){
        st.insert(a[i] - a[i-1]-1);
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        int delta = a[i] - a[i-1] -1;
        st.erase(st.lower_bound(delta));
        if (i != n) {
            st.erase(st.lower_bound(a[i+1] - a[i] -1));
            st.insert(a[i+1] - a[i-1] -1);
        }

        int a1 = min(((*st.rbegin())-1)/2,(*st.begin()));
        int a2;
        if (i == n) {
            a2 = min(d-a[n-1]-1,(*st.begin()));
        }
        else a2 = min(d-a[n]-1,(*st.begin()));

        ans = max(ans,a1);
        ans = max(ans,a2);

        // for (auto x:st) {
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << i << " " << a1 << " " << a2 << " " << (*st.begin()) << endl;

        st.insert(delta);
        if (i != n) {
            st.insert(a[i+1] - a[i] -1);
            st.erase(st.lower_bound(a[i+1] - a[i-1] -1));
        }
    }
    cout << ans << endl;
    // cout << endl;
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

