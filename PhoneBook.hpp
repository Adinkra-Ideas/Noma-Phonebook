#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <iomanip>
// # include <sstream>
# include "_etc_.hpp"
# include "Contact.hpp"

class Contact ;

# ifndef MAX_ENTRY
#  define MAX_ENTRY 8 // Maximum number of Contacts that this Phonebook App can store
# endif

class PhoneBook
{
public:
	PhoneBook() ;
  ~PhoneBook() ;

  const __int8&   getCount() ;
  Contact*        getArrayFromContact(const __int8&) ;

  static void   showHomeScreen(std::string&) ;

  void    addContact() ;
	void	  removeOneContact(__int8, const bool&) ;
	void	  displaySearchResults() ;
  void	  showSingleContactUsingIndex() ;
  void    displayBookmarks() ;
  void    removeContact() ;  

private:
	__int8     _count ;                    // Value of _count is total number of Contacts currently stored in *_contact[]
	Contact	   *_contact[MAX_ENTRY + 1] ;  // Each array of  *_contact[] holds a unique Contact
} ;

#endif
