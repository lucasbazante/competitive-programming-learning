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

  vector<set<pair<int, int>>> bets(38);
  int n, c, bet, outcome, p_i = 1;

  cin >> n;
  while (n--) {
    cin >> c;
    forexc(i, 0, c) {
      cin >> bet;
      bets[bet].insert({c, p_i});
    }
    p_i++;
  }

  cin >> outcome;

  int prev = bets[outcome].begin()->fi;
  vector<int> least_winners;
  foreach (b, bets[outcome]) {
    if (b.fi == prev)
      least_winners.pb(b.se);
    else
      break;
    prev = b.fi;
  }

  cout << least_winners.size() << nl;
  foreach (w, least_winners)
    cout << w << sp;
  cout << nl;

  return EXIT_SUCCESS;
}
