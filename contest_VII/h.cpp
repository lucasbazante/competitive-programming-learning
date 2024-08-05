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
  cin >> n;

  vector<ll> x(n), y(n);
  forexc(i, 0, n) cin >> x[i] >> y[i];
  vector<vector<ll>> courses(n + 1, vector<ll>(2, -4e18));
  courses[0][0] = 0;

  for (ll i = 0; i < n; ++i) {
    if (x[i] == 0)
      courses[i + 1][0] =
          max(courses[i][0], max(courses[i][0], courses[i][1]) + y[i]);
    else
      courses[i + 1][1] = max(courses[i][1], courses[i][0] + y[i]);

    courses[i + 1][0] = max(courses[i + 1][0], courses[i][0]);
    courses[i + 1][1] = max(courses[i + 1][1], courses[i][1]);
  }

  cout << max(courses[n][0], courses[n][1]) << nl;
  return 0;
}
