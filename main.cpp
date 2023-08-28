#include <math.h>
#include <string.h>

#include <iostream>
using namespace std;
string school_method_add(string num1, string num2, int base) {
  string sum;
  int carry = 0;
  int num1_len = num1.length();
  int num2_len = num2.length();
  int sum_len = max(num1_len, num2_len) + 1;
  if (num1_len < num2_len) {
    for (int i = 0; i < num2_len - num1_len; i++) {
      num1 = "0" + num1;
    }
    num1_len = num2_len;
  } else if (num1_len > num2_len) {
    for (int i = 0; i < num1_len - num2_len; i++) {
      num2 = "0" + num2;
    }
    num2_len = num1_len;
  }
  for (int i = 0; i < sum_len - 1; i++) {
    int int1, int2, sumi;
    int1 = num1[num1_len - 1 - i] - '0';
    int2 = num2[num2_len - 1 - i] - '0';
    sumi = int1 + int2 + carry;
    if (sumi >= base) {
      carry = 1;
      sumi = sumi - base;
    } else {
      carry = 0;
    }
    sum = to_string(sumi) + sum;
  }
  sum = to_string(carry) + sum;

  int start = sum.size();
  for (int i = 0; i < start; i++) {
    if (sum[i] != '0') {
      start = i;
      break;
    }
  }
  sum = sum.substr(start, sum.size() - start);
  return sum;
}

int main() {
  string num1, num2, base;
  cin >> num1 >> num2 >> base;
  int base_int = stoi(base);
  cout << school_method_add(num1, num2, base_int) << " " << endl;
  return 0;
}