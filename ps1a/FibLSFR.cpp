#include <string>
#include <iostream>
#include "FibLSFR.hpp"

LSFR::LSFR(string seed){
  bin_string = seed;
}

string LSFR::toString(){
  return bin_string;
}

int LSFR::generate(int k){
  int i,hold = 0;
  unsigned int j = 0;
  //goal step k times, add the kth bits and add the last bit
  
  for(i = 0; i < k; i++){
    step();
  }

  //we want the remaining bits
  for(j = bin_string.size() - k; j <= bin_string.size(); j++)
    {
      //check if its equal to one
      if(bin_string[j] == 49)
	{
	  //check if its in the last bit place
	  if(bin_string.size() - j - 1 == 49)
	    {
	      hold = hold + 1;
	    }
	  else
	    {
	      hold = pow(2, bin_string.size() - j - 1) + hold;
	    }
	}
    }
  // cout << bin_string << " " << bin_string.back() << endl;

  return hold; 
}

int LSFR::step(){
  //cout << bin_string.capacity() << endl;
  //here we xor the bit that will be pushed out and the seed
  //also I subtract the lenght by tao ti get the order the homework desires. since its in reverse order
  
  int a = bin_string[0] ^ bin_string[2] ^ bin_string[3] ^ bin_string[5];
  //cout << " " << a;

  //since we are converting an int to a char we must account for ascii, there fore we add 48
  //if its 0 then 0 + 48 = 48 which is in ascii. If its 1 then 1+48 = 49 which is one in ascii

  char b = a + 48;

  //cout << " " << b;

  //left shift it by one
  left_shift(bin_string, 1);

  //make the back equal to the xor of the tap positions
  bin_string.back() = b;

  //return the last
  return a;
}
 
void left_shift(string & b_string, int shift_amount){
  reverse(b_string.begin(), b_string.begin() + shift_amount);
  reverse(b_string.begin() + shift_amount, b_string.end());
  reverse(b_string.begin(), b_string.end());
}

string to_bin(int &a){
  string bin_hold;
  unsigned int i = 0;
  while(a > 0){
    bin_hold.push_back(((a % 2) + 48));
    a = a / 2;
    i++;
  }
  reverse(bin_hold.begin(), bin_hold.end());
  return bin_hold;
}

int to_int(string &strin){
  unsigned int i;
  unsigned int hold = 0;
  for(i = 0; i <= strin.size() - 1; i++)
    {
      if(strin[i] == 49)
	{
	  if(strin.size() - i - 1 == 49)
	    {
	      hold = hold + 1;
	    }
	  else
	    {
	      hold = pow(2,strin.size() - i - 1);
	    }
	}
    }
  return hold;
}
