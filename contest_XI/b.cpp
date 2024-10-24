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

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int dfs(vector<string> &graph, char hole_id, int i, int j) {
  graph[i][j] = '.';
  int count = 1;

  forexc(k, 0, 4) {
    int ti = i + di[k], tj = j + dj[k];

    if (ti < 0 or ti >= graph.size() or tj < 0 or tj >= graph[0].size())
      continue;

    if (graph[ti][tj] == hole_id)
      count += dfs(graph, hole_id, ti, tj);
  }

  return count;
}

int main() {
  int x, y, problem = 1;

  while (cin >> x >> y) {
    cin.ignore();

    if (x == 0 and y == 0)
      break;

    vector<string> graph(x);
    vector<pair<char, int>> holes;
    forexc(i, 0, x) getline(cin, graph[i]);

    forexc(i, 0, x) forexc(j, 0, y) if (graph[i][j] != '.') {
      char hole_id = graph[i][j];
      holes.pb({hole_id, dfs(graph, hole_id, i, j)});
    }

    sort(holes.begin(), holes.end(),
         [](const pair<char, int> &l, const pair<char, int> &r) {
           if (l.se == r.se)
             return l.fi < r.fi;
           return l.se > r.se;
         });

    cout << "Problem " << problem++ << ":" << nl;
    foreach (hole, holes)
      cout << hole.fi << sp << hole.se << nl;
  }

  return 0;
}
