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

bool prime(int n) {
  if (n <= 1)
    return false;

  forinc(i, 2, sqrt(n)) if (n % i == 0) return false;

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n;
  cin >> t;

  while (t-- and cin >> n) {
    int i = n / 2, j = n / 2 + 1;
    bool found = false;

    while (i >= 1) {
      if (prime(i) or prime(j)) {
        --i;
        ++j;
        continue;
      }
      found = true;
      break;
    }

    if (found)
      cout << i << sp << j << nl;
    else
      cout << -1 << nl;
  }

  return 0;
}
