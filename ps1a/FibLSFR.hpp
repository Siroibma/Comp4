#ifndef FIBLSFR_HPP
#define FIBLSFR_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

void left_shift(string& b_string, int shift_amount);
string to_bin(int& a);
int to_string(string &strin);

class LSFR{
public:
  LSFR(string seed);
  int step();
  int generate(int k);
  string toString();
  static void main(string args[]);
  friend void left_shift(string &b_string, int shift_amount);
private:
  string bin_string;
};

#endif
