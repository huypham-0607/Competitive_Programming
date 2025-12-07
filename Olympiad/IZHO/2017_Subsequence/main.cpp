/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;
const int LGF = 20;
const int LGH = 10;

//Starts here

int n;
int a[N],b[N];
pii save[(1<<LGH)][(1<<LGH)][LGH+1];
pii trace[N];

int getp1(int x) {
    int mask = (1<<LGH)-1;
    return (x&mask);
}

int getp2(int x) {
    int mask = ((1<<LGF)-1) - ((1<<LGH)-1);
    return ((x&mask)>>LGH);
}

string binRep(int x, int LG) {
    string s;
    for (int lg=0; lg<LG; lg++){
        s = (((1<<lg)&x)?'1':'0') + s;
    }
    return s;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> b[i];
    }

    pii ans = {0,0};

    for (int i=1; i<=n; i++){
        pii cur = {0,0};
        int p1 = getp1(a[i]);
        int p2 = getp2(a[i]);

//        cout << binRep(a[i],LGF) << endl;
//        cout << binRep(p2,LGH) << " " << binRep(p1,LGH) << endl;

        for (int m1=0; m1<(1<<LGH); m1++){
            int rem = b[i] - __builtin_popcountll(p1&m1);
            if (rem < 0 || rem > 10) continue;
            cur = max(cur,save[m1][p2][rem]);
        }
        cur.fi++;
        trace[i] = cur;
        cur.se = i;
        ans = max(ans,cur);
        for (int m2=0; m2<(1<<LGH); m2++){
            int cnt = __builtin_popcountll(p2&m2);
            save[p1][m2][cnt] = max(save[p1][m2][cnt],cur);
        }
    }

    cout << ans.fi << endl;
    pii cur = ans;
    vector<int> order;
    while (cur.se) {
        order.push_back(cur.se);
        cur = trace[cur.se];
    }
    reverse(all(order));
    for (auto x:order) {
        cout << x << " ";
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
