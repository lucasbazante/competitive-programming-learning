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
using image = vector<string>;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(image &img, int i, int j) {
  img[i][j] = '0';
  int count = 1;

  forexc(k, 0, 8) {
    int ti = i + di[k], tj = j + dj[k];

    if (ti < 0 or ti >= img.size() or tj < 0 or tj >= img[0].size())
      continue;

    if (img[ti][tj] == '1')
      count += dfs(img, ti, tj);
  }

  return count;
}

int main() {
  int t;
  string line;

  cin >> t;
  cin.ignore();
  cin.ignore();

  while (t--) {
    image img;

    while (getline(cin, line)) {
      if (line.empty())
        break;
      img.pb(line);
    }

    int max_con = 0;
    forexc(i, 0, img.size()) forexc(j, 0, img[0].size()) if (img[i][j] == '1')
        remax(max_con, dfs(img, i, j));

    if (t != 0)
      cout << max_con << nl << nl;
    else
      cout << max_con << nl;
  }

  return 0;
}
