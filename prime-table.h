#ifndef _PRIME_TABLE_H_
#define _PRIME_TABLE_H_

#include <iostream>
#include "primes.h"
#include "print-table.h"

namespace fc {

namespace _ {

template <typename T>
T square(T const& x) {
  return x * x;
}

}

void primeTable(std::ostream& os, size_t n) {
  if (n > 0) {
    auto ps = primes(n);
    auto biggest = _::square(*ps->rbegin());
    print_table(os, *ps, 1 + width_of(biggest));
  }
}

} // namespace fc

#endif
