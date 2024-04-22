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

  string S;
  ll n;
  map<char, ll> freq;

  getline(cin, S);
  n = S.size();

  foreach (c, S)
    freq[c]++;

  ll n_swaps = (n * (n - 1)) / 2, k_swaps = 0, total_swaps, add = 0;

  foreach (kv, freq) {
    if (kv.se >= 2)
      add = 1;
    k_swaps += (kv.se * (kv.se - 1)) / 2;
  }

  total_swaps = n_swaps - k_swaps;

  cout << total_swaps + add << nl;

  return EXIT_SUCCESS;
}
