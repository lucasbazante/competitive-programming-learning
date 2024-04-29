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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, p;
  cin >> n >> m;

  multiset<int, greater<int>> prices;
  while (n-- and cin >> p)
    prices.insert(p);

  while (m-- and cin >> p) {
    auto it = prices.lower_bound(p);
    if (it == prices.end()) {
      cout << -1 << nl;
    } else {
      cout << *it << nl;
      prices.erase(it);
    }
  }

  return EXIT_SUCCESS;
}
