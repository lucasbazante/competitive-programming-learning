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

static const int INF = 100000;

int main() {
  int t;
  cin >> t;

  forinc(cases, 1, t) {
    int b, r, x, y, m = 0;
    cin >> b >> r;

    vector<vector<int>> graph(b, vector<int>(b, INF));

    forexc(i, 0, r) {
      cin >> x >> y;
      graph[x][y] = 1, graph[y][x] = 1;
    }

    forexc(i, 0, b) graph[i][i] = 0;

    forexc(k, 0, b) forexc(i, 0, b) forexc(j, 0, b)
        remin(graph[i][j], graph[i][k] + graph[k][j]);

    cin >> x >> y;
    forexc(i, 0, b) remax(m, graph[x][i] + graph[i][y]);

    cout << "Case " << cases << ": " << m << nl;
  }

  return 0;
}
