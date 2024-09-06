#include <bits/stdc++.h>
using namespace std;

string findNum(vector<int>& A) {
  auto low = A.begin();
  auto high = A.end() - 1;
  while (!(*low > *high)) {
    if (*low + *high == 7777 && *low != *high)
      return "Yes";
    else if (*low + *high > 7777)
      high--;
    else
      low++;
  }
  return "No";
}

string unique(vector<int>& A) {
  auto it = A.begin() + 1;

  for (auto& v : A) {
    if (it == A.end()) return "Unique";
    //  cout << *it << " " << v << endl;
    if (*it == v) return "Contains duplicate";
    it++;
  }
  return "Unique";
}

int case3(vector<int>& A) {
  for (int i = 0; i < A.size(); i++) {
    if (A[i] < (A.size() / 2)) return A[i];
  }
  return -1;
}

void median(vector<int>& A) {
  int mid = ((A.size()) / 2);
  if (A.size() % 2 == 1)
    cout << A[mid];
  else
    cout << A[mid - 1] << " " << A[mid];
}

void print(vector<int>& A) {
  auto it = A.begin();
  bool isTrue = true;

  while (isTrue) {
    if (*it > 999)
      isTrue = false;
    else if (*it > 100)
      cout << *it << " ";
    it++;
  }
}

int main() {
  int N, t;
  vector<int> arr;

  cin >> N >> t;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;

    arr.push_back(input);
  }
  sort(arr.begin(), arr.end());
  switch (t) {
    case 1: {
      cout << findNum(arr);
      break;
    }

    case 2: {
      cout << unique(arr);
      break;
    }

    case 3: {
      cout << case3(arr);
      break;
    }

    case 4: {
      median(arr);
      break;
    }

    case 5:
      print(arr);
      break;

    default: {
      cout << "incorrect input";
      break;
    }
  }

  return 0;
}