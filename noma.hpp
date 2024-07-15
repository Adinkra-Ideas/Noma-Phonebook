#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <iostream>
#include <string>

namespace noma {

extern const char  *RESET_COLOR ;
extern const char  *RED ;
extern const char  *GREEN ;
extern const char  *YELLOW ;
extern const char  *MAGENTA ;

void	printOut(const char *, const std::string&, bool EOL = true, bool stream = true) ;

} // namespace noma

#endif // MAIN_HPP_
