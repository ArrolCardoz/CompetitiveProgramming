// 852
#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
  int size = arr.size() - 1;
  int upperBound = size;
  int lowerBound = 0;

  while (lowerBound < upperBound) {
    int mid = (upperBound + lowerBound) / 2;
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;
    if (arr[mid] < arr[mid + 1])
      lowerBound = mid;
    else
      upperBound = mid;
    cout << lowerBound << " " << upperBound << endl;
  }
  return -1;
}

int main() {
  vector<int> arr = {0, 10, 5, 2};
  cout << peakIndexInMountainArray(arr);
  return 0;
}