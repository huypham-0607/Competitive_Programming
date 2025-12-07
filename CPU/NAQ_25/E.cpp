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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<int> a;
vector<int> b;

int computeDist(int x, int y){
    return (x-144)*(x-144)+(y-84)*(y-84);
}

void solve(){
    int sa = 0, sb = 0;
    for (int tst=1; tst<=10; tst++){
        int ma=INF,mb=INF;
        a.clear(); b.clear();

        cin >> n;

        for (int i=0; i<n; i++){
            int x,y; cin >> x >> y;
            int tmp = computeDist(x,y);
            ma = min(ma,tmp);
            a.push_back(tmp);
        }

        cin >> m;

        for (int i=0; i<m; i++){
            int x,y; cin >> x >> y;
            int tmp = computeDist(x,y);
            mb = min(mb,tmp);
            b.push_back(tmp);
        }

        if (ma < mb){
            for (int i=0; i<n; i++){
                if (a[i] < mb) ++sa;
            }
        }
        if (mb < ma){
            for (int i=0; i<m; i++){
                if (b[i] < ma) ++sb;
            }
        }
    }
    cout << sa << " " << sb;
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

