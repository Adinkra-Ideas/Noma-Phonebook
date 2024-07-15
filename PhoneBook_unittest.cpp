#include "PhoneBook.hpp"
#include <gtest/gtest.h>

namespace {

// Tests the default constructor.
TEST(PhoneBook, DefaultConstructor) {
  const PhoneBook pb ;

  EXPECT_EQ(0, pb.getCount()) ;
}

} // namespace
