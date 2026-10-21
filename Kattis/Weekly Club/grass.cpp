#include <bits/stdc++.h>
using namespace std;

const double EXP = 1e-9;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
struct sp {
  int x, r;
  double top_l, top_r;
};

bool cmp(const sp& a, const sp& b) {
  if (fabs(a.top_l - b.top_l) > EXP) return a.top_l < b.top_l;
  return a.top_r > b.top_r;
}

bool solution() {
  int n, l, w;
  if (!(cin >> n >> l >> w)) return false;
  vector<sp> sprinklers(n);
  for (auto& it : sprinklers) {
    cin >> it.x >> it.r;
    double halfW = (double)w / 2.0;
    double spR = (double)it.r;
    if (spR < halfW) {
      it.top_l = it.top_r = spR;
    } else {
      double d = sqrt((spR * spR) - (halfW * halfW));
      it.top_r = it.x + d;
      it.top_l = it.x - d;
    }
  }
  sort(sprinklers.begin(), sprinklers.end(), cmp);

  // for (auto& it : sprinklers) cerr << it.top_l << ' ' << it.top_r << endl;

  double current = 0.0;
  int ans = 0;
  bool ok = true;
  for (int i = 0; (i < n) && ok; i++) {
    // cerr << sprinklers[i].top_l << ' ' << sprinklers[i].top_r << ' '
    //      << current + EXP << endl;
    if (current > l) break;
    if (sprinklers[i].top_r <= current + EXP) continue;
    if (sprinklers[i].top_l <= current && ok) {
      double max_r = -1;
      int newIdx = -1;
      for (int j = i; (j < n) && sprinklers[j].top_l <= current; j++) {
        // cerr << "++++++++++" << sprinklers[j].top_l << ' '
        //      << sprinklers[j].top_r << ' ' << current + EXP << endl;
        if (sprinklers[j].top_r > current && sprinklers[j].top_r > max_r) {
          max_r = sprinklers[j].top_r;
          newIdx = j;
        }
      }
      current = max_r;
      i = newIdx;
      ans++;
    } else
      ok = false;
  }
  if (current >= l && ok)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return true;
}

int main() {
  fastIO();
  while (solution());
  return 0;
}