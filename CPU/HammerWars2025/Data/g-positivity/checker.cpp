#include "testlib.h"

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);

	int n = inf.readInt();
	auto a = inf.readIntegers(n);
	inf.readEoln();
	auto p = inf.readIntegers(n);
	for (int& x: p) x--;

	int k = ouf.readInt(0, INT_MAX, "k");
	if (k > n / 2) {
		quitf(_wa, "%d > floor(n/2) = %d operations", k, n / 2);
	}

	auto ops = ouf.readIntegers(k, 1, n, "x");
	for (int x : ops) {
		x--;
		a[x] = -a[x];
		a[p[x]] = -a[p[x]];
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] + a[p[i]] < 0) {
			quitf(_wa, "a_%d + a_%d = %d", i + 1, p[i] + 1, a[i] + a[p[i]]);
		}
	}

	quitf(_ok, ":)");
}