#ifndef _PRIMES_H_
#define _PRIMES_H_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

namespace fc {

/// Returns a vector containing the first n primes.
std::unique_ptr<std::vector<size_t>> primes(size_t n) {
  // This is implemented as a basic sieve. We construct a table of candidate
  // primes. Then, for each remaining candidate, we consider it prime and
  // eliminate all candidates that contain it as a factor. We need a table of
  // at least size x where pi(x) == n. We iterate through it until we've gotten
  // n primes, then return.
  //
  auto primes = std::make_unique<std::vector<size_t>>(n);
  // We know that
  //   p_n < n * log(n * log(n))
  // for n >= 6, that is, for primes >= 13. We allocate at least enough to find
  // the first 5 primes, growing appropriately from there.
  size_t x = std::max<size_t>(12, std::max<int>(0, ceil(n * log(n * log(n)))));
  // table of candidate primes; e[i] is true if i is composite.
  auto eliminated = std::vector<bool>(x);

  // next prime to add.
  auto nextp = primes->begin();
  for (size_t i = 2; i < x && nextp != primes->end(); ++i) {
    if (!eliminated.at(i)) {
      // i has not been eliminated yet; it must be prime.
      *nextp++ = i;
      if (nextp == primes->end()) {
        break;
      }
      // eliminate all factors of i in the table.
      for (size_t j = 1; j * i < x; ++j) {
        eliminated.at(j * i) = true;
      }
    }
  }
  assert(nextp == primes->end());
  return primes;
}

/// Print a multiplication table over the contents of v.
///
/// Prints elements of v along the first row and column, with each cell
/// containing the product for the corresponding row and column.
template <typename T>
void print_table(std::ostream& os, std::vector<T> const& v) {
  const size_t wid = 8;
  if (!v.empty()) {
    os << std::setw(wid) << "";
  }
  std::for_each(v.begin(), v.end(),
      [&os](T const& x) {
        os << std::setw(wid) << x;
      });
  os << std::endl;
  std::for_each(v.begin(), v.end(),
      [&v,&os](T const& x) {
        os << std::setw(wid) << x;
        std::for_each(v.begin(), v.end(),
            [&x,&os](T const& y) {
              os << std::setw(wid) << x * y;
            });
        os << std::endl;
      });
}

} // namespace fc

#endif
