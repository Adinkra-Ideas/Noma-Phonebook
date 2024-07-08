# include "Contact.hpp"

// ********************
// CANONICALS BEGINS  *
// ********************

Contact::Contact() :  _name(""),
    _number(""),
    _nickname(""),
    _bookmark(false) {}

Contact::~Contact() {}

// ******************
// CANONICALS ENDS  *
// ******************


// ******************
//  GETTERS BEGINS  *
// ******************

const std::string&	 Contact::getName() {
    return (_name) ;
}

const std::string&	 Contact::getNickname() {
    return (_nickname) ;
}

const std::string&	 Contact::getNumber() {
    return (_number) ;
}

const bool&  Contact::getBookmark() {
    return _bookmark ;
}

// ******************
//  GETTERS ENDS    *
// ******************

/**
  * Collects and validate details from the stdin
  ** for creating a new Contact.
  * @param phonebook Required for gaining access to
  ** the phonebook->_contact[] object for comparing
  ** number received against numbers already saved.
  * @returns true if any of the details received for
  ** creating the new Contact was invalid. Else true
  ** if details received were ok.
  */
bool	Contact::addOneContact(PhoneBook * phonebook) {
    etc::printOut(etc::YELLOW, "Enter name") ;
    std::getline(std::cin, _name) ;
    etc::printOut(etc::YELLOW, "Enter phone number") ;
    std::getline(std::cin, _number) ;
    while (this->validateNumberInput(phonebook)) {
        etc::printOut(etc::RED, "Phone number exists already!") ;
        etc::printOut(etc::YELLOW, "Enter new number") ;
        std::getline(std::cin, _number) ;
    }

    etc::printOut(etc::YELLOW, "Enter nickname") ;
    std::getline(std::cin, _nickname) ;
    if ( this->entryValidator() ) {
        return true ;
    }
    return false ;
}

/**
  * Compares _number against numbers already saved in
  ** other instances of Contact object accessible through
  ** the phonebook->_contact[] object
  * @param phonebook Required for gaining access to
  ** the phonebook->_contact[] object for comparing
  ** number received against numbers already saved.
  * @returns true if _number exists already in other
  ** instances of Contact object. Else, returns true.
  */
bool	Contact::validateNumberInput(PhoneBook * phonebook) {
    int8_t contactCount = phonebook->getCount() - 1 ;

    while (contactCount >= 0) {
        if (! _number.compare(phonebook->getArrayFromContact(contactCount)->getNumber()) ) {
            return true ;
        }
        contactCount-- ;
    }
    return false ;
}

/**
  * Function that checks if any of the strings _name,
  ** _number, _nickname is empty.
  * @returns true if any is empty. Else returns false.
  */
bool	Contact::entryValidator() {
    if ( !_name.length()
        || !_number.length()
        || !_nickname.length() ) {
        return true ;
    }
    return false ;
}

/**
  * Prints out the full details of one phone number
  * @returns void
  */
void	Contact::printContact() {
    std::cout << "First Name:       " << _name << std::endl
              << "Phone Number:     " << _number << std::endl
              << "Nickname:         " << _nickname << std::endl
              << (( ! _bookmark ) ?  this->addBookmark() : "") << std::endl ;
}

/**
  * Tries to Bookmark this Contact by setting _bookmark
  ** member to true, if the user input in STDIN=='*'
  * @returns Success message as a string literal if the
  ** user input in STDIN=='*', else it returns an empty
  ** string literal.
  */
const char* Contact::addBookmark() {
    std::string userInput ;

    etc::printOut(etc::YELLOW, "To Bookmark, enter *\nTo return, enter any Character") ;

    std::getline(std::cin, userInput) ;
    if ( userInput.at(0) == '*' ) {
        _bookmark = true ;
        return "Bookmark Set Successfully!" ;
    } else {
        return "" ;
    }
}
