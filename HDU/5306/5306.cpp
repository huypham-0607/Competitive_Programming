/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>

#define TEXT "5306"

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int N = 1e6 + 10;
const int INF = 1e9 + 7;
const int MD = 1e9 + 7; // 998244353;
const long long LLINF = 1e18 + 3;

// Starts here
struct Node
{
    int mx;
    int mx2;
    int mxcnt;
    ll sum;
    Node()
    {
        mx = -1;
        mx2 = -1;
        mxcnt = 0;
        sum = -1;
    }
};

int n, q;
int a[N];
Node IT[4 * N + 1];
int lazy[4 * N + 1];

void propagate(int idx, int l, int r)
{
    if (lazy[idx] != -1)
    {
        int mid = (l + r) / 2;
        int x = lazy[idx];

        // Update idx*2
        if (x < IT[idx * 2].mx)
        {
            IT[idx * 2].sum -= 1LL * (IT[idx * 2].mx - x) * IT[idx * 2].mxcnt;
            IT[idx * 2].mx = x;
            lazy[idx * 2] = x;
        }
        // Update idx*2+1
        if (x < IT[idx * 2 + 1].mx)
        {
            IT[idx * 2 + 1].sum -= 1LL * (IT[idx * 2 + 1].mx - x) * IT[idx * 2 + 1].mxcnt;
            IT[idx * 2 + 1].mx = x;
            lazy[idx * 2 + 1] = x;
        }
    }
    // Reset idx
    lazy[idx] = -1;
}

void comb(Node& i, Node l, Node r) {
    if (l.mx < r.mx)
        swap(l, r);

    i.mx = l.mx;
    i.mxcnt = l.mxcnt;
    i.sum = l.sum + r.sum;

    if (l.mx == r.mx)
    {
        i.mxcnt += r.mxcnt;
        i.mx2 = max(l.mx2, r.mx2);
    }
    else
    {
        i.mx2 = max({r.mx, l.mx2, r.mx2});
    }
}

void build(int idx, int l, int r)
{
    lazy[idx] = -1;
    if (l == r)
    {
        IT[idx].mx = a[l];
        IT[idx].mx2 = -1;
        IT[idx].mxcnt = 1;
        IT[idx].sum = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    comb(IT[idx], IT[idx * 2], IT[idx * 2 + 1]);
}

void update(int idx, int l, int r, int x, int y, int val)
{
    if (y < l || r < x || IT[idx].mx <= val)
        return;
    if (x <= l && r <= y && val < IT[idx].mx && IT[idx].mx2 < val)
    {
        IT[idx].sum -= 1LL * (IT[idx].mx - val) * IT[idx].mxcnt;
        IT[idx].mx = val;
        lazy[idx] = val;
        // cout << idx << " " << l << " " << r << endl;
        // cout << IT[idx].mx << " " << IT[idx].mx2 << " " << IT[idx].mxcnt << " " << IT[idx].sum << endl;
        return;
    }

    propagate(idx, l, r);

    int mid = (l + r) / 2;
    update(idx * 2, l, mid, x, y, val);
    update(idx * 2 + 1, mid + 1, r, x, y, val);
    comb(IT[idx], IT[idx * 2], IT[idx * 2 + 1]);
    // cout << idx << " " << l << " " << r << endl;
    // cout << IT[idx].mx << " " << IT[idx].mx2 << " " << IT[idx].mxcnt << " " << IT[idx].sum << endl;
}

ll range_sum(int idx, int l, int r, int x, int y)
{
    if (y < l || r < x)
        return 0;
    if (x <= l && r <= y)
    {
        return IT[idx].sum;
    }

    propagate(idx, l, r);

    int mid = (l + r) / 2;
    return range_sum(idx << 1, l, mid, x, y) + range_sum(idx << 1 | 1, mid + 1, r, x, y);
}

int range_max(int idx, int l, int r, int x, int y)
{
    if (y < l || r < x)
        return -1;
    if (x <= l && r <= y)
    {
        return IT[idx].mx;
    }

    propagate(idx, l, r);

    int mid = (l + r) / 2;
    return max(range_max(idx << 1, l, mid, x, y), range_max(idx << 1 | 1, mid + 1, r, x, y));
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int id, x, y, t;
        cin >> id >> x >> y;
        if (id == 0)
        {

            cin >> t;
            // cout << "Update: " << x << " " << y << " " << t << endl; 
            update(1, 1, n, x, y, t);
        }
        if (id == 1)
        {
            int mx = range_max(1, 1, n, x, y);
            cout << mx << endl;
        }
        if (id == 2)
        {
            ll sum = range_sum(1, 1, n, x, y);
            cout << sum << endl;
        }
    }
}

/*Driver Code*/
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TEXT ".inp", "r"))
    {
        freopen(TEXT ".inp", "r", stdin);
        freopen(TEXT ".out", "w", stdout);
    }

    int testCount = 1;
    cin >> testCount;
    while (testCount--)
    {
        solve();
    }

    return 0;
}
