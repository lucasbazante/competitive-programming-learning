#include <bits/stdc++.h>
#include <stack>

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

  int n, m;
  cin >> n >> m;

  int a, b;
  vector<vector<int>> adj(n + 1);
  // vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

  forinc(i, 1, m) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  queue<int> route;
  vector<int> visited(n + 1, 0);

  route.push(1);
  visited[1] = 1;

  while (not route.empty()) {
    int k = route.front();
    route.pop();

    foreach (neigh, adj[k]) {
      if (visited[neigh] == 0) {
        visited[neigh] = k;
        route.push(neigh);
      }
    }
  }

  if (visited[n] == 0) {
    cout << "IMPOSSIBLE" << nl;
    return 0;
  }

  int end = n;
  stack<int> path;
  path.push(n);

  while (end != 1) {
    path.push(visited[end]);
    end = visited[end];
  }

  cout << path.size() << nl;
  while (not path.empty()) {
    cout << path.top() << " ";
    path.pop();
  }
  cout << nl;

  return 0;
}
