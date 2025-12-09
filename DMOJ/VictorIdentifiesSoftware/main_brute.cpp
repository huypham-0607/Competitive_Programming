#include <bits/stdc++.h>

//idea: use 3 lazy segtree, for managing the max_stretch and max_value for each type of games and for the total array

//when we want to turn a segment to a type, the information for whole segment is in the 3rdsegment tree, 
//so we can have O(1) update for segment tree of both games

//when we want to change values of a segment to the same value, easy O(1) update

using namespace std;

#define int long long

const int N = 300010;
const int inf = 1e10;

struct Block {
    int len, sum, total_max, left_max, right_max, max_value;
};

Block mrg(Block b1, Block b2) {
    return {b1.len + b2.len,
                 b1.sum + b2.sum,
                 max(b1.right_max + b2.left_max, max(b1.total_max, b2.total_max)),
                 max(b1.left_max, b1.sum + b2.left_max),
                 max(b1.right_max + b2.sum, b2.right_max), max(b1.max_value, b2.max_value)};
}

int n, q, a[N], st_max[4 * N][2], st_max_value[4 * N][2], longest_bl[4 * N][2];

Block st[4 * N], left_bl[4 * N][2], right_bl[4 * N][2];

int lazy_val[4 * N], lazy_state[4 * N];

void build(int id, int l, int r) {
    lazy_val[id] = inf;
    lazy_state[id] = - 1;

    left_bl[id][1].max_value = right_bl[id][1].max_value = st_max_value[id][1] = - inf;


    if (l == r) {
        st[id].len = 1;
        st[id].sum = a[l];
        st[id].total_max = st[id].left_max = st[id].right_max = max((int) 0, a[l]);
        st[id].max_value = a[l];

        left_bl[id][0] = right_bl[id][0] = st[id];

        st_max[id][0] = st[id].total_max;
        st_max_value[id][0] = a[l];
        longest_bl[id][0] = 1;


        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = mrg(st[id * 2], st[id * 2 + 1]);

    left_bl[id][0] = right_bl[id][0] = st[id];

    longest_bl[id][0] = r - l + 1;
    st_max[id][0] = st[id].total_max;
    st_max_value[id][0] = st[id].max_value;

}

void update(Block &b, int k) {
    b.total_max = b.right_max = b.left_max = max((int) 0, b.len * k);
    b.sum = b.len * k;
    b.max_value = k;
}

void down(int id, int l, int r) {
    int mid = (l + r) / 2;

    if (lazy_val[id] != inf) {
        int k = lazy_val[id];

        update(st[id * 2], k);
        update(st[id * 2 + 1], k);

        for (int i = 0; i < 2; i ++) {
            update(left_bl[id * 2][i], k);
            update(right_bl[id * 2][i], k);

            update(left_bl[id * 2 + 1][i], k);
            update(right_bl[id * 2 + 1][i], k);

            st_max[id * 2][i] = max((int) 0, longest_bl[id * 2][i] * k);
            st_max[id * 2 + 1][i] = max((int) 0, longest_bl[id * 2 + 1][i] * k);

            st_max_value[id * 2][i] = longest_bl[id * 2][i] > 0 ? k : - inf;
            st_max_value[id * 2 + 1][i] = longest_bl[id * 2 + 1][i] > 0 ? k : - inf;
        }

        lazy_val[id * 2] = lazy_val[id * 2 + 1] = k;
        lazy_val[id] = inf;
    }

    if (lazy_state[id] != - 1) {
        int k = lazy_state[id];
        left_bl[id * 2][k] = right_bl[id * 2][k] = st[id * 2];
        left_bl[id * 2 + 1][k] = right_bl[id * 2 + 1][k] = st[id * 2 + 1];
        st_max[id * 2][k] = st[id * 2].total_max;
        st_max[id * 2 + 1][k] = st[id * 2 + 1].total_max;
        longest_bl[id * 2][k] = mid - l + 1;
        longest_bl[id * 2 + 1][k] = r - mid;
        st_max_value[id * 2][k] = st[id * 2].max_value;
        st_max_value[id * 2 + 1][k] = st[id * 2 + 1].max_value;

        left_bl[id * 2][1 - k] = right_bl[id * 2][1 - k] = left_bl[id * 2 + 1][1 - k] = right_bl[id * 2 + 1][1 - k] = {0, 0, 0, 0, 0, - inf};
        st_max[id * 2][1 - k] = st_max[id * 2 + 1][1 - k] = 0;
        longest_bl[id * 2][1 - k] = longest_bl[id * 2 + 1][1 - k] = 0;
        st_max_value[id * 2][1 - k] = - inf;
        st_max_value[id * 2 + 1][1 - k] = - inf;

        lazy_state[id * 2] = lazy_state[id * 2 + 1] = k;
        lazy_state[id] = - 1;
    }
}

void st_mrg(int id, int l, int r) {
    st[id] = mrg(st[id * 2], st[id * 2 + 1]);

    int mid = (l + r) / 2;

    for (int i = 0; i < 2; i ++) {

        Block mid_bl = mrg(right_bl[id * 2][i], left_bl[id * 2 + 1][i]);

        longest_bl[id][i] = max(mid_bl.len, max(longest_bl[id * 2][i], longest_bl[id * 2 + 1][i]));
        st_max[id][i] = max(mid_bl.total_max, max(st_max[id * 2][i], st_max[id * 2 + 1][i]));

        left_bl[id][i] = left_bl[id * 2][i];
        if (left_bl[id * 2][i].len == mid - l + 1) left_bl[id][i] = mid_bl;

        right_bl[id][i] = right_bl[id * 2 + 1][i];
        if (right_bl[id * 2 + 1][i].len == r - mid) right_bl[id][i] = mid_bl;

        st_max_value[id][i] = max(st_max_value[id * 2][i], st_max_value[id * 2 + 1][i]);
    }
}

void update_val(int id, int l, int r, int u, int v, int k) {
    if (r < u || v < l) return;

    if (u <= l && r <= v) {
        update(st[id], k);
        for (int i = 0; i < 2; i ++) {
            update(left_bl[id][i], k);
            update(right_bl[id][i], k);

            st_max[id][i] = max((int) 0, longest_bl[id][i] * k);

            st_max_value[id][i] = longest_bl[id][i] > 0 ? k : - inf;
        }
        lazy_val[id] = k;
        return;
    }

    int mid = (l + r) / 2;
    down(id, l, r);

    update_val(id * 2, l, mid, u, v, k);
    update_val(id * 2 + 1, mid + 1, r, u, v, k);

    st_mrg(id, l, r);
}

void update_state(int id, int l, int r, int u, int v, int k) {
    if (r < u || v < l) return;

    if (u <= l && r <= v) {
        st_max[id][k] = st[id].total_max;
        longest_bl[id][k] = r - l + 1;
        left_bl[id][k] = right_bl[id][k] = st[id];
        st_max_value[id][k] = st[id].max_value;

        st_max[id][1 - k] = 0;
        longest_bl[id][1 - k] = 0;
        left_bl[id][1 - k] = right_bl[id][1 - k] = {0, 0, 0, 0, 0, - inf};
        st_max_value[id][1 - k] = - inf;

        lazy_state[id] = k;

        return;
    }

    int mid = (l + r) / 2;
    down(id, l, r);

    update_state(id * 2, l, mid, u, v, k);
    update_state(id * 2 + 1, mid + 1, r, u, v, k);

    st_mrg(id, l, r);
}

tuple<Block, Block, int, int> get_ans(int id, int l, int r, int u, int v, int k) {
    if (r < u || v < l) return make_tuple(Block{0, 0, 0, 0, 0, - inf}, Block{0, 0, 0, 0, 0, - inf}, 0, - inf);

    if (u <= l && r <= v) return make_tuple(left_bl[id][k], right_bl[id][k], st_max[id][k], st_max_value[id][k]);

    int mid = (l + r) / 2;
    down(id, l, r);
    auto t1 = get_ans(id * 2, l, mid, u, v, k);
    auto t2 = get_ans(id * 2 + 1, mid + 1, r, u, v, k);

    Block l_bl = get<0>(t1);
    Block r_bl = get<1>(t2);
    Block mid_bl = mrg(get<1>(t1), get<0>(t2));

    if (l_bl.len == mid - l + 1) l_bl = mid_bl;
    if (r_bl.len == r - mid) r_bl = mid_bl;

    return make_tuple(l_bl, r_bl, max(mid_bl.total_max, max(get<2>(t1), get<2>(t2))), max(get<3>(t1), get<3>(t2)));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("main.inp","r",stdin);
    freopen("main.ans","w",stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    build(1, 1, n);

    int t, l, r, x;

    while (q --) {
        cin >> t >> l >> r;

        if (t == 1) {
            update_state(1, 1, n, l, r, 0);
        } else if (t == 2) {
            update_state(1, 1, n, l, r, 1);
        } else if (t == 3) {
            cin >> x;
            update_val(1, 1, n, l, r, x);
        } else if (t == 4) {
            auto ans = get_ans(1, 1, n, l, r, 0);
            if (get<3>(ans) == - inf) cout << "breaks galore\n";
            else if (get<3>(ans) < 0) cout << get<3>(ans) << "\n";
            else cout << get<2>(ans) << "\n";
        } else {
            auto ans = get_ans(1, 1, n, l, r, 1);
            if (get<3>(ans) == - inf) cout << "breaks galore\n";
            else if (get<3>(ans) < 0) cout << get<3>(ans) << "\n";
            else cout << get<2>(ans) << "\n";
        }
    }

    return 0;
}