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

  int n, m, q;
  cin >> n >> m;

  vector<int> arr(n + 1);
  forinc(i, 1, n) cin >> arr[i];

  unordered_set<int> seen({arr[n]});
  vector<int> query(n + 1, 1);

  for (int i = n - 1; i > 0; i--) {
    if (not in(arr[i], seen))
      query[i] = query[i + 1] + 1, seen.insert(arr[i]);
    else
      query[i] = query[i + 1];
  }

  while (m-- and cin >> q)
    cout << query[q] << nl;

  return 0;
}
