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

  string points = "ABCDEFG";
  map<char, int> dis = {{'A', 3}, {'B', 1}, {'C', 4},
                        {'D', 1}, {'E', 5}, {'F', 9}};

  char p, q;
  cin >> p >> q;

  if (p > q)
    swap(p, q);

  int d = 0;
  while (p != q) {
    d += dis[p];
    p = char(p + 1);
  }

  cout << d << nl;

  return EXIT_SUCCESS;
}