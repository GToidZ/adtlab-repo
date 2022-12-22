#include <iostream>

using namespace std;

int main() {
  int G;
  while (cin >> G) {
    if (!G) break;
    string message;
    cin >> message;
    int npG = message.length() / G; // # of members per group
    for (int i = 0; i < message.length(); i += npG) {
      // For each index in a group, going from backwards
      for (int j = i + npG - 1; j >= i; j--) {
        cout << message[j];
      }
    }
    cout << endl;
  }
}
