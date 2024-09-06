#include <bits/stdc++.h>
using namespace std;

void solution(vector<int>& low, vector<int>& high, int h, int n) {
  vector<int> answer;
  bool islow = true;
  int lowCounter = 0;
  int highCounter = 0;
  for (int i = 1; i <= h; i++) {
    while (low[lowCounter] < i && islow) lowCounter++;
    while (h - high[highCounter] < i) highCounter++;
    if (lowCounter >= low.size()) {
      islow = false;
      lowCounter = n;
    }
    answer.push_back(n - lowCounter + (highCounter));
    // cout << n - lowCounter << " +" << (highCounter) << endl;
  }

  // cout << "ANSWER" << endl;
  // for (auto& it : answer) cout << it << endl;
  int min, cont;
  min = *min_element(answer.begin(), answer.end());
  cont = count(answer.begin(), answer.end(), min);
  cout << min << " " << cont;
}

bool decend(int a, int b) {
  if (a > b) return true;
  return false;
}

int main() {
  vector<int> high, low;
  int n, h;
  cin >> n >> h;
  int numlow, numhigh;
  for (int i = 0; i < n / 2; i++) {
    cin >> numlow >> numhigh;
    high.push_back(numlow);
    low.push_back(numhigh);
  }

  sort(high.begin(), high.end(), decend);
  sort(low.begin(), low.end());
  // cout << "HIGH" << endl;
  // for (auto& it : high) cout << it << endl;
  // cout << "LOW" << endl;

  // for (auto& it : low) cout << it << endl;
  solution(low, high, h, n / 2);

  return 0;
}