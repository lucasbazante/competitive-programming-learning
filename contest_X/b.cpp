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
using image = vector<vector<int>>;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(image &img, int i, int j) {
  img[i][j] = 0;

  int size = img.size();
  forexc(k, 0, 8) {
    int ti = i + di[k], tj = j + dj[k];

    if (ti < 0 or ti >= size or tj < 0 or tj >= size)
      continue;
    if (img[ti][tj] == 1)
      dfs(img, ti, tj);
  }
}

int main() {
  int cases = 1, n;

  while (cin >> n) {
    cin.ignore();

    string line;
    image img(n, vector<int>(n));

    forexc(i, 0, n) {
      getline(cin, line);
      forexc(j, 0, n) img[i][j] = line[j] - '0';
    }

    int connected_components = 0;
    forexc(i, 0, n) {
      forexc(j, 0, n) {
        if (img[i][j] == 1) {
          ++connected_components;
          dfs(img, i, j);
        }
      }
    }

    cout << "Image number " << cases++ << " contains " << connected_components
         << " war eagles." << nl;
  }

  return 0;
}
