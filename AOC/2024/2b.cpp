#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int a, b;
  vector<int> vec1;
  int ans = 0;

  int ctr = 0;

  while (getline(cin, str)) {
    int counter = 1;
    bool isTrue = true;
    stringstream ss(str);
    int a;

    while (ss >> a) {
      vec1.push_back(a);
    }
    bool isIncreasing = vec1[0] <= vec1[1];

    for (int i = 1; i < vec1.size(); i++) {
      //   cout << ctr << " " << vec1[i - 1] << " - " << vec1[i] << endl;
      if (abs(vec1[i - 1] - vec1[i]) > 3 ||
          ((vec1[i - 1] > vec1[i]) && isIncreasing) ||
          ((vec1[i - 1] < vec1[i]) && !isIncreasing) ||
          (vec1[i - 1] == vec1[i])) {
        // cout << ctr << " " << vec1[i - 1] << " - " << vec1[i] << endl;
        if (counter == 0) isTrue = false;
        counter--;
        i++;
        if ((abs(vec1[i - 1] - vec1[i + 1]) > 3 ||
             ((vec1[i - 1] > vec1[i + 1]) && isIncreasing) ||
             ((vec1[i - 1] < vec1[i + 1]) && !isIncreasing) ||
             (vec1[i - 1] == vec1[i + 1]))) {
          if ((i != 0 || i + 1 != (vec1.size() - 1))) isTrue = false;
        }
      }
      if (!isTrue) break;
    }

    if (isTrue) {
      ans++;
      cout << ctr << endl;
    }
    isTrue = true;
    vec1.clear();

    ctr++;
  }

  cout << " ANS: " << ans;

  return 0;
}