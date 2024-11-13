#include <bits/stdc++.h>
using namespace std;
int arr[9][12];

void slidingWindow(string str, int n) {
  map<string, int> doubles;
  int end = str.size() - 1;
  int start = 0;

  int index;
  vector<string> ans;
  if (str.size() == n) {
    cout << "1" << endl;
    cout << str;
  } else {
    string prefix = "";
    for (int i = 0; i < n; i++) prefix += str[i];
    ans.push_back(prefix);
    string suffix = "";
    while (prefix.size() != 0) {
      prefix.pop_back();
      int currentPtr = prefix.size();
      while (currentPtr != (str.size() - suffix.size() - 1)) {
        currentPtr++;

        string temp = suffix;
        reverse(temp.begin(), temp.end());
        ans.push_back(prefix + str[currentPtr] + temp);
      }
      suffix.push_back(str[currentPtr]);
    }

    for (auto &it : ans) doubles[it]++;
    cout << doubles.size() << endl;

    for (auto &it : doubles) cout << it.first << endl;
  }
}
void increment(int num, int i, string &str, int n) {
  int j = 0;
  while (true) {
    if (arr[num][j] == i) {
      // cout<<n<<" "<<j<<endl;
      arr[num][j]++;
      str += to_string(num);
      break;
    } else if (arr[num][j] < i)
      break;
    else
      j++;
  }
}

void solution() {
  map<string, int> count;

  int numSize;
  int n;
  string str;
  cin >> numSize >> n;

  for (int i = 0; i < n; i++) {
    str = "";
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      int num = s[j] - '0';
      if (arr[num][0] >= i) {
        //    if(num==7)cout<<num<<" "<<i<<endl;

        increment(num, i, str, n);
      }
    }
    count[str]++;
  }

  // //debug
  //     for(int i =0;i<9;i++){
  //         for(int j=0;j<12;j++){
  //         if(arr[i][j]==n)
  //         cout<<i<< " " <<j<<' '<<arr[i][j]<<endl;
  //     }
  //     }
  int ctr = 0;
  for (auto &it : count) {
    if (ctr < it.second) str = it.first;
    ctr = it.second;
  }
  // cout<<str<<" string" <<endl;

  slidingWindow(str, numSize);
}

int main() {
  solution();
  return 0;
}  // net project