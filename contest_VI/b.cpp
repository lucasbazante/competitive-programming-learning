#include <bits/stdc++.h>

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

  int n, h, k;
  cin >> n >> k;

  vector<int> stones(n + 1);
  vector<int> jumps(n + 1, numeric_limits<int>::max());
  forinc(i, 1, n) cin >> stones[i];

  jumps[1] = 0, jumps[2] = abs(stones[1] - stones[2]);
  forinc(i, 3, n) {
    vector<int> costs;
    int start = (i - k >= 1) ? i - k : 1;
    for (int j = start; j < i; j++)
      costs.pb(abs(stones[i] - stones[j]) + jumps[j]);
    jumps[i] = *min_element(costs.begin(), costs.end());
  }

  cout << jumps[n] << nl;

  return 0;
}
