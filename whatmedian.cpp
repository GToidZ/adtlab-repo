#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<long long> series;
  long long x;
  while (cin >> x) {
    series.push_back(x);
    int size = series.size();
    int tmp = size;
    while (tmp > 1 && series[tmp-1] < series[tmp-2]) {
      swap(series[tmp-1], series[tmp-2]);
      tmp--;
    }
    if (size == 1) {
      cout << series[0] << endl;
      continue;
    }
    if (size % 2 == 0) {
      cout << (series[size/2-1] + series[size/2])/2 << endl;
    } else {
      cout << series[size/2] << endl; 
    }
  }
}
