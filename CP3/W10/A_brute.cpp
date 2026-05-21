/*
 * Author: Arseni Anoshka
 */
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define i128 __int128_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ppii pair<pair<int, int>, int>
#define szf(a) ((int)((a).size()))
#define what_is(x) cerr << #x << " is " << x << endl;
#define bit(x) cerr << bitset<64>(x) << "\n"
#define bitcnt(x) __builtin_popcount(x)
#define clz(x) (!x ? 32 : __builtin_clz(x))
#define inf 1e9
#define INF 1e18
#define MOD 998'244'353
#define MOD1 1'000'000'007
#define MODMAX 9223372036854775783LL
#define YES { cout << "YES\n"; return; }
#define NO { cout << "NO\n"; return; }

#define x first
#define y second

using namespace std;

constexpr int N = 1'000'005;


void solve() {
    int k; cin >> k;
    string s; cin >> s;
    int n = s.size();
 
    int cnt = 0;
    int st = 0, en = 0;

    for (; en < n; en++) {
        cnt += s[en] - '0';
        if (cnt == k)  break;
    }

    en++;

    ll res = 0;
    while (en <= n) {
        ll d1 = 1;
        while (st < n && s[st] == '0') { // st goes to first one d1 is number of zeros + 1
            st++; 
            d1++;
        }


        ll d2 = 1;
        while (en < n && s[en] == '0') { // goes to the k + 1 th one d1 is number of zeros + 1
            en++; 
            d2++;
        }

        res += d1 * d2;
        st++;
        en++;
    }


    cout << res << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("A.inp","r")){
        freopen("A.inp","r",stdin);
        freopen("A.ans","w",stdout);
    }

    int tt = 1; //cin >> tt;
    while (tt--) {
        solve();
        #ifdef LDHOME
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LDHOME
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}