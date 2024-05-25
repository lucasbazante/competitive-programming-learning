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

  int n, l, r;
  cin >> n;

  vector<pair<int, int>> pairs;
  while (n-- and cin >> l >> r)
    pairs.pb({l, -1}), pairs.pb({r, 1});

  sort(pairs.begin(), pairs.end());

  int count = 0, ans = 0;
  foreach (p, pairs) {
    if (p.se == -1)
      ++count;
    else
      ans += --count;
  }

  cout << ans << nl;

  return 0;
}
