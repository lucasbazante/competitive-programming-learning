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

struct edge {
  int a, b, cost;
};

bool bellman_ford(int n, int m, vector<edge> &edges) {
  vector<int> cost(n + 5);
  bool neg_cyc = false;

  cost[0] = 0;
  forexc(i, 1, n) cost[i] = 1e9;

  forexc(i, 0, n - 1)
      forexc(j, 0, m) if (cost[edges[j].b] > cost[edges[j].a] + edges[j].cost)
          cost[edges[j].b] = cost[edges[j].a] + edges[j].cost;

  forexc(i, 0, m) if (cost[edges[i].b] > cost[edges[i].a] + edges[i].cost)
      neg_cyc = true;

  return neg_cyc;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n, m;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    vector<edge> edges(m);
    forexc(i, 0, m) cin >> edges[i].a >> edges[i].b >> edges[i].cost;

    if (bellman_ford(n, m, edges))
      cout << "possible" << nl;
    else
      cout << "not possible" << nl;
  }

  return 0;
}
