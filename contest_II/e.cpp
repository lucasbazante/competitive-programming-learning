#include <bits/stdc++.h>
#include <cstdlib>

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

  int n, m, h, k;
  pair<int, int> tk_pos(0, 0);
  string moves;
  set<pair<int, int>> hp_items;

  cin >> n >> m >> h >> k;
  cin.ignore();
  getline(cin, moves);

  int x, y;
  while (m-- and cin >> x >> y)
    hp_items.insert(make_pair(x, y));

  foreach (mv, moves) {
    switch (mv) {
    case 'R':
      tk_pos.fi++;
      break;
    case 'L':
      tk_pos.fi--;
      break;
    case 'U':
      tk_pos.se++;
      break;
    case 'D':
      tk_pos.se--;
      break;
    }

    h--;
    if (h < 0) {
      cout << "No" << nl;
      return EXIT_SUCCESS;
    }

    if (h < k) {
      auto hp_it = hp_items.find(tk_pos);
      if (hp_it != hp_items.end()) {
        h = k;
        hp_items.erase(hp_it);
      }
    }
  }

  cout << "Yes" << nl;

  return EXIT_SUCCESS;
}
