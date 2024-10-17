// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * inputArr, represents the array of size N.
 */
int funcMaxDifference(vector<int> inputArr) {
  int answer = 0;
  int maximum = 0;
  int minimum = 100000000;
  for (auto &it : inputArr) {
    if (it < minimum) {
      minimum = it;
      maximum = 0;
      continue;
    }
    if (maximum < it) maximum = it;
    if (answer < maximum - minimum) answer = maximum - minimum;
  }
  // Write your code here

  return answer;
}

int main() {
  // input for inputArr
  int inputArr_size;
  cin >> inputArr_size;
  vector<int> inputArr;
  for (int idx = 0; idx < inputArr_size; idx++) {
    int temp;
    cin >> temp;
    inputArr.push_back(temp);
  }

  int result = funcMaxDifference(inputArr);
  cout << result;

  return 0;
}
