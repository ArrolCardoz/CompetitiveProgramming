#include <bits/stdc++.h>
using namespace std;

int solution() {
  map<int, int> cat;
  map<int, int> dog;
  map<int, int> catoriginal;
  map<int, int> dogoriginal;
  int first;

  int numcat, numdog, num;
  cin >> numcat >> numdog >> num;

  for (int i = 0; i < num; i++) {
    int votein, voteout;
    char charin, charout;
    first = votein;
    cin >> charin >> votein >> charout >> voteout;
    if (charin == 'C') {
      cat[votein]++;
      catoriginal[votein]++;

    } else {
      dog[votein]++;
      dogoriginal[votein]++;
    }

    if (charout == 'C') {
      cat[voteout]--;
    } else
      dog[voteout]--;
  }

  int counter = 0, ans = 0, zerocount = 0;
  for (auto it : cat) {
    if (it.second > 0) {
      ans += catoriginal[it.first];
      counter++;
    }
  }
  for (auto it : dog) {
    if (it.second > 0) {
      ans += dogoriginal[it.first];
      counter++;
    }
  }

  if (counter == 0) {
    if (catoriginal[first] > dogoriginal[first])
      ans = catoriginal[first];
    else
      ans = dogoriginal[first];
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << solution() << endl;
  }
  return 0;
}