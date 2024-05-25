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

  int n, t, ti, d = 0, antid = 0;
  cin >> n >> t;

  vector<int> row(n), col(n);

  forinc(turn, 1, t) {
    cin >> ti;
    ti--;

    int i = ti / n, j = ti % n;

    auto inc = [&](int &v) {
      if (++v == n) {
        cout << turn << nl;
        exit(0);
      }
    };

    inc(row[i]);
    inc(col[j]);

    if (i == j)
      inc(d);
    if (i + j == n - 1)
      inc(antid);
  }

  cout << -1 << nl;

  return 0;
}
