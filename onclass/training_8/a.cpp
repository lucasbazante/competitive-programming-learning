#include <bits/stdc++.h>
#include <limits>

using namespace std;

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, h;
  cin >> n;

  vector<int> stones(n + 1);
  vector<int> jumps(n + 1, numeric_limits<int>::max());
  forinc(i, 1, n) cin >> stones[i];

  jumps[1] = 0, jumps[2] = abs(stones[1] - stones[2]);
  forinc(i, 3, n) {
    int cost_1 = jumps[i - 1] + abs(stones[i - 1] - stones[i]);
    int cost_2 = jumps[i - 2] + abs(stones[i - 2] - stones[i]);
    jumps[i] = min(cost_1, cost_2);
  }

  cout << jumps[n] << nl;

  return 0;
}
