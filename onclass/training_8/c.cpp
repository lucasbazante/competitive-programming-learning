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

  int n, a, b, c;
  cin >> n;

  vector<vector<int>> dp(n + 1, vector<int>(3, 0));
  forinc(i, 1, n) {
    cin >> a >> b >> c;

    dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]),
    dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]),
    dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << nl;

  return 0;
}
