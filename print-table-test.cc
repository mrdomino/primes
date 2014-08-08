#include "print-table.h"
#include <gtest/gtest.h>
#include <sstream>

namespace fc {

namespace {

TEST(print_table, prints_nl_on_empty_vector) {
  std::stringstream ss;

  print_table(ss, std::vector<int>());
  EXPECT_EQ("\n", ss.str());
}

TEST(print_table, prints_0_correctly) {
  std::stringstream ss;

  print_table(ss, std::vector<int>(1));
  EXPECT_EQ(
      "               0\n"
      "       0       0\n",
      ss.str());
}

TEST(print_table, multiplies_and_formats_elements) {
  std::stringstream ss;
  auto v = std::vector<int>();
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  print_table(ss, v);
  EXPECT_EQ(
      "               1       2       3\n"
      "       1       1       2       3\n"
      "       2       2       4       6\n"
      "       3       3       6       9\n",
      ss.str());
}

} // namespace

} // namespace fc