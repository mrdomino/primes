#include "prime-table.h"
#include <gtest/gtest.h>

#include <iostream>
#include <string>

namespace fc {

namespace {

struct PrimeTableTest : ::testing::Test {
  std::ostringstream os;

  void expectStream(char const* c) {
    EXPECT_STREQ(c, os.str().c_str());
  }
};

TEST_F(PrimeTableTest, emptyTableIsEmpty) {
  primeTable(os, 0);
  expectStream("");
}

TEST_F(PrimeTableTest, printsOneDigitMultiples) {
  primeTable(os, 2);
  expectStream("   2 3\n"
               " 2 4 6\n"
               " 3 6 9\n");
}

TEST_F(PrimeTableTest, printsTwoDigitMultiples) {
  primeTable(os, 4);
  expectStream("     2  3  5  7\n"
               "  2  4  6 10 14\n"
               "  3  6  9 15 21\n"
               "  5 10 15 25 35\n"
               "  7 14 21 35 49\n");
}

TEST_F(PrimeTableTest, throwsOnAbsurdInput) {
  EXPECT_ANY_THROW(primeTable(os, -1));
  EXPECT_ANY_THROW(primeTable(os, std::numeric_limits<size_t>::max()));
}

} // namespace

} // namespace fc
