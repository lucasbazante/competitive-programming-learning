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

  int n, n_cp, m, k, food;
  map<int, int> likes;
  cin >> n >> m;
  n_cp = n;

  forinc(i, 1, m) likes[i] = 0;

  while (n-- and cin >> k)
    while (k-- and cin >> food)
      likes[food]++;

  int count = 0;
  forinc(i, 1, m) if (likes[i] == n_cp) count++;

  cout << count << nl;

  return EXIT_SUCCESS;
}
