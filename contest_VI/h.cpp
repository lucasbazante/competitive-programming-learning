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

  int n, x, inp;
  cin >> n >> x;

  vector<int> coins;
  forinc(i, 1, n) {
    cin >> inp;
    coins.pb(inp);
  }

  vector<int> dp(x + 1, 10000000);
  dp[0] = 0;

  forinc(i, 1, x) {
    vector<int> value = {10000000};
    foreach (c, coins)
      if (i - c >= 0)
        value.pb(dp[i - c] + 1);
    dp[i] = *min_element(value.begin(), value.end());
  }

  if (dp[x] == 10000000)
    cout << -1 << nl;
  else
    cout << dp[x] << nl;

  return 0;
}
