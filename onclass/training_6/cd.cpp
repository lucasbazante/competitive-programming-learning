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
template <typename Key, typename Val> using umap = unordered_map<Key, Val>;

int N, t, best = 0;
void solve(vector<int> cds, vector<int> tracks, umap<int, bool> used,
           umap<int, vector<int>> &tape) {
  auto track_sum = accumulate(tracks.begin(), tracks.end(), 0);

  if (track_sum == N or tracks.size() >= t)
    return;

  foreach (cd, cds) {
    if (used[cd] || track_sum + cd > N || in(track_sum + cd, tape))
      continue;

    remax(best, track_sum + cd);

    tracks.pb(cd);
    used[cd] = true;
    tape[track_sum + cd] = tracks;

    solve(cds, tracks, used, tape);

    tracks.pop_back();
    used[cd] = false;
  }
}

int main() {
  while (cin >> N >> t) {
    vector<int> cds(t), tracks;
    umap<int, bool> used;
    umap<int, vector<int>> tape;

    forexc(i, 0, t) cin >> cds[i], used[cds[i]] = false;

    solve(cds, tracks, used, tape);

    foreach (track, tape[best])
      cout << track << sp;
    cout << "sum:" << best << nl;

    best = 0;
  }
  return EXIT_SUCCESS;
}
