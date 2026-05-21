#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <array>
#include <cassert>
#include <random>
#pragma GCC optimize ("O3")
using namespace std;
typedef long double ld;

const int moveX[] = {0, 0, 1, -1};
const int moveY[] = {-1, 1, 0, 0};

#define            task       "a"
#define          FORE(i, v)   for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define             ed        << "\n";
#define             el        cout<<'\n';
#define            ALL(s)     s.begin(),s.end()
#define             fi        first
#define             se        second
#define            SQ(a)      (a)*(a)
#define            A(a)        abs(a)
#define            SZ(a)      ((int)(a.size()))
#define          REP(i,a,b)    for (int i = (a), _b = (b); i < _b; i++)
#define          FOR(i,a,b)    for (int i = (a), _b = (b); i <= _b; i++)
#define          FOD(i,r,l)    for(int i=r; i>=l; i--)
#define           MASK(x)      (1LL << (x))
#define           BIT(x, i)    ((x) & (1ULL << (i)))
#define           pll          pair<ll,ll>
#define           db           double
#define           II(a, b)     make_pair((a),(b))
#define           pb(x)        push_back(x)
#define          ull unsigned long long
#define           int long long
#define         debug(x) cerr << #x << " = " << x << '\n';

template <class T> inline bool minimize(T &a, const T &b) {
    return (a > b ? (a = b),1 : 0);
}

template <class T> inline bool maximize(T &a, const T &b) {
    return (a < b ? (a = b),1 : 0);
}
const int  maxn = 1e6 + 10;
int n, k;
string str;
int a[1000005];
void input() {
  cin >> n >> k;
  cin >> str;
  FOR(i, 0, n-1) {
    a[i+1] = str[i]-'0';
  }
}


#pragma once
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 998244353; // faster if const

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

int root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
            a[i + j + k] = ai - z + (z > ai ? mod : 0);
            ai += (ai + z >= mod ? z - mod : z);
        }
}
vl conv(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
        n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i,0,n)
        out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

long long h[maxn];
long long ans_H[maxn];
vector<int> ans_1, ans_2;


void precompute() {
  long long totH = 0;
  FOR(i, 1, n - 1) {
    if (a[i] > 0 && a[i+1] == 0) h[i] += a[i];
    if (a[i] == 0 && a[i+1] > 0) h[i] += a[i+1];
      
    totH += h[i];
  }

  FOR(w, 1, n) {
    long long current_H = totH;
    for(int j = 1; j * w < n; j++) {
      int pos = j * w;
      current_H -= h[pos]; 
    }
    ans_H[w] = current_H;
  }
  // FOR(w, 1, n) cout << ans_H[w] << ' ';
  // cout << '\n';

  vector<int> v,b;
  FOR(i, 1, n)  {v.push_back(a[i]), b.push_back(a[i]==0?1:0);};
  reverse(ALL(v));

  ans_1 = conv(v, b);

  reverse(ALL(v));
  reverse(ALL(b));

  ans_2 = conv(v, b);
}

// int calcV(int w) {
//   int sum = 0;
//   FOR(i, 1, n-w) {

//     sum += a[i]*(a[i+w]==0?1:0);
//     sum += a[i+w]*(a[i]==0?1:0);
  
//   } //
//   // this equiv to : calcV(w)= sum_1^{n-w}(a[i] * b[i+w]) + sum_1^{n-w}(a[i+w] * b[i])
//   return sum;
// }

void lds_go_go_gooo(){
  precompute();
  vector<int> ans;
//   cerr << ans_1.size() << " " << ans_2.size() << endl;
  FOR(w, 1, n) {
    int tmp = ans_H[w];
    if (n+w-1 < ans_1.size()) tmp += ans_1[n+w-1];
    if (n+w-1 < ans_2.size()) tmp += ans_2[n+w-1];
    ans.push_back(tmp);
  }
  sort(ALL(ans));
  cout << ans[n - k];
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
     int t = 1;  //cin >> t;
    while(t -- ) {
        input();
        lds_go_go_gooo();
    }
    return 0;
}