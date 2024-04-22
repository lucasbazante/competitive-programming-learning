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

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, i{1};
  string S;
  bool A, B, C;
  A = B = C = false;

  getline(cin, S);
  getline(cin, S);

  foreach (c, S) {
    if (c == 'A')
      A = true;
    else if (c == 'B')
      B = true;
    else
      C = true;

    if (A and B and C)
      break;

    ++i;
  }

  cout << i << nl;

  return EXIT_SUCCESS;
}
