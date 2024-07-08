# include "_etc_.hpp"

namespace etc {
  /**
  * Prints out texts in terminal using Custom Colors
  * @param color is used to set color of text to be printed.
  ** Macros have been defined for popular color codes in etc::
  * @param texts is the actual texts to be printed.
  * @param EOL is a default parameter set to true. 
  ** It is used to determine if line break will be added
  ** after printing texts.
  * @param stdout is a default parameter set to true.
  ** It is used to determine which output stream to print texts. 
  ** If false, texts will be printed to stderr.
  * @returns void
  */
  void	printOut(const char *color, const std::string& texts, bool EOL, bool stdout) {
    if ( stdout ) {
      std::cout << color 
              << texts 
              << etc::RESET_COLOR
              << ((EOL) ? "\n" : "") ;
    } else {
      std::cerr << color 
              << texts 
              << etc::RESET_COLOR
              << ((EOL) ? "\n" : "") ;
    } 
  }

} // namespace etc
