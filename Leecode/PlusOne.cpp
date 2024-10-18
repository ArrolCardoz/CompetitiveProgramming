// 66
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
  int size = digits.size() - 1;
  string num;

  vector<int> ans;
  vector<int> ans1;

  int carry = 1;
  int sum;
  //   cout << str << "string " << endl;
  for (int i = size; i >= 0; i--) {
    sum = digits[i] + carry;
    carry = sum / 10;
    sum %= 10;
    ans.push_back(sum);
    // cout << it << endl;
  }
  if (carry) {
    ans.push_back(carry);
    size++;
  }
  for (int i = size; i >= 0; i--) {
    ans1.push_back(ans[i]);
  }

  return ans1;
}

int main() {
  vector<int> digits = {9};
  for (auto& it : plusOne(digits)) cout << it << ' ';
  return 0;
}
