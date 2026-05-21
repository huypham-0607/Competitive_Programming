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
map<int,int> sz;

void get_sizes(int l, int r) {
    if (l>r) return;
    sz[r-l+1]++;
    int mid = (l+r)/2;
    get_sizes(l,mid-1);
    get_sizes(mid+1,r);
}

map<int,map<int,int>> mp; 
int ans[(int)(5e6+10)];

int get_left(int x) {
    return (x-1)/2;
}

int get_right(int x) {
    return x/2;
}

void process(int x) {
    if (x == 0) return;
    int k = (x+1)/2;
    int l = get_left(x), r = get_right(x);
    // cout << "process: " <<  x << " " << l << " " << r << endl;

    for (auto ls:mp[l]) {
        for (auto rs:mp[r]) {
            ans[get_right(ls.fi)+get_left(rs.fi)+2] += ls.se*rs.se*sz[x];
        }
    }

    for (int i=1; i<=x; i++) {
        if (i<k) ans[k-i] += sz[x];
        if (i>k) ans[i-k] += sz[x];
    }

    for (auto ls:mp[l]) {
        mp[x][ls.fi] += ls.se;
    }

    for (auto rs:mp[r]) {
        mp[x][rs.fi] += rs.se;
    }

    mp[x][x]++;
}

void solve(){
    cin >> n;
    sz[0] = 0;
    get_sizes(1,n);
    
    int id = 0;
    for (auto x:sz) {
        process(x.fi);

        // for (int i=0; i<=n; i++){
        //     cout << ans[i] << " ";
        // }
        // cout << endl;

        ++id;
    }

    // for (auto in:sz) {
    //     cout << "size: " << in.fi << endl;
    //     for (auto s:mp[in.fi]) {
    //         cout << s.fi << " " << s.se << endl;
    //     }
    // }

    // for (auto in:sz) {
    //     cout << in.fi << " " << in.se << endl;
    // }

    for (int i=0; i<=n; i++){
        cout << ans[n-i] << " ";
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

