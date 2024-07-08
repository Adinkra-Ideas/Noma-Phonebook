#pragma once

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <iomanip>
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

    const int8_t&   getCount() ;
    Contact*        getArrayFromContact(const int8_t&) ;

    static void   showHomeScreen(std::string&) ;

    void    addContact() ;
    void	  removeOneContact(int8_t, const bool&) ;
    void	  displaySearchResults() ;
    void	  showSingleContactUsingIndex() ;
    void    displayBookmarks() ;
    void    removeContact() ;

private:
    int8_t     _count ;                    // Value of _count is total number of Contacts currently stored in *_contact[]
    Contact	   *_contact[MAX_ENTRY + 1] ;  // Each array of  *_contact[] holds a unique Contact
} ;

#endif // PHONEBOOK_HPP
