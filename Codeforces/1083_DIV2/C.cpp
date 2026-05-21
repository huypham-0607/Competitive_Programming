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

const int N = 3010;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int l[N];
int marked[(int)1e6+10];
int marked2[(int)1e6+10];
int a[N][N];

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        vector<int> tmp;
        cin >> l[i];
        for (int j=1; j<=l[i]; j++){
            int x; cin >> x;
            a[i][j] = x;
        }
    }

    vector<int> ans;
    vector<int> best;
    vector<int> tmp;
    for (int lvl=1; lvl<=n; lvl++){
        for (int idx=1; idx<=n; idx++){
            for (int i=l[idx]; i>0; i--){
                if (!marked[a[idx][i]] && !marked2[a[idx][i]]) {
                    tmp.push_back(a[idx][i]);
                    marked[a[idx][i]] = true;
                }
            }
            if (tmp.size() == 0) continue;
            if (best.size() == 0 || tmp < best) {
                swap(tmp,best);
            }
            for (int i=l[idx]; i>0; i--) {
                marked[a[idx][i]] = false;
            }
            tmp.clear();
        }
        for (auto x:best) {
            ans.push_back(x);
            marked2[x] = true;
        }
        best.clear();
    }

    for (auto x:ans) {
        cout << x << " ";
        marked2[x] = false;
    }
    cout << endl;
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
        // cout << "wtf" << endl;
        solve();
    }

    return 0;
}

