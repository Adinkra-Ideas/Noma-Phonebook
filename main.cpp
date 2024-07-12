/**
  * @name Noma Phonebook
  ** A non-GUI Phonebook Program written in CPP.
  * 
  * This Program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This Program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  */


#include "PhoneBook.hpp"
#include "main.hpp"

namespace noma {

  const char *RESET_COLOR = "\033[0m" ;
  const char *RED = "\033[1;31m" ;
  const char *GREEN = "\033[1;32m" ;
  const char *YELLOW = "\033[1;33m" ;
  const char *MAGENTA = "\033[1;35m" ;

/**
  * Prints out texts in terminal using Custom Colors
  * @param color is used to set color of text to be printed.
  ** Macros have been defined for popular color codes in noma::
  * @param texts is the actual texts to be printed.
  * @param EOL is a default parameter set to true.
  ** It is used to determine if line break will be added
  ** after printing texts.
  * @param stream is a default parameter set to true.
  ** It is used to determine which output stream to print texts.
  ** If false, texts will be printed to stderr.
  * @returns void
  */
void	printOut(const char * color, const std::string & texts, bool EOL, bool stream) {
    if ( stream ) {
        std::cout << color
                  << texts
                  << noma::RESET_COLOR
                  << ((EOL) ? "\n" : "") ;
    } else {
        std::cerr << color
                  << texts
                  << noma::RESET_COLOR
                  << ((EOL) ? "\n" : "") ;
    }
}

} // namespace noma

int main()
{
	PhoneBook   phonebook ;
	std::string cmd ;

	PhoneBook::showHomeScreen(cmd) ;

	while ( cmd.compare("EXIT\0") ) {
		if ( ! cmd.compare("ADD") ) {
			phonebook.addContact() ;
    } else if ( ! cmd.compare("SEARCH\0") ) {
			phonebook.displaySearchResults() ;
    } else if ( ! cmd.compare("BOOKMARK\0") ) {
      phonebook.displayBookmarks() ;
    } else if ( ! cmd.compare("REMOVE\0") ) {
      phonebook.removeContact() ;
    } else if ( cmd.length() > 0 ) {
      noma::printOut(noma::RED, "WRONG COMMAND! Please try again...") ;
    } else {
      return (0) ;
    }
    
    PhoneBook::showHomeScreen(cmd) ;
	}

	if ( ! cmd.compare("EXIT\0") ) {
		return (0);
  }

	return (1);
}
