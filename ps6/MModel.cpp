/* Copyright 2020 Ambioris Lora */
#include "/home/osboxes/ps6/MModel.h"

int MModel::kOrder() {
    return order;
}
MModel::MModel(std::string text, int k) {
    txt = text;
    txt_hold = text;
    order = k;
    order2 = k + 1;
    int position = 0;
    for (unsigned int i = 0; i < text.size(); i++) {
        if (std::string::npos == letters.find(text[i])) {
            letters.push_back(text[i]);
        }
    }
    std::string string_hold;
    std::map<std::string, int> kascii;
    if (k != 0) {
        txt_hold += text.substr(0, k - 1);
    }
    for (unsigned int i = 0; i < text.length(); i++) {
        string_hold = txt_hold.substr(position, k);
        kascii[string_hold] += 1;
        position = position + 1;
    }
    for (auto const& pair : kascii) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    table = kascii;
    std::map<std::string, int>kgram2;
    position = 0;
    if (k != 0) {
        txt_hold += text.substr(0, k);
    }
    for (unsigned int i = 0; i < text.length(); i++) {
        string_hold = txt_hold.substr(position, k + 1);
        kgram2[string_hold] += 1;
        position = position + 1;
    }
    for (auto const& pair : kgram2) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    table2 = kgram2;
}

int MModel::freq(std::string kgram) {
    if (kgram.size() != (unsigned)order) {
        throw std::runtime_error("kgram is not size k");
    }
    if (order == 0) {
        return txt.length();
    } else {
        return table[kgram];
    }
}

int MModel::freq(std::string kgram, char c) {
    if (kgram.length() != (unsigned)order) {
    throw std::runtime_error("Error not Kgram length L.");
  }
  std::string str1 = kgram;
  str1.push_back(c);
  return table2[str1];
}

char MModel::kRand(std::string kgram) {
    if (kgram.size() != (unsigned)order || table.end() == table.find(kgram)) {
        throw std::runtime_error("Error: randk kgram is invalid");
    }
    std::string temp;
    for (unsigned i = 0; i < letters.size(); i++) {
        for (int j = 0; j < table[kgram + letters[i]]; j++) {
            temp.push_back(letters[i]);
        }
    }
  return temp[rand() % temp.size()];
}

std::string MModel::generate(std::string kgram, int L) {
  std::string gen = "";
  char hold;
  gen = gen + kgram;
  for (unsigned int i = 0; i <= (L - (unsigned)order); i++) {
    hold = kRand(gen.substr(i, order));
    gen.push_back(hold);
  }
  return gen;
}
