#include <bits/stdc++.h>
using namespace std;
vector<int> input;
unordered_map<int, int> matrix;
int solution(int w, int h) {
  int breakCounter = 0;
  int bottomCounter = 0;
  int answer = 0;
  bool isTrue = false;
  for (auto it : input) {
    isTrue = true;
    if (breakCounter > 1000000) return -1;

    //   if (it == *input.end()) break;
    if (matrix[it] > h) {
      for (int i = 0; i < w; i++) {
        cout << "++++++++++++" << matrix[i] << " > " << bottomCounter << endl;
        if (matrix[i] < bottomCounter) {
          cout << "============" << matrix[i] << " > " << bottomCounter << endl;

          isTrue = false;
        }
      }
      if (isTrue) {
        bottomCounter++;
        matrix[it]++;
      } else {
        input.push_back(it);
        answer++;
      }

      input.push_back(it);
    } else {
      //   cout << "++++++++++++" << matrix[it] << " > " << bottomCounter <<
      //   endl;
      matrix[it]++;
    }

    breakCounter++;
  }
  for (auto &it : matrix) cout << it.first << " " << it.second << endl;
  return answer;
}

int main() {
  int w, h, n;
  int inpt;
  cin >> w >> h >> n;
  h--;
  for (int i = 0; i < n; i++) {
    cin >> inpt;
    input.push_back(inpt);
  }
  cout << solution(w, h);
  return 0;
}
