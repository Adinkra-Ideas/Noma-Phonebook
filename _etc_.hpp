#pragma once

#ifndef _ETC__HPP
#define _ETC__HPP

# include <iostream>
# include <string>

namespace etc {

extern const char  *RESET_COLOR ;
extern const char  *RED ;
extern const char  *GREEN ;
extern const char  *YELLOW ;
extern const char  *MAGENTA ;

void	printOut(const char *, const std::string&, bool EOL = true, bool stream = true) ;

} // namespace etc

#endif // _ETC__HPP
