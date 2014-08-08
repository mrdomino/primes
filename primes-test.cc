#include "primes.h"
#include <gtest/gtest.h>

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

  EXPECT_EQ(7, *primes(4)->rbegin());
  EXPECT_EQ(11, *primes(5)->rbegin());
  EXPECT_EQ(13, *primes(6)->rbegin());
  EXPECT_EQ(17, *primes(7)->rbegin());
}

TEST(primes, 10__is_29) {
  auto p = primes(10);
  ASSERT_EQ(10, p->size());
  EXPECT_EQ(29, p->at(9));
}

TEST(primes, large_prime_matches) {
  EXPECT_EQ(7919, *primes(1000)->rbegin());
}

} // namespace

} // namespace fc
