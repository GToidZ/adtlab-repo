#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (a == 0 || b == 0) {
    return a + b;
  }
  if (a == b) {
    return a;
  }
  if (a % 2 == 0 && b % 2 != 0) {
    return gcd(a / 2, b);
  } else if (a % 2 != 0 && b % 2 == 0) {
    return gcd(a, b / 2);
  }
  if (a > b) {
    return gcd(a - b, b);
  } else {
    return gcd(a, b - a);
  }
}

int main() {
  int numerator, denominator;
  cin >> numerator >> denominator;
  int _gcd = gcd(numerator, denominator);
  numerator /= _gcd;
  denominator /= _gcd;

  cout << numerator << "/" << denominator << endl;
}
