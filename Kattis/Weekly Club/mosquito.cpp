#include <bits/stdc++.h>
using namespace std;
int solution(int mosquitoes, int pupar, int larvae, int egg, int larvaLife,
             int puparLife, int n) {
  for (int i = 0; i < n; i++) {
    int newLarva = mosquitoes * egg;
    int newPupar = larvae / larvaLife;
    mosquitoes = pupar / puparLife;
    larvae = newLarva;
    pupar = newPupar;
  }
  return mosquitoes;
}

int main() {
  int mosquitoes, pupar, larvae, egg, larvaLife, puparLife, n;
  while (cin >> mosquitoes >> pupar >> larvae >> egg >> larvaLife >>
         puparLife >> n)
    cout << solution(mosquitoes, pupar, larvae, egg, larvaLife, puparLife, n)
         << endl;
  return 0;
}