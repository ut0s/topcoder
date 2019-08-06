/**
  @date Time-stamp: <2019-08-06 21:57:18 tagashira>
  @file CrazyBot.cpp
  @brief
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, N) for (int i = 0; i < (N); ++i)

class CrazyBot {
  double prob[4];
  bool seen[50][50];

public:
  double getProbability(int n, int east, int west, int south, int north) {
    REP(i, 50) {
      REP(j, 50) {
        seen[i][j] = false;
      }
    }

    prob[0] = (double)east / 100.0;
    prob[1] = (double)west / 100.0;
    prob[2] = (double)south / 100.0;
    prob[3] = (double)north / 100.0;

    return dfs(25, 25, n);
  }

private:
  double dfs(int x, int y, int n) {
    if (seen[x][y]) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }

    seen[x][y] = true;
    double ret = 0;
    ret += prob[0] * dfs(x + 1, y, n - 1);
    ret += prob[1] * dfs(x - 1, y, n - 1);
    ret += prob[2] * dfs(x, y - 1, n - 1);
    ret += prob[3] * dfs(x, y + 1, n - 1);
    seen[x][y] = false;

    return ret;
  }
};

int main() {
  CrazyBot test;

  int N;
  cin >> N;
  int east, west, south, north;
  cin >> east >> west >> south >> north;

  cout << test.getProbability(N, east, west, south, north) << endl;
  return 0;
}
