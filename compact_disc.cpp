#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  // While not EOF and N != 0 and M != 0
  while (cin >> N >> M && N && M) {
    vector<int> NCD(N, 0);
    vector<int> MCD(M, 0);

    for (int i = 0; i < N; i++) cin >> NCD[i];
    for (int i = 0; i < M; i++) cin >> MCD[i];

    int both = 0;
    for (int i = 0, j = 0; i < N && j < M;) {
      if (NCD[i] == MCD[j]) {
        both++; i++; j++;
      } else if (NCD[i] > MCD[j]) j++;
      else i++;
    }
    cout << both << endl;
  }
}
