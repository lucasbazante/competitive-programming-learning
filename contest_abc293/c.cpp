#include <bits/stdc++.h>

#define foreach(e, comp) for (auto &e : comp)
#define forinc(i, a, b) for (int i{a}; i <= b; ++i)
#define forexc(i, a, b) for (int i{a}; i < b; ++i)
#define remax(a, b) (a) = max((a), (b))
#define remin(a, b) (a) = min((a), (b))
#define fi first
#define se second
#define pb push_back
#define nl "\n"
#define sp " "
#define in(e, comp) (comp.find(e) != comp.end())
#define instr(c, str) (str.find(c) != string::npos)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
template <class T> using Matrix = vector<vector<T>>;

vector<int> path;
Matrix<int> paths;

void solve(Matrix<int> grid, int i, int j) {
  int N = grid.size(), M = grid[0].size();

  if (i >= N or j >= M)
    return;

  path.push_back(grid[i][j]);

  if (i == N - 1 and j == M - 1) {
    paths.push_back(path);
    path.pop_back();
    return;
  }

  if (i < N)
    solve(grid, i + 1, j);

  if (j < M)
    solve(grid, i, j + 1);

  path.pop_back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  uint H, W, total = 0;

  cin >> H >> W;
  Matrix<int> grid(H, vector<int>(W));

  forexc(y, 0, H) forexc(x, 0, W) cin >> grid[y][x];

  solve(grid, 0, 0);

  foreach (p, paths) {
    unordered_set<int> val(p.begin(), p.end());
    total += val.size() == p.size() ? 1 : 0;
  }

  cout << total << nl;

  return EXIT_SUCCESS;
}
