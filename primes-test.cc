#include "primes.h"
#include <gtest/gtest.h>
#include <sstream>

namespace fc {

namespace {

TEST(primes, 0__is_empty) {
  EXPECT_TRUE(primes(0)->empty());
}

TEST(primes, 1__is_2) {
  auto ps = primes(1);
  ASSERT_EQ(1, ps->size());
  EXPECT_EQ(2, ps->at(0));
}

TEST(primes, first_few_primes_match) {
  auto ps = primes(3);
  ASSERT_EQ(3, ps->size());
  EXPECT_EQ(2, ps->at(0));
  EXPECT_EQ(3, ps->at(1));
  EXPECT_EQ(5, ps->at(2));
}

TEST(primes, 10__is_29) {
  auto p = primes(10);
  ASSERT_EQ(10, p->size());
  EXPECT_EQ(29, p->at(9));
}

TEST(primes, large_prime_matches) {
  EXPECT_EQ(7919, *primes(1000)->rbegin());
}


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
