#include <bits/stdc++.h>

using namespace std;

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

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  char inp;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n, 0));

  forexc(i, 0, n) {
    forexc(j, 0, n) {
      cin >> inp;

      if (i == 0) {
        if (j < n - 1)
          grid[i][j + 1] = inp;
        else if (j == n - 1)
          grid[i + 1][j] = inp;
      } else if (i == n - 1) {
        if (j > 0)
          grid[i][j - 1] = inp;
        else if (j == 0)
          grid[i - 1][j] = inp;
      } else {
        if (j == 0)
          grid[i - 1][j] = inp;
        else if (j == n - 1)
          grid[i + 1][j] = inp;
        else
          grid[i][j] = inp;
      }
    }
  }

  foreach (line, grid) {
    foreach (elem, line)
      cout << elem;
    cout << nl;
  }

  return 0;
}
