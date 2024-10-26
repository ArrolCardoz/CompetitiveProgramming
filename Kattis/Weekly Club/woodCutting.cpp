#include <bits/stdc++.h>
using namespace std;

void solution() {
  float numCustomer;
  cin >> numCustomer;
  float timeCustomer = 0;
  float totalTime = 0;

  vector<float> waitTime;
  for (int i = 0; i < numCustomer; i++) {
    int numWood;
    cin >> numWood;
    timeCustomer = 0;
    for (int j = 0; j < numWood; j++) {
      int n;
      cin >> n;

      timeCustomer += n;
      //   cout << "HI" << endl;
    }
    // cout << totalTime << " TOTAL" << endl;
    // cout << timeCustomer << " Customer" << endl;
    // totalTime += timeCustomer + totalTime;
    waitTime.push_back(timeCustomer);
  }
  sort(waitTime.begin(), waitTime.end());
  float sum = 0;
  for (auto &it : waitTime) {
    sum += it + totalTime;
    totalTime = it;
  }
  // cout << endl << sum << "/" << numCustomer << endl;

  float ans = sum / numCustomer;
  // if (numCustomer == 1)
  //   cout << sum << endl;
  // else
  cout << fixed << setprecision(12) << ans << endl;
  // cout << endl << sum << "/" << numCustomer << endl;
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    solution();
  }
  return 0;
}
