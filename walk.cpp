#include <iostream>
#include <vector>

using namespace std;

int get_closest(vector<int> pos, int current_distance, int enthusiasm_distance) {
  // Will not get the passed gas stations
  for (auto x = pos.begin(); x != pos.end(); x++) {
    if (*x < current_distance) continue; 
    if (*x >= current_distance && *x <= current_distance + enthusiasm_distance) {
      return *x;
    }
  }
  return -1;
}

int main() {
  int N, Z, D, E;
  cin >> N >> Z  >> D >> E;
  vector<int> gas_pos = vector<int>(N);
  for (int i = 0; i < N; i++) {
    int pos;
    cin >> pos;
    gas_pos.push_back(pos);
  }

  // Simulate going/walking to destination
  int gas_refill_count = 0;
  int current_distance = 0;
  for (int i = 0; i < Z; i += D) {
    current_distance += D;
    
    if (Z-current_distance <= E) {
      continue;
    }

    int visit = get_closest(gas_pos, current_distance, E);
    
    if (visit == -1 && Z-current_distance > E) {
      gas_refill_count = -1;
      break;
    }

    gas_refill_count++;
  }

  cout << gas_refill_count << endl;
}
