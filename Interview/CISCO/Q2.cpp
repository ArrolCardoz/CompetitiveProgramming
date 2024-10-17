
// Header Files
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * numJars, represents the number of jars.
Value of the array represents the number of chocolates in each jar.
 */
void maxSum(vector<int> inputArr) {
  int sum = 0;
  int prevCounter = -100;
  // Write your code here
  for (int i = 0; i < inputArr.size(); i++) {
    if (i + 1 == inputArr.size() && prevCounter != i - 1) {
      sum += inputArr[i];
    }
    if (inputArr[i] > inputArr[i + 1] && prevCounter != i - 1) {
      cout << "SUM - condition 1 -" << inputArr[i] << endl;

      sum += inputArr[i];
      prevCounter = i;
    } else {
      if (inputArr[i + 1] > inputArr[i + 2] && prevCounter != i - 1 &&
          i + 2 < inputArr.size()) {
        sum += inputArr[i];
        cout << "SUM - condition 2 - " << inputArr[i] << endl;
        prevCounter = i;
      } else {
        if (prevCounter != i - 1 && i + 2 < inputArr.size()) {
          cout << "SUM - condition 3 - " << inputArr[i] << endl;

          sum += inputArr[i];
          prevCounter = i;
        }
      }
    }
  }
  cout << sum;
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

  maxSum(inputArr);

  return 0;
}