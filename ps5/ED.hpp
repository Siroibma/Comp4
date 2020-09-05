#ifndef ED_HPP
#define ED_HPP
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> 
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class ED{
    public:
    ED(std::string string_one, std::string string_two);
    int minimum(int a, int b, int c){
        return std::min({a,b,c});
    }
  ~ED();
    int OptDistance();
    void string_alignment();
    int penalty(char a, char b);
    private:
    std::shared_ptr<std::vector<std::vector<int>>> arr;
    std::string s1;
    std::string s2;
};

#endif
