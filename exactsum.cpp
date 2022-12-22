#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  while (cin >> N) {
    long prices[10010];
    for (int i = 0; i < N; i++) {
      cin >> prices[i];
    }
    int M;
    cin >> M;
    stable_sort(prices, prices+N);
    int a, b, diff = 2147483647;
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        if (prices[i] + prices[j] == M && prices[j] - prices[i] < diff) {
          a = prices[i];
          b = prices[j];
        }
      }
    }
    cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl << endl;
  }
}
