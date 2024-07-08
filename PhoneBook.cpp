# include "PhoneBook.hpp"

// ********************
// CANONICALS BEGINS  *
// ********************

PhoneBook::PhoneBook() : _count(0) {}

PhoneBook::~PhoneBook() {
    int	i;

    i = 0;
    while ( i < _count ) {
        delete _contact[i];
        i++;
    }

  etc::printOut(etc::GREEN, "Goodbye User!") ;
}

// ******************
// CANONICALS ENDS  *
// ******************


// ******************
//  GETTERS BEGINS  *
// ******************

const int8_t& PhoneBook::getCount() {
    return (_count) ;
}

Contact*  PhoneBook::getArrayFromContact(const int8_t& i) {
    return (_contact[i]) ;
}

// ******************
//  GETTERS ENDS    *
// ******************


// ************************
//  STATIC METHODS BEGINS *
// ************************
 
/**
  * Shows the homescreen of the App where stdin is
  ** listening for a user to enter a command.
  * @param[out] cmd is address of a string where the command
  ** inputted by the user is stored.
  * @returns void
  */
void  PhoneBook::showHomeScreen(std::string& cmd) {
    etc::printOut(etc::MAGENTA, "Noma PhoneBook!") ;
    etc::printOut(etc::YELLOW, "Enter a Command") ;
    std::getline(std::cin, cmd);
}

// **********************
//  STATIC METHODS ENDS *
// **********************


/**
  * Adds a new Contact to the Phonebook.
  * @returns void
  */
void	PhoneBook::addContact() {
    _contact[_count] = new Contact ;

    if ( _contact[_count]->addOneContact(this) ) {
        etc::printOut(etc::RED, "Contact not Saved!", true, false) ;
        delete _contact[_count] ;
        return ;
    }
    if ( _count == MAX_ENTRY ) {
        _count -= 1 ;
        this->removeOneContact(0, false) ;
    }
    etc::printOut(etc::GREEN, "New Contact Saved!") ;

    _count += 1 ;
}

/**
  * Deletes an element (Contact) from **contact array and shifts the
  ** subsequent elements(if any) back to fill the deleted spot.
  * @param index The index from _contact whose value needs to be deleted
  * @param flag if true, _count will be reduced by 1 from the if(..) condition
  ** If false, it has no effect.
  * @returns void
  */
void PhoneBook::removeOneContact(int8_t index, const bool& flag) {
    if (index < 0) {
        return ;
    }

    delete _contact[index] ;
    while ( index < MAX_ENTRY ) {
        _contact[index] = _contact[index + 1] ;
        index++ ;
    }

    if (flag == true) {
        _count -= 1;
    }
}

/**
  * Displays Summary of all saved Contacts from _count
  * @returns void
  */
void	PhoneBook::displaySearchResults() {
    int8_t	      i ;
    std::string   input ;

    i = 0 ;
    etc::printOut(etc::GREEN, "     INDEX|      NAME|  NICKNAME|") ;

    if ( ! _count ) {
        etc::printOut(etc::RED, "Contact List is empty!", true, false) ;
        return ;
    }

    while ( ++i <= _count ) {
        std::cout << std::setw(10) << static_cast<int>(i) << "|" ;

        std::cout << std::setw(10) << _contact[i - 1]->getName().substr(0, 10) << "|" ;

        std::cout << std::setw(10) << _contact[i - 1]->getNickname().substr(0, 10) << "|" ;
        std::cout << std::endl ;
    }

    this->showSingleContactUsingIndex() ;
}

/**
  * Listens on STDIN for user to enter the index of a Contact,
  ** then if received a valid index as input, the Contact having
  ** that index number will be displayed.
  * @returns void
  */
void	PhoneBook::showSingleContactUsingIndex() {
    int			      i ;
    std::string   input ;

    etc::printOut(etc::YELLOW, "Enter index number of a contact for full details") ;
    std::getline(std::cin, input) ;
    try
    {
        i = std::stoi(input, nullptr) ;
    }
    catch ( ... )
    {
        etc::printOut(etc::RED, "The index requested is wrong!", true, false) ;
        return ;
    }
    if ( i > 0 && i <= _count ) {
        _contact[i - 1]->printContact() ;
    }
    else {
        etc::printOut(etc::RED, "The index requested is out of range!", true, false) ;
    }
}

/**
  * Displays bookmarked Contacts if any.
  * @returns void
  */
void  PhoneBook::displayBookmarks() {
    int8_t i = 0 ;
    int8_t j = 0 ;

    while ( i < _count ) {
        if ( _contact[i]->getBookmark() == true  ) {
            std::cout << _contact[i]->getName() << " : " << _contact[i]->getNumber() << std::endl ;
            ++j ;
        }
        ++i ;
    }

    if ( j == 0 ) {
        etc::printOut(etc::RED, "Bookmark is empty!", true, false) ;
    }
}


/**
  * Listens on STDIN for user to enter the index or number
  ** of a Contact they want to delete. Then after receiving
  ** user input from STDIN, it first tries to use input as
  ** index number for deletion, if fails, then it tries to
  ** use input as phone number for deletion.
  * @returns void
  */
void  PhoneBook::removeContact() {
    std::string input ;
    int8_t      i ;

    if ( ! _count ) {
        etc::printOut(etc::RED, "Contact List is empty!", true, false) ;
        return ;
    }

    etc::printOut(etc::YELLOW, "Enter index or number of a contact to delete") ;
    std::getline(std::cin, input) ;

    try
    {
        i = std::stoi(input, nullptr) ;
        if ( i <= MAX_ENTRY && i >= 0 && i <= _count ) {
            this->removeOneContact(i - 1, true) ;
        } else {
            throw std::out_of_range("") ;
        }
    }
    catch ( ... ) {
        for ( i = 0; i < _count; ++i ) {
            if ( ! _contact[i]->getNumber().compare(input) ) {
                this->removeOneContact(i, true) ;
                break ;
            }
        }
    }

    etc::printOut(etc::GREEN, "Action Performed!") ;
}
