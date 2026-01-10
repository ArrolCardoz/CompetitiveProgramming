#include <bits/stdc++.h>
using namespace std;

int cycle(vector<int>& arr2, vector<bool>& visited, int idx) {
  int e = idx;
  int counter = 0;
  visited[idx] = true;

  do {
    idx = arr2[idx];
    counter++;
    visited[idx] = true;
  } while (idx != e);
  return counter;
}

void shuffle(int& num, string& mode) {
  vector<int> arr1(num, 0);
  vector<int> arr2;
  arr2.reserve(num);
  unordered_map<int, int> idx;
  // cerr << num << endl;
  for (int i = 0; i < num; i++) {
    arr1[i] = i;
  }

  int p1 = 0, p2 = (num + 1) / 2;
  if (mode == "in") {
    p2 = num / 2;
    swap(p1, p2);
  }
  for (int i = 0; i * 2 < num - 1; i++) {
    arr2.push_back(arr1[p1]);
    arr2.push_back(arr1[p2]);
    p1++;
    p2++;
  }

  if (num & 1) {
    arr2.push_back(arr1[p1]);
    arr2.push_back(arr1[p2]);
  } else {
    if (mode == "in")
      arr2.push_back(arr1[p1]);
    else
      arr2.push_back(arr1[p2]);
  }

  // for (int i = 0; i < num; i++) {
  //   cerr << arr2[i] << ' ';
  // }
  // cerr << endl;
  vector<bool> visited(num, false);
  int maxCycle = 0;
  for (int i = 0; i < num; i++) {
    if (!visited[i]) {
      int temp = cycle(arr2, visited, i);
      if (temp > maxCycle) maxCycle = temp;
    }
  }
  cout << maxCycle << endl;
}

int main() {
  string mode;
  int num;
  cin >> num >> mode;
  shuffle(num, mode);
  return 0;
}