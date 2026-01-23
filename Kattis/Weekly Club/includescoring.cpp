#include <bits/stdc++.h>
using namespace std;
struct contestant {
  int problems = 0, timePenalty = 0, time = 0;
  int onSite;
  int tied = 0;
  int order;
  int finalScore = 0;
};
bool operator==(const contestant& a, const contestant& b) {
  return a.problems == b.problems && a.timePenalty == b.timePenalty &&
         a.time == b.time;
}

bool operator!=(const contestant& a, const contestant& b) { return !(a == b); }

bool operator<(contestant& a, contestant& b) {
  if (a == b) {
    a.tied = 1;
    b.tied = 1;
  }
  if (a.problems != b.problems) return a.problems > b.problems;
  if (a.timePenalty != b.timePenalty) return a.timePenalty < b.timePenalty;
  return a.time < b.time;
}

int pointsDistribution[30] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26,
                              24,  22, 20, 18, 16, 15, 14, 13, 12, 11,
                              10,  9,  8,  7,  6,  5,  4,  3,  2,  1};

void handleTie(queue<int>& tiedRank, queue<int>& tiedOrder,
               vector<contestant>& contestants, vector<int>& idx) {
  if (tiedRank.empty()) return;
  // cerr << "TIED SIZE: " << tiedRank.size() << endl;
  int total = 0;
  int tiedNum = tiedRank.size();

  // Sum points for tied ranks
  while (!tiedRank.empty()) {
    int r = tiedRank.front();
    tiedRank.pop();
    if (r < 30) total += pointsDistribution[r];
  }

  // Ceiling average
  total = (total + tiedNum - 1) / tiedNum;

  // Assign score
  while (!tiedOrder.empty()) {
    int ord = tiedOrder.front();
    tiedOrder.pop();

    int pos = idx[ord];
    contestants[pos].finalScore = total;
    if (contestants[pos].onSite) contestants[pos].finalScore++;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);

  vector<contestant> contestants(n);
  queue<int> tiedRank, tiedOrder;
  bool tiedFlag = false;
  contestant cerrTied;
  int ctr = 0;
  for (auto& it : contestants) {
    cin >> it.problems >> it.timePenalty >> it.time >> it.onSite;
    it.order = ctr;
    ctr++;
  }
  sort(contestants.begin(), contestants.end());
  ctr = 0;
  for (auto& it : contestants) {
    cerr << it.problems << it.timePenalty << it.time << it.onSite << it.tied
         << endl;
  }

  for (auto& it : contestants) {
    idx[it.order] = ctr;
    if (it.tied) {
      if (cerrTied != it && tiedFlag) {
        handleTie(tiedRank, tiedOrder, contestants, idx);
        tiedFlag = false;
      }
      // calculate tied points
      // cerr << "TRSGIRSGHIRSHGOIRHG" << endl;
      cerrTied = it;
      tiedRank.push(ctr);
      tiedOrder.push(it.order);

      tiedFlag = true;
    } else {
      if (tiedFlag) {
        handleTie(tiedRank, tiedOrder, contestants, idx);
        tiedFlag = false;
      }

      // process the current not tied contestant
      if (ctr < 30) it.finalScore = pointsDistribution[ctr];
    }
    // check if they are in person or not
    if (it.onSite) it.finalScore++;
    // update the order idx of the contestants
    ctr++;
  }
  // process if not process the tied ranks

  int tiedNum = tiedRank.size();
  // get the ranks
  if (tiedNum) {
    handleTie(tiedRank, tiedOrder, contestants, idx);
  }
  // cerr << "LOOP?4" << endl;

  for (auto& i : idx) {
    // cerr << "LOOP?5" << endl;
    cout << contestants[i].finalScore << endl;
  }

  return 0;
}