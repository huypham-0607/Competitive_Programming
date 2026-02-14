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

void ask(int x) {
    cout << "? " << x << endl;
    cout.flush();
}

void answer(int x, vector<pii>& edges) {
    cout << "! " << x << endl;
    for (auto [x,y]:edges) {
        cout << x << " " << y << endl;
    }
    cout.flush();
}

void solve(){
    cin >> n;
    vector<pii> edges;
    vector<int> nodes;
    int pivot = 1;
    pii prev = {1,0};
    while (prev.fi != 0) {
        int l = pivot+1; int r = (1LL<<30)-1;
        int ans = r+1;
        pii lmeo = {0,0};
        while (l<=r) {
            pii cur = {0,0};
            int mid = (l+r)/2;
            ask(mid);
            
            int ncnt; cin >> ncnt;
            for (int i=1; i<=ncnt; i++){
                int x; cin >> x;
                if (i == 1) cur.fi = x;
                if (i == 2) cur.se = x;
            }

            if (cur.fi != prev.fi || cur.se != prev.se) {
                ans = mid;
                lmeo = cur;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        if (lmeo.se != 0) {
            edges.push_back(lmeo);
        }
        prev = lmeo;
        pivot = ans;
        // for (auto [x,y]:edges) {
        //     cout << x << " " << y << endl;
        //     cout.flush();
        // }
    }
    answer(edges.size(), edges);
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

