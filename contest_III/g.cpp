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
  int n, prev, curr;

  while (cin >> n) {
    bool jolly = true;
    int sz = n - 1;
    set<int> jumps;

    cin >> prev;
    n--;

    while (n--) {
      cin >> curr;

      if (abs(prev - curr) < 1 or abs(prev - curr) > sz)
        jolly = false;

      jumps.insert(abs(prev - curr));

      prev = curr;
    }

    if (jolly and (jumps.size() == sz))
      cout << "Jolly" << nl;
    else
      cout << "Not jolly" << nl;
  }

  return EXIT_SUCCESS;
}
