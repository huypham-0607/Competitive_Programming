#include <bits/stdc++.h>
using namespace std;

struct Node
{
    uint64_t sum, max1, max2, nmax1, lazy_val;

    Node() { sum = max1 = max2 = nmax1 = 0, lazy_val = UINT64_MAX; }
};

struct SegmentTree
{
    vector<Node> t;
    size_t l;

    SegmentTree(vector<uint64_t> const &a)
    {
        l = 1 << (32 - __builtin_clz(a.size()));
        t = vector<Node>(2 * l);

        for (size_t i = 0; i < a.size(); i++)
        {
            t[l + i].sum = t[l + i].max1 = a[i];
            t[l + i].nmax1 = 1;
        }
        for (size_t i = l - 1; i; i--)
            t[i] = combine(t[2 * i], t[2 * i + 1]);
    }

    Node combine(Node x, Node y)
    {
        Node z;
        z.sum = x.sum + y.sum;
        if (x.max1 < y.max1)
            swap(x, y);
        z.max1 = x.max1;
        z.nmax1 = x.nmax1;
        if (y.max1 == x.max1)
            z.nmax1 += y.nmax1, z.max2 = max(x.max2, y.max2);
        else
            z.max2 = max(y.max1, x.max2);
        return z;
    }

    void propagate(size_t k)
    {
        if (t[2 * k].max1 > t[k].lazy_val)
        {
            t[2 * k].sum -= (t[2 * k].max1 - t[k].lazy_val) * t[2 * k].nmax1;
            t[2 * k].max1 = t[k].lazy_val;
            t[2 * k].lazy_val = t[k].lazy_val;
        }
        if (t[2 * k + 1].max1 > t[k].lazy_val)
        {
            t[2 * k + 1].sum -= (t[2 * k + 1].max1 - t[k].lazy_val) * t[2 * k + 1].nmax1;
            t[2 * k + 1].max1 = t[k].lazy_val;
            t[2 * k + 1].lazy_val = t[k].lazy_val;
        }
        t[k].lazy_val = UINT64_MAX;
    }

    void min_update(size_t i, size_t j, uint64_t v, size_t k, size_t x, size_t y)
    {
        if (y < i || x > j || t[k].max1 <= v)
            return;
        if (i <= x && y <= j && t[k].max2 < v && v < t[k].max1)
        {
            t[k].sum -= (t[k].max1 - v) * t[k].nmax1;
            t[k].max1 = v;
            t[k].lazy_val = v;
        }
        else if (y - x)
        {
            propagate(k);
            min_update(i, j, v, 2 * k, x, (x + y) / 2);
            min_update(i, j, v, 2 * k + 1, (x + y) / 2 + 1, y);
            t[k] = combine(t[2 * k], t[2 * k + 1]);
        }
    }

    uint64_t range_max(size_t i, size_t j, size_t k, size_t x, size_t y)
    {
        if (y < i || x > j)
            return 0;
        if (i <= x && y <= j)
            return t[k].max1;
        propagate(k);
        return max(range_max(i, j, 2 * k, x, (x + y) / 2),
                   range_max(i, j, 2 * k + 1, (x + y) / 2 + 1, y));
    }

    uint64_t range_sum(size_t i, size_t j, size_t k, size_t x, size_t y)
    {
        if (y < i || x > j)
            return 0;
        if (i <= x && y <= j)
            return t[k].sum;
        propagate(k);
        return range_sum(i, j, 2 * k, x, (x + y) / 2) +
               range_sum(i, j, 2 * k + 1, (x + y) / 2 + 1, y);
    }
};

int main()
{
    freopen("5306.inp","r",stdin);
    freopen("5306.ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    size_t t;
    cin >> t;

    for (size_t z = 0; z < t; z++)
    {
        size_t n, q;
        cin >> n >> q;

        vector<uint64_t> a(n);
        for (uint64_t &x : a)
            cin >> x;
        SegmentTree tree(a);

        while (q--)
        {
            unsigned c, i, j;
            cin >> c >> i >> j;

            switch (c)
            {
            case 0:
            {
                uint64_t v;
                cin >> v;
                tree.min_update(i - 1, j - 1, v, 1, 0, tree.l - 1);
                break;
            }
            case 1:
            {
                cout << tree.range_max(i - 1, j - 1, 1, 0, tree.l - 1) << '\n';
                break;
            }
            case 2:
            {
                cout << tree.range_sum(i - 1, j - 1, 1, 0, tree.l - 1) << '\n';
                break;
            }
            }
        }
    }
}