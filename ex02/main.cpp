# include <iostream>
# include <string>

# include "Convert.hpp"

// *******************************
// ONLY WORKS WITH UNSIGNED CHAR *
// *******************************

int main(int argc, char const *argv[])
{
  if ( argc < 3 ) {
    std::cout << "Not Enough CMD Args!" << std::endl ;
    return 1 ;
  }

  if ( Convert::validateArgvOne(argv[1]) ) {
    std::cout << "CMD Argv[1] Value Neither 'up' nor 'down'!" << std::endl ;
    return 1 ;
  }

  Convert::convertUpperLower(argv + 2, argc - 2, argv[1]) ; 

  return 0 ;
}
