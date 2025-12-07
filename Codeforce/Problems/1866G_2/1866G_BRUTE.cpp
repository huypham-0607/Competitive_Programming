#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct range {
    ll start;
    ll end;
    ll count;
};

bool possible(const vector<range> &ranges, ll max_per_carriage) {
    int n = ranges.size();
    vector<range> curr_ranges = ranges;

    auto comp = [&](const int &left, const int &right) -> bool {
        return !(curr_ranges[left].end < curr_ranges[right].end);
    };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    int next_range = 0;
    for (int curr_pos = 0; curr_pos < n; curr_pos++) {
        while (next_range < n && curr_ranges[next_range].start <= curr_pos) {
            pq.push(next_range);
            next_range++;
        }

        ll curr_left = max_per_carriage;
        while (!pq.empty() && curr_left > 0) {
            int next = pq.top();
            pq.pop();
            if (!(curr_pos < curr_ranges[next].end)) continue;

            if (curr_ranges[next].count <= curr_left) {
                curr_left -= curr_ranges[next].count;
                curr_ranges[next].count = 0;
            } else {
                curr_ranges[next].count -= curr_left;
                curr_left = 0;
                pq.push(next);
            }

        }
    }

    for (int i = 0; i < n; i++)
        if (curr_ranges[i].count != 0) return false;

    return true;
}

int main() {
    freopen("1866G.inp","r",stdin);
    freopen("1866G.ans","w",stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> cnt(n);
    ll sum = 0;
    ll max_val = LLONG_MIN;
    for (auto &ref: cnt) {
        cin >> ref;
        sum += ref;
        max_val = max(max_val, ref);
    }

    vector<ll> max_dis(n);
    for (auto &ref: max_dis) cin >> ref;


    vector<range> ranges(n);
    for (int i = 0; i < n; i++)
        ranges[i] = {max(0ll, i - max_dis[i]), min(n, i + max_dis[i] + 1), cnt[i]};
    std::sort(ranges.begin(), ranges.end(), [](const range &left, const range &right) -> bool {
        return left.start < right.start;
    });


    ll start = sum / n;
    ll end = max_val + 1;
    while (start < end) {
        ll mid = start + (end - start) / 2;

        if (possible(ranges, mid))
            end = mid;
        else
            start = mid + 1;
    }

    cout << start;

}
