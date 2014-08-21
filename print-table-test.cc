#include "print-table.h"
#include <gtest/gtest.h>
#include <sstream>

namespace fc {

namespace {

TEST(printTable, printsNlOnEmptyVector) {
  std::stringstream ss;

  printTable(ss, std::vector<int>());
  EXPECT_EQ("\n", ss.str());
}

TEST(printTable, prints0Correctly) {
  std::stringstream ss;

  printTable(ss, std::vector<int>(1));
  EXPECT_EQ(
      "               0\n"
      "       0       0\n",
      ss.str());
}

TEST(printTable, multipliesAndFormatsElements) {
  std::stringstream ss;
  auto v = std::vector<int>();
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  printTable(ss, v);
  EXPECT_EQ(
      "               1       2       3\n"
      "       1       1       2       3\n"
      "       2       2       4       6\n"
      "       3       3       6       9\n",
      ss.str());
}

TEST(printTable, variableWidth) {
  std::stringstream ss;
  auto v = std::vector<int>(1);

  printTable(ss, v, 2);
  EXPECT_EQ(
      "   0\n"
      " 0 0\n",
      ss.str());

  ss.str("");
  printTable(ss, v, 0);
  EXPECT_EQ(
      "0\n"
      "00\n",
      ss.str());

  ss.str("");

  printTable(ss, v, 3);
  EXPECT_EQ(
      "     0\n"
      "  0  0\n",
      ss.str());
}

TEST(widthOf, 0Is1) {
  EXPECT_EQ(1, widthOf(0));
}

TEST(widthOf, nIsDigitsInN) {
  EXPECT_EQ(2, widthOf(10));
  EXPECT_EQ(2, widthOf(19));

  EXPECT_EQ(4, widthOf(1234));
  EXPECT_EQ(5, widthOf(10000));
  EXPECT_EQ(10, widthOf(1999999999));
}

} // namespace

} // namespace fc
