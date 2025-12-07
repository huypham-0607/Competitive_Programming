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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,kmax;
int a[N],b[N];
vector<int> occ[26];

void dec(int& curpos) {
    occ[a[curpos]].pop_back();
    --curpos;
}

void solve(){
    cin >> n >> kmax;
    for (int i=0; i<26; i++){
        occ[i].clear();
        occ[i].push_back(-INF);
    }
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c-'a';
        occ[a[i]].push_back(i);
    }
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        b[i] = c-'a';
    }


    vector<int> revpos(n+1);
    vector<int> sftpos(n+1,0);

    int mx = 0;

    int curpos = n;
    for (int i=n; i>0; i--){
        while (curpos > i){
            dec(curpos);
        }
        while (curpos > 0 && a[curpos]!=b[i]){
            dec(curpos);
        }

        if (curpos <= 0) revpos[i] = -INF;
        else revpos[i] = curpos;

        mx = max(mx,i-revpos[i]);
    }

    if (mx > kmax) {
        cout << -1 << endl;
        return;
    }
    cout << mx << endl;
    for (int i=1; i<=n; i++){
        sftpos[revpos[i]] = max(sftpos[revpos[i]],i-revpos[i]);
    }

//    for (int i=1; i<=n; i++){
//        cout << sftpos[i] << " ";
//    }

    vector<int> ans(n+1,0);
    for (int i=1; i<=n; i++){
        ans[i] = a[i];
    }
    for (int idx=1; idx<=mx; idx++){
        for (int i=1; i<=n; i++){
            if (idx<=sftpos[i]) {
                ans[i+idx] = a[i];
            }
        }

        for (int i=1; i<=n; i++){
            cout << (char)(ans[i]+'a');
        }
        cout << endl;
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

