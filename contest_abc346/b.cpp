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
#define instr(c, str) (str.find(c) != string::npos)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, b;
  string piano = "wbwbwwbwbwbw";
  cin >> w >> b;

  auto rep = [piano](int times) {
    string rep = piano;
    while (times--)
      rep += piano;

    return rep;
  };

  if (w + b > 12) {
    int factor = (w + b) / 12;
    int times = 12 * factor >= w + b ? factor : factor + 1;
    piano = rep(times);
  }

  forexc(i, w + b, piano.length()) {
    int begin = i - (w + b);
    string subs = piano.substr(begin, i - begin);

    int cw = count(subs.begin(), subs.end(), 'w'),
        cb = count(subs.begin(), subs.end(), 'b');

    if (cw == w and cb == b) {
      cout << "Yes" << nl;
      return EXIT_SUCCESS;
    }
  }

  cout << "No" << nl;

  return EXIT_SUCCESS;
}
