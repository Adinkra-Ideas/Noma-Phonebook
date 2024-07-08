# include "Convert.hpp"

Convert::Convert()
{}

Convert::~Convert()
{}

bool Convert::validateArgvOne(std::string argv1) {
  if ( ! argv1.compare("up")
      || ! argv1.compare("down") ) {
    return false ;
  }
  return true ;
}

void Convert::convertUpperLower( const char **argvModified, int argcModified, std::string command ) {
  std::string sentence ;

  while ( argcModified > 0 ) {
    sentence.append(*argvModified) ;
    argvModified++ ;
    argcModified-- ;

    if ( argcModified > 0 ) {
      sentence.append(" ") ;
    }
  }

  if ( ! command.compare("up") ) {
    std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper) ;
  }
  else if ( ! command.compare("down") ) {
    std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower) ;
  }

  std::cout << sentence << std::endl ;
}
