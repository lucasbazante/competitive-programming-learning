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

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, m{};
  string S, X, Y;

  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, S);

  forexc(i, 1, N) {
    set<char> seen;
    int count{};

    X = S.substr(0, i);
    Y = S.substr(i, N);

    foreach (c, X) {
      if (!in(c, seen) and instr(c, Y))
        ++count;
      seen.insert(c);
    }

    remax(m, count);
  }

  cout << m << nl;

  return EXIT_SUCCESS;
}
