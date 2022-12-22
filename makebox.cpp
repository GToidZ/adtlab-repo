#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;

  // Read in the integer
  cin >> n;

  // Generate and print the output for each line
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);  // Convert the integer to a string
    cout << s[s.length() - 1];  // Print the last character of the string
    for (int j = 0; j < s.length() - 1; j++) {  // Iterate through the rest of the characters in the string
      cout << s[j];  // Print each character
    }
    cout << endl;  // Move to the next line
  }

  return 0;
}
