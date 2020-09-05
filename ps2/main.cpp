#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PTree.hpp"

using namespace std;
using namespace sf;

int main(int argc, char* argv[])
{
  double L = 0.0;
  int N = 0; 
  //command line arguments
  L = atol(argv[1]);
  N = atoi(argv[2]);

  argc = argc;
  // This creates the window and tree
  PTree tree(L, N);
  return 0;
}
