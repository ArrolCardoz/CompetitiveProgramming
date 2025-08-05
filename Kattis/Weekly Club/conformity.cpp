#include <bits/stdc++.h>
using namespace std;

int main() {
  map<vector<int>, int> students;
  vector<int> courses(5);
  int count = 0, maxCourse = 0;
  int studentNum;
  cin >> studentNum;
  while (studentNum--) {
    for (int i = 0; i < 5; i++) {
      int n;
      cin >> n;
      courses[i] = n;
    }
    sort(courses.begin(), courses.end());
    students[courses]++;
  }
  for (auto &it : students) {
    maxCourse = max(maxCourse, it.second);
  }
  for (auto &it : students) {
    // cout << it.second << endl;
    if (it.second == maxCourse) count += it.second;
  }
  cout << count << endl;
}