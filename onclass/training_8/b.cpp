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

  int n;
  cin >> n;

  vector<int> squares(n + 1);
  vector<int> moves(n + 1, 0);
  forinc(i, 1, n) cin >> squares[i];

  int max_move = 0;
  for (int i = n - 1; i >= 1; i--) {
    if (squares[i] >= squares[i + 1]) {
      moves[i] = moves[i + 1] + 1;
      remax(max_move, moves[i]);
    }
  }

  cout << max_move << nl;

  return 0;
}
