// #pragma once
#ifndef __ETC_HPP__
# define __ETC_HPP__

# include <iostream>
# include <string>

typedef char __int8 ;

namespace etc {
  static const char  *RESET_COLOR = "\033[0m" ;
  static const char  *RED = "\033[1;31m" ;
  static const char  *GREEN = "\033[1;32m" ;
  static const char  *YELLOW = "\033[1;33m" ;
  static const char  *MAGENTA = "\033[1;35m" ;


  void	printOut(const char*, const std::string&, bool EOL = true, bool stdout = true) ;
  
} // namespace etc
  
#endif
