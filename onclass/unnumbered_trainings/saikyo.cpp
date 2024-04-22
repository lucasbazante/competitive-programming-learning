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

  int N, p_1, p, p_max{};

  cin >> N;
  cin >> p_1;

  N -= 1;

  while (N-- and cin >> p)
    p_max = p > p_max ? p : p_max;

  p_max = p_max - p_1 + 1;
  cout << (p_max >= 0 ? p_max : 0) << nl;

  return EXIT_SUCCESS;
}
