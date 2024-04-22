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

  int n;
  string s, t;

  cin >> n;
  cin.ignore();
  getline(cin, s);
  getline(cin, t);

  auto similar = [](char x, char y) {
    if (x == y)
      return true;
    else if (x == '1' and y == 'l' or x == 'l' and y == '1')
      return true;
    else if (x == '0' and y == 'o' or x == 'o' and y == '0')
      return true;
    else
      return false;
  };

  forexc(i, 0, n) {
    if (not similar(s[i], t[i])) {
      cout << "No" << nl;
      return 0;
    }
  }

  cout << "Yes" << nl;

  return EXIT_SUCCESS;
}
