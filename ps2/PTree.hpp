#ifndef PTREE_HPP_INCLUDED
#define PTREE_HPP_INCLUDED

using namespace std;
using namespace sf;

class PTree
{
public:
    PTree(double L, int N);
    ~PTree();

  void drawPtree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent);
  void drawPtree(sf::RenderTarget& target, const float L, const int N);
  
private:
    sf::RenderWindow window;
};

#endif 
