#include <bits/stdc++.h>
#include <queue>

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
using p = pair<int, int>;

priority_queue<p, vector<p>, greater<p>> pq;

void dijkstra(int start, vector<vector<p>> &edges, vector<int> &vals,
              vector<bool> &vis) {
  vals[start] = 0;
  pq.push({0, start});

  while (not pq.empty()) {
    auto [val, u] = pq.top();
    pq.pop();
    vis[u] = true;

    for (auto &[v, w] : edges[u]) {
      if (not vis[v]) {
        int tmp = val + w;
        if (vals[v] == -1 or vals[v] > tmp) {
          vals[v] = tmp;
          pq.push({tmp, v});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, cases = 0;
  cin >> t;

  while (t--) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<p>> edges(n, vector<p>());
    vector<int> vals(n + 1, -1);
    vector<bool> vis(n + 1, false);

    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[u].pb({v, w});
      edges[v].pb({u, w});
    }

    dijkstra(s, edges, vals, vis);

    cout << "Case #" << ++cases << ": ";
    if (vals[t] == -1)
      cout << "unreachable" << nl;
    else
      cout << vals[t] << nl;
  }

  return 0;
}
