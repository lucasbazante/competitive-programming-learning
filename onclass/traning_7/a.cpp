#include <bits/stdc++.h>
#include <unordered_map>

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

  int n, m, input;
  vector<ll> A, B, AB;
  unordered_map<ll, int> pos;

  cin >> n >> m;

  forexc(i, 0, n) {
    cin >> input;
    A.pb(input);
    AB.pb(input);
  }

  forexc(i, 0, m) {
    cin >> input;
    B.pb(input);
    AB.pb(input);
  }

  sort(AB.begin(), AB.end());

  foreach (a, A) {
    auto it = lower_bound(AB.begin(), AB.end(), a);
    cout << distance(AB.begin(), it) + 1 << sp;
  }
  cout << nl;
  foreach (b, B) {
    auto it = lower_bound(AB.begin(), AB.end(), b);
    cout << distance(AB.begin(), it) + 1 << sp;
  }
  cout << nl;

  return EXIT_SUCCESS;
}
