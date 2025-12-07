#include <bits/stdc++.h>
using namespace std;

/**
 * Calculate the maximum height of the left bottom region for each possible
 * partion based on the x coordinate which has maximum max_cows cows
 * in the region.
 * @return bound[i] is the maximum possible height for the region 0..i,
 * 0..bound[i], in which the number of cows is less than or equal to max_cows
 */
vector<int> calc_max_height(int max_cows, const vector<pair<int, int>> &cows) {
	// total number of cows in the current region
	int sum = 0;
	// number of cows based on the y coordinates
	vector<int> count(cows.size());
	// the current maximum height for the region
	int y_bound = cows.size() - 1;
	// the maximum heights for the region based on the x partition
	vector<int> bound(cows.size());
	for (int x = 0, i = 0; x < cows.size(); x++) {
		while (i < cows.size() && cows[i].first == x) {
			int y = cows[i].second;
			count[y]++;
			// update the sum of cows in the active region
			if (y <= y_bound) { sum++; }
			i++;
		}
		/*
		 * if the maximum allowed number of cows in the region is exceeded,
		 * decrease the height of the region
		 */
		while (sum > max_cows) {
			sum -= count[y_bound];
			y_bound--;
		}
		bound[x] = y_bound;
	}
	return bound;
}

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.ans", "w", stdout);

	int N;
	cin >> N;
	vector<pair<int, int>> cows(N);
	for (pair<int, int> &c : cows) { cin >> c.first >> c.second; }

	// BeginCodeSnip{Coordinate Compression}
	//  compress x coordinates
	sort(cows.begin(), cows.end());
	int new_x = 0;
	int actual_x = cows[0].first;
	for (int i = 0; i < N; i++) {
		if (cows[i].first != actual_x) {
			new_x++;
			actual_x = cows[i].first;
		}
		cows[i].first = new_x;
	}

	// compress y coordinates
	sort(cows.begin(), cows.end(),
	     [&](const pair<int, int> &c1, const pair<int, int> &c2) {
		     return make_pair(c1.second, c1.first) < make_pair(c2.second, c2.first);
	     });
	int new_y = 0;
	int actual_y = cows[0].second;
	for (int i = 0; i < N; i++) {
		if (cows[i].second != actual_y) {
			new_y++;
			actual_y = cows[i].second;
		}
		cows[i].second = new_y;
	}
	// EndCodeSnip

	sort(cows.begin(), cows.end());
	int l = 1, h = N + 1;
	// binar search on the maximum of M
	while (l < h) {
		int mid = (h + l) / 2;
		bool possible = false;

		vector<int> west_south_height = calc_max_height(mid, cows);

		for (pair<int, int> &t : cows) { t.second = N - 1 - t.second; }
		vector<int> west_north_height = calc_max_height(mid, cows);

		reverse(cows.begin(), cows.end());
		for (pair<int, int> &t : cows) {
			t.first = N - 1 - t.first;
			t.second = N - 1 - t.second;
		}
		vector<int> east_south_height = calc_max_height(mid, cows);

		for (pair<int, int> &t : cows) { t.second = N - 1 - t.second; }
		vector<int> east_north_height = calc_max_height(mid, cows);

		// for each possible x partition
		for (int x = 0; x < N - 1; x++) {
			/*
			 * if the sum of the heights of the southern and northern regions is
			 * larger than the height of the farm, then there is one solution
			 * with the current maximum M, i.e. mid
			 */
			if (min(west_south_height[x], east_south_height[N - 2 - x]) + 1 +
			        min(west_north_height[x], east_north_height[N - 2 - x]) + 1 >=
			    N) {
				possible = true;
				break;
			}
		}

		if (possible) {
			h = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l << endl;
}
