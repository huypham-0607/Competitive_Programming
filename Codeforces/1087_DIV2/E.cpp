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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;
int z[N];

void calc_z(const string &s) {
    for (int i=0; i<s.size(); i++){
        z[i] = 0;
    }
	z[0] = s.size();

	int l = 0;
	int r = 0;
	for (int i = 1; i < s.size(); i++) {
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
			l = i;
			r = i + z[i];
			z[i]++;
		}
	}
}

void solve(){
    cin >> n >> q;
    string sorg,s; cin >> sorg;
    stack<pii> st;
    for (int i=1; i<=q; i++){
        int l,r; cin >> l >> r;
        // cout << "query: " << l << " " << r << endl;
        int m = r-l+1;
        s = sorg.substr(l-1,r);
        calc_z(s);

        ll ans = 0;

        while (!st.empty()) st.pop();
        for (int i = 0; i < m; i++){

            int prev = -1;

            if (z[i]) {
                prev = ((st.empty()) ? 0 : st.top().se);
                // st.push({i+z[i],prev+1});
            }

            while (!st.empty() && st.top().fi <= i) {
                st.pop();
            }

            if (prev != -1) {
                st.push({i+z[i],prev+1});
            }

            int val = ((st.empty()) ? 0 : st.top().se);
            // cout << val << " " << z[i] << endl;
            ans += val;
        }

        cout << ans << endl;
    }
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

