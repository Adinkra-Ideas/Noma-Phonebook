#pragma once
# ifndef __CONVERT_HPP__
# define __CONVERT_HPP__

# include <iostream>
# include <string>
# include <algorithm>

class Convert 
{
public:
  Convert( void ) ;
  ~Convert(  void ) ;

  static bool validateArgvOne(std::string) ;
  static void convertUpperLower(const char **, int, std::string) ;

private:
} ;

#endif
