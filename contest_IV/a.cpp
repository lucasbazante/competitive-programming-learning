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

void n_fill(set<string> &nums, int n, int h, string num) {
  if (h == 0) {
    nums.insert(num);
    return;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (num[i] == '0') {
      num[i] = '1';
      n_fill(nums, n - 1, h - 1, num);
      num[i] = '0';
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cin.ignore();

    int n, h;
    cin >> n >> h;

    set<string> nums;
    string x(n, '0');
    n_fill(nums, n, h, x);

    foreach (num, nums)
      cout << num << nl;

    cout << nl;
  }

  return EXIT_SUCCESS;
}
