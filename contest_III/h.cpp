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

  ll n, k, a, b, pills = 0;
  vector<pair<ll, ll>> presc;

  cin >> n >> k;
  while (n-- and cin >> a >> b)
    presc.push_back({a, b}), pills += b;

  sort(presc.begin(), presc.end());

  int days = 1;
  foreach (med, presc) {
    if (pills <= k)
      break;
    days = med.fi + 1;
    pills -= med.se;
  }

  cout << days << nl;

  return EXIT_SUCCESS;
}
