/* Copyright 2020 Ambioris Lora */
#ifndef  _HOME_OSBOXES_PS6_MMODEL_H_
#define  _HOME_OSBOXES_PS6_MMODEL_H_

#include <iostream>
#include <string>
#include <map>
#include <random>
#include <ctime>
#include <exception>

class MModel{
 public:
  MModel(std::string text, int k);
  int kOrder();
  int freq(std::string kgram);
  int freq(std::string kgram, char c);
  char kRand(std::string kgram);
  std::string generate(std::string kgram, int L);
  std::ostream friend operator <<(std::ostream& out, MModel const& a);
 private:
  std::string txt;
  int order, order2;
  std::string txt_hold, letters;
  std::map<std::string, int> table;
  std::map<std::string, int> table2;
};

#endif  // _HOME_OSBOXES_PS6_MMODEL_H_
