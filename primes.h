#ifndef _PRIMES_H_
#define _PRIMES_H_

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

namespace fc {

std::unique_ptr<std::vector<size_t>> primes(size_t n) {
  auto primes = std::make_unique<std::vector<size_t>>(n);
  size_t x = n * n + 2; // conservative guess, must have x s.t. pi(x) == n.
  auto eliminated = std::vector<bool>(x);

  auto nextp = primes->begin();
  for (size_t i = 2; i < x; ++i) {
    if (!eliminated.at(i)) {
      *nextp++ = i;
      if (nextp == primes->end()) {
        break;
      }
      for (size_t j = 1; j * i < x; ++j) {
        eliminated.at(j * i) = true;
      }
    }
  }
  assert(nextp == primes->end());
  return primes;
}

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
