#include <bits/stdc++.h>
using namespace std;
int score[41] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32,
                 33, 34, 36, 38, 39, 40, 42, 45, 48, 51, 54, 57, 60};
void print(int a, int b, int c) {
  unordered_map<int, string> ans;
  ans[1] = "single 1";
  ans[2] = "single 2";
  ans[3] = "single 3";
  ans[4] = "single 4";
  ans[5] = "single 5";
  ans[6] = "single 6";
  ans[7] = "single 7";
  ans[8] = "single 8";
  ans[9] = "single 9";
  ans[10] = "single 10";
  ans[11] = "single 11";
  ans[12] = "single 12";
  ans[13] = "single 13";
  ans[14] = "single 14";
  ans[15] = "single 15";
  ans[16] = "single 16";
  ans[17] = "single 17";
  ans[18] = "single 18";
  ans[19] = "single 19";
  ans[20] = "single 20";
  ans[21] = "triple 7";
  ans[22] = "double 11";
  ans[24] = "double 12";
  ans[26] = "double 13";
  ans[27] = "triple 9";
  ans[28] = "double 14";
  ans[30] = "double 15";
  ans[32] = "double 16";
  ans[33] = "triple 11";
  ans[34] = "double 17";
  ans[36] = "double 18";
  ans[38] = "double 19";
  ans[39] = "triple 13";
  ans[40] = "double 20";
  ans[42] = "triple 14";
  ans[45] = "triple 15";
  ans[48] = "triple 16";
  ans[51] = "triple 17";
  ans[54] = "triple 18";
  ans[57] = "triple 19";
  ans[60] = "triple 20";
  cout << ans[a] << endl;
  if (b) cout << ans[b] << endl;
  if (c) cout << ans[c] << endl;
}
void solution(int num) {
  int answer[3];
  int count;
  int loop = 40;
  do {
    count = 0;
    int number = num;
    for (int j = 0; j < 3; j++) {
      int state = 1;
      for (int i = 41; i >= 0; i--) {
        if (!state) break;
        if (number > score[i]) {
          cout << score[i] << endl;
          number -= score[i];
          count++;
          answer[j] = score[i];
          // cout << score[i] << " " << number << endl;
          state = 0;
        }
      }
    }
    cout << answer[0] << " " << answer[1] << " " << answer[2];
    if (count = 3)
      print(answer[0], answer[1], answer[2]);
    else if (count = 2)
      print(answer[0], answer[1], 0);
    else
      print(answer[0], 0, 0);
  } while (count > 3 && (loop / 3) > num);
}

int main() {
  solution(60);
  //   vector<int> nums;
  //   for (int i = 1; i <= 20; i++) {
  //     for (int j = 1; j < 4; j++) nums.push_back(j * i);
  //   }

  //   sort(nums.begin(), nums.end());
  //   for (auto &it : nums) cout << it << " ";
  return 0;
}