#include "bits/stdc++.h"
#include "testlib.h"

using namespace std;

#define ll long long

int readAns(int n, vector<vector<int>> g1, vector<vector<int>> g2, InStream& stream) {
  
  int moves = stream.readInt(-1, n * n, "k");

  if (moves == -1) return 0;

  int flip = 0;
  for (int i = 0; i < moves; i++) {

    int ty = stream.readInt(1, 2, "type");

    if (ty == 1) {

      int x = stream.readInt(1, n, "x");
      int y = stream.readInt(1, n, "y");
      int z = stream.readInt(1, n, "z");

      if (x == y || y == z || x == z) {
        stream.quitf(_wa, "x, y, z must be distinct");
      }

      x--; y--; z--;

      if (g1[x][y] == flip) {
        stream.quitf(_wa, "there is no edge between x, y");
      }
      if (g1[y][z] == flip) {
        stream.quitf(_wa, "there is no edge between y, z");
      }
      if (g1[x][z] != flip) {
        stream.quitf(_wa, "there is an edge between x, z");
      }

      g1[x][z] ^= 1;
      g1[z][x] ^= 1;


    }
    else {
      flip ^= 1;
    }

  }  

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      g1[i][j] ^= flip;
    }
  }

  if (g1 != g2) {
    stream.quitf(_wa, "G1 and G2 are not equal at the end");
  }

  return 1;

}

int main(int argc, char* argv[]) {

  registerTestlibCmd(argc, argv);

  int t = inf.readInt();
  for (int tt = 1; tt <= t; tt++) {

    setTestCase(tt);

    int n = inf.readInt();

    vector<vector<int>> g1(n, vector<int>(n));
    vector<vector<int>> g2 = g1;

    for (int it = 0; it < 2; it++) {
      for (int i = 0; i < n; i++) {
        string s = inf.readToken();
        for (int j = 0; j < n; j++) {
          g1[i][j] = (s[j] == '1');
        }
      }
      swap(g1, g2);
    }

    int pans = readAns(n, g1, g2, ouf);
    int jans = readAns(n, g1, g2, ans);

    if (pans != jans) {
      if (pans) quitf(_fail, "uh oh");
      else quitf(_wa, "jury has solution but participant does not");
    }

  }
  quitf(_ok, "good job");
  
}