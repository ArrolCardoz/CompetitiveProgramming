
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
  // Write your code here
  int num0, num1, num2, num3, max0, max1 = 0;
  int prevCounter = -100;
  int sum = 0;
  for (int i = 0; i < inputArr.size(); i++) {
    num0 = inputArr[i];
    if (inputArr.size() > i + 1) {
      num1 = inputArr[i + 1];
    } else {
      num1 = 0;
    }
    if (inputArr.size() > i + 2) {
      num2 = inputArr[i + 2];
    } else {
      num2 = 0;
    }
    if (inputArr.size() > i + 3) {
      num3 = inputArr[i + 3];
    } else {
      num3 = 0;
    }

    if (num0 > num2)
      max0 = num0;
    else
      max0 = num2;
    if (num1 > num3)
      max1 = num1;
    else
      max1 = num3;
    cout << "MAX0 " << num3 << "MAX1 " << num2 << endl;
    if (max0 > max1) {
      if (num0 > num2 && prevCounter != i - 1) {
        sum += num0;
        cout << "SUM - condition 1 - " << inputArr[i] << endl;
        prevCounter = i;
      } else if (num0 < num2 && prevCounter != i - 1) {
        sum += num2;
        cout << "SUM - condition 2 - " << inputArr[i] << endl;
        prevCounter = i;
      }
    } else {
      if (num1 > num3 && prevCounter != i - 1) {
        sum += num1;
        cout << "SUM - condition 3 - " << inputArr[i] << endl;
        prevCounter = i;
      } else if (num1 < num3 && prevCounter != i - 1) {
        sum += num3;
        cout << "SUM - condition 4 - " << inputArr[i] << endl;
        prevCounter = i;
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