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

  int n;
  string str;

  while (cin >> n >> str) {
    unordered_map<string, ll> freqs;

    forinc(i, n, str.length()) {
      int begin = i - n;
      string subs = str.substr(begin, i - begin);

      if (in(subs, freqs))
        freqs[subs]++;
      else
        freqs[subs] = 0;
    }

    ll max = 0;
    string max_s;
    foreach (p, freqs) {
      if (max < p.second) {
        max = p.second;
        max_s = p.first;
      }
    }

    cout << max_s << nl;
  }

  return 0;
}
