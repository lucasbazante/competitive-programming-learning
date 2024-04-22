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

  int n, prev, i;

  cin >> n;
  cin >> prev;
  n--;
  cout << prev << sp;

  while (n-- and cin >> i) {

    if (abs(i - prev) == 1) {
      cout << i << sp;
      prev = i;
      continue;
    }

    if (prev < i)
      forinc(k, prev + 1, i - 1) cout << k << sp;
    else
      for (int k = prev - 1; k >= i + 1; k--)
        cout << k << sp;

    prev = i;
    cout << i << sp;
  }
  cout << nl;

  return EXIT_SUCCESS;
}
