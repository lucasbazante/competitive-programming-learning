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

  int n, q, l, r, inp;
  enum Sleep { sleeping, awake };
  auto cmp = [](const pair<int, Sleep> &i, const pair<int, Sleep> &j) {
    return i.fi < j.fi;
  };

  cin >> n;
  multiset<pair<int, Sleep>, decltype(cmp)> log(cmp);
  forinc(i, 1, n) {
    cin >> inp;
    log.insert({inp, (i % 2 == 0 ? sleeping : awake)});
  }

  cin >> q;
  while (q-- and cin >> l >> r) {
    ll sum = 0, prev = l;
    auto lb = log.lower_bound(make_pair(l, awake)),
         ub = log.upper_bound(make_pair(r, awake));

    while (lb != ub) {
      if (lb->se == awake)
        sum += lb->fi - prev;
      prev = lb->fi;
      lb++;
    }

    if (lb->se == awake)
      sum += min(lb->fi, r) - prev;

    cout << sum << nl;
  }

  return EXIT_SUCCESS;
}
