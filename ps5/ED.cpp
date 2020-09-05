#include "ED.hpp"

ED::ED(std::string string_one, std::string string_two){
  s1 = string_one;
  s2 = string_two;
  //makes a 2d vector with size of string one by string two
  arr = std::make_shared<std::vector<std::vector<int>>>(string_one.size() + 1, std::vector<int>(string_two.size() + 1));
  
}

void ED::string_alignment(){
  for(int i = 0; i < (signed)s1.length();){
        for(int j = 0; j < (signed)s2.length();){
            if(i  == (signed)s1.length() + 1 or j + 1 == (signed)s2.length()){
                std::cout << s1[i] << " " << s2[j] << " " << penalty(s1[i],s2[j]) << std::endl;
                return;
            }
            if((*arr)[i][j] == (*arr)[i+1][j+1] + 1){
                std::cout << s1[i] << " " << s2[j] << " " << penalty(s1[i],s2[j]) << std::endl;
                i += 1;
                j += 1;
            }
            if((*arr)[i][j] == (*arr)[i+1][j+1]){
                std::cout << s1[i] << " " << s2[j] << " " << penalty(s1[i],s2[j]) << std::endl;
                i += 1;
                j += 1;
            }
            if((*arr)[i][j] == (*arr)[i+1][j] + 2){
                std::cout << s1[i] << " -" << " 2" << std::endl; 
                i+=1;
            }
            if((*arr)[i][j] == (*arr)[i][j+1] + 2){
                std::cout << "- " << s2[j] << " 2" << std::endl;
                j+=1;
            }
            
        }
        
    }
}

ED::~ED(){
  std::cout << "destructor called" << std::endl;
}
int ED::penalty(char a, char b){
    if(a == b){
        return 0;
    }
    if(a != b){
        return 1;
    }
    else{
      return 0;
    }
}

int ED::OptDistance(){
    int a = s1.size() * 2;
    int b = s2.size() * 2;
    //last row
    for(int i = 0; i <= (signed)s1.size(); i++){
        //(*arr)[9][k] = a - (2 * k);
        (*arr)[i][s2.size()] = a - (2 * i);
    }
    //last column 
    for(int j = 0; j <= (signed)s2.size(); j++){
        (*arr)[s1.size()][j] = b - (2 * j);
    }
    //fill in the rest of the matrix using the min algorthim
    for(int i = s1.size() - 1 ; i >= 0; i--){
        for(int j = s2.size() - 1; j >= 0; j--){
            if(s1[i] == s2[j]){
                (*arr)[i][j] = minimum( (*arr)[i+1][j+1] + 0, (*arr)[i+1][j] + 2, (*arr)[i][j+1] + 2);
                
            }
            if(s1[i] != s2[j]){
                
                (*arr)[i][j] = minimum( (*arr)[i+1][j+1] + 1, (*arr)[i+1][j] + 2, (*arr)[i][j+1] + 2);
            }
            
        }
    }
    return (*arr)[0][0];
}
