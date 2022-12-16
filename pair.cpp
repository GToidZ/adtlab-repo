#include <iostream>
#include <vector>

using namespace std;

struct NumberPair {
  long long first;
  long long second;
  
  NumberPair(long long first, long long second)
    : first(first), second(second) {}

};

typedef vector<NumberPair> NumberPairs;

NumberPairs get_pairs_from_num_array(int n, long long arr[]) {
  NumberPairs pairs;
  for (int i = 0; i < n - 1; i++) {
    int cursor = arr[i];
    for (int j = i + 1; j < n; j++) {
      NumberPair pair(cursor, arr[j]);
      pairs.push_back(pair);
    }
  }
  return pairs;
}

int main() {
  int n;
  long long G, T;
  cin >> n >> G >> T;
  long long numbers[n];
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  NumberPairs pairs = get_pairs_from_num_array(n, numbers);
  NumberPairs valid_pairs;
  for (auto it = pairs.begin(); it != pairs.end(); ++it) {
    NumberPair pair(it->first, it->second);
    long long sum = pair.first + pair.second;
    if (T) {
      long long min = G-T, max = G+T;
      if (sum >= min && sum <= max) valid_pairs.push_back(pair);
    } else {
      if (sum == G) valid_pairs.push_back(pair);
    }
  }
  cout << valid_pairs.size() << endl;
}

