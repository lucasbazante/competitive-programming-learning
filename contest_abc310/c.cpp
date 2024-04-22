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

  int n, i = 0;
  string s;
  cin >> n;
  cin.ignore();

  auto eq_rev = [](string x, string y) {
    if (x.size() == y.size() and x == y)
      return false;
    reverse(x.begin(), x.end());
    return x != y;
  };

  set<string, decltype(eq_rev)> strings;

  while (n-- and getline(cin, s))
    strings.insert(s);

  cout << strings.size() << nl;

  return EXIT_SUCCESS;
}
