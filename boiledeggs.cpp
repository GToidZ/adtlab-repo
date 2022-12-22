#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T, t = 0;
  cin >> T;
  while (T--) {
    int eggs, nLimit, wLimit;
    cin >> eggs >> nLimit >> wLimit;
    int eggWeights[40];
    for (int i = 0; i < eggs; i++) {
      cin >> eggWeights[i];
    }
    stable_sort(eggWeights, eggWeights + eggs);
    int count = 0;
    for (int i = 0; i < min(nLimit, eggs); i++) {
      wLimit -= eggWeights[i];
      if (wLimit >= 0) count++;
    }
    cout << "Case " << ++t << ": " << count << endl; 
  }
}
