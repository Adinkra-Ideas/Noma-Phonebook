#pragma once

#ifndef _ETC__HPP
#define _ETC__HPP

# include <iostream>
# include <string>

namespace etc {
static const char  *RESET_COLOR = "\033[0m" ;
static const char  *RED = "\033[1;31m" ;
static const char  *GREEN = "\033[1;32m" ;
static const char  *YELLOW = "\033[1;33m" ;
static const char  *MAGENTA = "\033[1;35m" ;


void	printOut(const char*, const std::string&, bool EOL = true, bool stream = true) ;

} // namespace etc

#endif // _ETC__HPP
