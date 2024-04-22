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

  ll n, k, num;
  cin >> n >> k;

  ll sum = k * (k + 1) / 2;
  unordered_set<ll> seen;

  while (n-- and cin >> num) {
    if (num <= k) {
      if (!seen.contains(num)) {
        sum -= num;
        seen.insert(num);
      }
    }
  }

  cout << sum << nl;

  return EXIT_SUCCESS;
}
