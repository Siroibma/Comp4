/* Copyright 2020 Ambioris Lora */
#include "MModel.h"

int main(int argc, const char* argv[]) {
  std::string str1(argv[1]); // get user input
  std::string str2(argv[2]);
  int k = std::stoi(str1);
  int t = std::stoi(str2);
  std::string input;
  std::string current_txt;
  while (std::cin >> current_txt) {
    input = input + " " + current_txt;
    current_txt = "";
  }
  for (int i = 0; i < t; i++) {
    std::cout << input[i];
    if (input[i] == '.' || input[i] == '!') {
      std::cout << "\n";
    }
  }
  std::string output_string;
  MModel txt(input, k);
  output_string += "" + txt.generate(input.substr(0, k), t);
  std::cout << "output below\n";
  for (int i = 0; i < t; i++) {
    std::cout << output_string[i];
    if (output_string[i] == '.' || output_string[i] == '!') {
      std::cout << "\n";
    }
  }
  return 0;
}
