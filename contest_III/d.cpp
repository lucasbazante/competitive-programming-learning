#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
#include <unordered_set>

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

  string str;
  bool upper = false, lower = false;
  unordered_set<char> seen;

  getline(cin, str);

  foreach (c, str) {
    if (seen.contains(c)) {
      cout << "No" << nl;
      return EXIT_SUCCESS;
    }

    seen.insert(c);

    if (islower(c))
      lower = true;
    else
      upper = true;
  }

  if (lower and upper)
    cout << "Yes" << nl;
  else
    cout << "No" << nl;

  return EXIT_SUCCESS;
}
