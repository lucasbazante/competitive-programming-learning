#include <bits/stdc++.h>
#include <unordered_set>

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

  int n, m, inp;
  cin >> n >> m;

  unordered_set<int> a;
  vector<int> c;

  while (n-- and cin >> inp)
    a.insert(inp), c.pb(inp);
  while (m-- and cin >> inp)
    c.pb(inp);

  sort(c.begin(), c.end());

  for (int i = 0; i <= c.size() - 1; i++) {
    if (in(c[i], a) and in(c[i + 1], a)) {
      cout << "Yes" << nl;
      return 0;
    }
  }

  cout << "No" << nl;

  return 0;
}
