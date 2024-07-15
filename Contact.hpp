#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <iostream>
#include <string>
#include "noma.hpp"
#include "PhoneBook.hpp"

class PhoneBook ;

class Contact
{
public:
    Contact() ;
    ~Contact() ;

    const std::string&		  getName() ;
    const std::string&		  getNickname() ;
    const std::string&		  getNumber() ;
    const bool&             getBookmark() ;

    bool          addOneContact(PhoneBook *) ;
    bool          validateNumberInput(PhoneBook *) ;
    bool          entryValidator() ;
    void	        printContact() ;
    const char*   addBookmark() ;

private:
    std::string   _name ;     // name of the Contact
    std::string   _number ;   // phone number of the Contact
    std::string   _nickname ; // nickname of the Contact
    bool          _bookmark ; // If true, it means this contact is saved as bookmark
} ;

#endif // CONTACT_HPP_
