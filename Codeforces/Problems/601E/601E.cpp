/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

typedef int int2;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 30010;
const int K = 1010;
const int INF = 1e9+7;
const int LG = 30;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int pw[K];

int n,k,m,q;
ll dp[K];
vector<pair<int, ll>> hist;

void addItem(int w, int val) {
    for (int i=k; i>=0; i--){
        if (i+w > k) continue;
        if (max(dp[i+w],dp[i]+val) != dp[i+w]) {
            hist.push_back({i+w,dp[i+w]});
            dp[i+w] = max(dp[i+w],dp[i] + val);
        }
    }
}

int getAns() {
    int res = 0;
    for (int i=1; i<=k; i++){
        // if (dp[i] != 0) cout << i << " " << dp[i] << endl;
        res = (1LL*res + (1LL*dp[i]%MD*pw[i-1])%MD)%MD;
    }
    return res;
}

int snapshot() {
    return hist.size();
}

void rollback(int ver) {
    while (hist.size() > ver) {
        dp[hist.back().fi] = hist.back().se;
        hist.pop_back();
    }
}

int value[N], weight[N]; 
int lb[N], rb[N];
int ans[N];

vector<int> query[4*N];
int IT[4*N];

void comb(int& i, int& l, int& r){
    i = l + r;
}

void addAnsQuery(int idx, int l, int r, int x) {
    if (r < x || x < l) return;
    if (l == r) {
        IT[idx] = 1;
        return;
    }
    
    int mid = (l+r)/2;
    addAnsQuery(idx*2,l,mid,x);
    addAnsQuery(idx*2+1,mid+1,r,x);
    comb(IT[idx], IT[idx*2], IT[idx*2+1]);
}

void updateQuery(int idx, int l, int r, int x, int y, int val){
    if (r < x || y < l) return;
    if (x <= l && r <= y){
        query[idx].push_back(val);
        return;
    }
    int mid = (l+r)/2;
    updateQuery(idx*2,l,mid,x,y,val);
    updateQuery(idx*2+1,mid+1,r,x,y,val);
}

void iterate(int idx, int l, int r) {
    if (!IT[idx]) return;

    int ver = snapshot();
    for (auto x:query[idx]) {
        addItem(weight[x],value[x]);
    }

    if (l==r) {
        ans[l] = getAns();
        rollback(ver);
        return;
    }

    int mid = (l+r)/2;
    iterate(idx*2,l,mid);
    iterate(idx*2+1,mid+1,r);
    rollback(ver);
}

void solve(){
    cin >> n >> k;
    pw[0] = 1;
    for (int i=1; i<=k; i++) {
        pw[i] = 1LL*pw[i-1]*((int)1e7+19)%MD;
    }

    for (int i=1; i<=n; i++){
        int v,w; cin >> v >> w;
        value[i] = v;
        weight[i] = w;
        lb[i] = 1;
    }

    cin >> q;

    for (int i=1; i<=min(n+q,15010); i++){
        rb[i] = q;
    }

    for (int i=1; i<=q; i++){
        ans[i] = -1;
    }

    for (int i=1; i<=q; i++){
        int id; cin >> id;
        if (id == 1) {
            ++n;
            int v,w; cin >> v >> w;
            weight[n] = w;
            value[n] = v;
            lb[n] = i;
        }
        else if (id == 2) {
            int x; cin >> x;
            rb[x] = i-1;
        }
        else {
            addAnsQuery(1,1,q,i);
        }
    }
    for (int i=1; i<=n; i++){
        if (rb[i] == -1) rb[i] = q;
        // cout << lb[i] << " " << rb[i] << endl;
        updateQuery(1,1,q,lb[i],rb[i],i);
    }

    iterate(1,1,q);
    for (int i=1; i<=q; i++){
        if (ans[i] != -1) {
            cout << ans[i] << endl;
        }
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