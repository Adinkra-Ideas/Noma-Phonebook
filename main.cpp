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


# include "PhoneBook.hpp"
# include "_etc_.hpp"

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
