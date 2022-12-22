#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int t = 0;
    int arr[1010];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n-1-i; j++) {
        if (arr[j] > arr[j+1]) {
          swap(arr[j], arr[j+1]);
          t++;
        }
      }
    }
    cout << "Minimum exchange operations : " << t << endl;
  }
}

