#include "ED.hpp"

int main()
{
    std::string ls1;
    std::string ws2;
    std::cin >> ls1 >> ws2;
    sf::Clock a;
    ED c(ls1,ws2); 
    std::cout << "Edit Distance: " << c.OptDistance() << std::endl;
    c.string_alignment();
    sf::Time elasped_t = a.getElapsedTime();
    std::cout << elasped_t.asSeconds();
    return 0;
}

