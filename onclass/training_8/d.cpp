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

  int m, n, t;
  while (cin >> m >> n >> t) {
    vector<int> minutes(t + 1, -1);
    minutes[t] = 0;

    for (int i = t; i >= 0; i--) {
      if (minutes[i] == -1)
        continue;
      else if (i - m >= 0)
        minutes[i - m] = max(minutes[i - m], minutes[i] + 1);
      if (i - n >= 0)
        minutes[i - n] = max(minutes[i - n], minutes[i] + 1);
    }

    if (minutes[0] != -1) {
      cout << minutes[0] << nl;
    } else {
      for (int i = 1; i <= t; i++)
        if (minutes[i] != -1) {
          cout << minutes[i] << sp << i << nl;
          break;
        }
    }
  }

  return 0;
}
