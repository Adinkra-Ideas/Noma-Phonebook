cmake_minimum_required(VERSION 3.5)

project(Noma LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AllFiles main.cpp
    Contact.cpp
    PhoneBook.cpp
    main.hpp
    Contact.hpp
    PhoneBook.hpp)

add_executable(noma ${AllFiles})

if (MSVC)
  # warning level 4
  target_compile_options(noma
        /W4)
else()
  # additional warnings
  target_compile_options(noma PUBLIC
        -Wextra
        -Werror
        -Wall
        -Wpedantic)
endif()

include(GNUInstallDirs)
install(TARGETS noma
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
