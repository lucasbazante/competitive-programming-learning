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

  int n, q, t, x;
  char c;
  vector<pair<int, char>> str;

  cin >> n;
  cin.ignore();

  forexc(i, 0, n) {
    cin >> c;
    str.pb({0, c});
  }

  pair<int, int> last = {-1, -1};
  cin >> q;
  forexc(i, 0, q) {
    cin >> t >> x >> c;
    switch (t) {

    case 1: {
      str[x - 1] = {i, c};
      break;
    }

    case 2: {
      last = {i, 2};
      break;
    }

    case 3: {
      last = {i, 3};
      break;
    }
    }
  }

  foreach (s, str) {
    if (last.fi == -1 or s.fi > last.fi)
      cout << s.se;
    else if (last.se == 2)
      cout << (char)tolower(s.se);
    else
      cout << (char)toupper(s.se);
  }

  cout << nl;

  return EXIT_SUCCESS;
}
