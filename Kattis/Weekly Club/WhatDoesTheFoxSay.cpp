#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
void solution() {
  unordered_map<string, int> sounds;
  unordered_map<string, int> soundsCount;
  vector<string> order;

  string str;
  getline(cin, str);
  //   cin.ignore();
  stringstream ss(str);
  string sound, temp1, temp2;

  while (ss >> sound) {
    // cout << "TESTING            ========" << sound << endl;

    if (sounds.find(sound) == sounds.end()) order.push_back(sound);
    sounds[sound] = 0;
    soundsCount[sound]++;
  }
  str = "";
  while (true) {
    getline(cin, str);
    // cin.ignore();
    // cout << "TESTING            ========" << str << endl;
    if (str == "what does the fox say?") break;
    stringstream input(str);
    input >> temp1 >> temp2 >> sound;
    sounds[sound] = 1;
  }
  //   cout << "LOOPEB++++++++++++++" << endl;
  for (auto& it : order) {
    if (sounds[it] == 0) {
      while (soundsCount[it]--) cout << it << ' ';
    }
    // cout << it << ' ';
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  while (n--) solution();
  return 0;
}