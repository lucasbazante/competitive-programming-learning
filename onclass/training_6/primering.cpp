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

bool prime(int n) {
  if (n <= 1)
    return false;

  forinc(i, 2, n / 2) if (n % i == 0) return false;

  return true;
}

void solve(vector<int> ring, vector<bool> used, int n) {
  if (ring.size() == n and prime(ring[n - 1] + ring[0])) {
    foreach (r, ring)
      cout << r << (r == ring.back() ? "" : sp);
    cout << nl;
    return;
  }

  forinc(i, 2, n) {
    if (used[i])
      continue;

    if (prime(ring.back() + i)) {
      used[i] = true;
      ring.pb(i);

      solve(ring, used, n);

      used[i] = false;
      ring.pop_back();
    }
  }
}

int main() {
  int n, i = 1;

  while (cin >> n) {
    vector<int> ring = {1};
    vector<bool> used(17, false);

    if (i > 1)
      cout << nl;

    cout << "Case " << i << ":" << nl;
    solve(ring, used, n);
    ++i;
  }

  return EXIT_SUCCESS;
}
