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

bool is_superior(pair<int, vector<int>> a, pair<int, vector<int>> b) {
  if (a.fi >= b.fi and
      includes(b.se.begin(), b.se.end(), a.se.begin(), a.se.end())) {
    if (a.fi > b.fi or a.se.size() < b.se.size())
      return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, p, c;
  vector<pair<int, vector<int>>> products;

  cin >> n >> m;
  while (n-- and cin >> p >> c) {
    vector<int> functions(c);

    forexc(j, 0, c) cin >> functions[j];
    products.push_back(make_pair(p, functions));
  }

  bool any = any_of(products.begin(), products.end(), [&products](auto &p_i) {
    return any_of(products.begin(), products.end(),
                  [&p_i](auto &p_j) { return is_superior(p_i, p_j); });
  });

  cout << (any ? "Yes" : "No") << nl;

  return EXIT_SUCCESS;
}
