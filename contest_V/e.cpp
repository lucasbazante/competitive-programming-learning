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
  string s;
  vector<string> strings;

  cin >> n;
  cin.ignore();
  forexc(i, 0, n) {
    getline(cin, s);
    strings.pb(s);
  }

  auto palind = [](string s) {
    forexc(i, 0, s.size() / 2) if (s[i] != s[s.size() - i - 1]) return false;
    return true;
  };

  forexc(i, 0, n) {
    forexc(j, i + 1, n) {
      if (palind(strings[i] + strings[j]) or palind(strings[j] + strings[i])) {
        cout << "Yes" << nl;
        return 0;
      }
    }
  }

  cout << "No" << nl;

  return EXIT_SUCCESS;
}
