#include <iostream>

using namespace std;

int main() {
  int T, N;
  int scarecrows;
  string field;
  while (cin >> T) {
    for (int i = 1; i <= T; i++) {
      cin >> N;
      getchar();
      getline(cin, field);
      scarecrows = 0;
      for (int j = 0; j < field.length(); j++) {
        if (field[j] == '.') {
          scarecrows++;
          if (j+1 < field.length()) field[j+1] = '#';
          if (j+2 < field.length()) field[j+2] = '#';
        }
      }
      cout << "Case " << i << ": " << scarecrows << endl;
    }
  }
}
