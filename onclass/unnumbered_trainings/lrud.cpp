#include <bits/stdc++.h>
#include <utility>

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

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  char c;
  pair<int, int> origin(0, 0);
  set<pair<int, int>> points = {origin};

  cin >> N;

  forexc(i, 0, N) {
    cin >> c;

    switch (c) {
    case 'R':
      origin = make_pair(origin.fi + 1, origin.se);
      points.insert(origin);
      break;
    case 'L':
      origin = make_pair(origin.fi - 1, origin.se);
      points.insert(origin);
      break;
    case 'U':
      origin = make_pair(origin.fi, origin.se + 1);
      points.insert(origin);
      break;
    case 'D':
      origin = make_pair(origin.fi, origin.se - 1);
      points.insert(origin);
      break;
    }
  }

  if (points.size() != N + 1)
    cout << "Yes" << nl;
  else
    cout << "No" << nl;

  return EXIT_SUCCESS;
}
