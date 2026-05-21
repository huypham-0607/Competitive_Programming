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
int a[N];

void solve(){
    cin >> n;
    priority_queue<pii,vector<pii>,greater<pii>> min_heap;
    priority_queue<pii> max_heap;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        min_heap.push({a[i],-i});
        max_heap.push({a[i],-i});
    }

    vector<pii> ans;

    for (int epoch = 1; epoch <= 96767; epoch++) {
        while (a[-min_heap.top().se] != min_heap.top().fi) min_heap.pop();
        while (a[-max_heap.top().se] != max_heap.top().fi) max_heap.pop();

        int j = -min_heap.top().se;
        min_heap.pop();
        int i = -max_heap.top().se;
        max_heap.pop();

        if (i > j) swap(i,j);
        ans.push_back({i,j});
        int t = a[i] + a[j];
        a[i] = t/2;
        a[j] = t/2 + (t%2);
        min_heap.push({a[i],-i});
        max_heap.push({a[i],-i});
        min_heap.push({a[j],-j});
        max_heap.push({a[j],-j});
    }

    // int t = 0;
    // for (int i=1; i<=n; i++){
    //     t += a[i];
    // }
    // int x = t/n;

    // int pos = 1;
    // for (int i=1; i<=n; i++){
    //     if (a[i] == x) {
    //         if (i!=pos) {
    //             ans.push_back({i,pos});
    //             int t = a[i] + a[pos];
    //             a[pos] = t/2;
    //             a[i] = t/2 + (t%2);
    //         }
    //         ++pos;
    //     }
    // }
    cout << ans.size() << endl;
    for (auto [i,j]:ans) {
        cout << i << " " << j << endl;
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

