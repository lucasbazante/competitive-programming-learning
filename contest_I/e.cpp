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

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, p, prev{0}, pairs{0};
  map<int, set<int>> ngb;

  cin >> N >> M;

  forexc(i, 0, M) {
    forexc(j, 0, N) {
      cin >> p;
      if (prev != 0) {
        ngb[prev].insert(p);
        ngb[p].insert(prev);
      }
      prev = p;
    }
    prev = 0;
  }

  foreach (p, ngb)
    forinc(i, 1, N) if (i != p.fi and !in(i, p.se))++ pairs;

  cout << pairs / 2 << nl;

  return EXIT_SUCCESS;
}
