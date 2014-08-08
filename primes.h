#ifndef _PRIMES_H_
#define _PRIMES_H_

#include <cassert>
#include <cmath>
#include <memory>
#include <vector>

namespace fc {

/// Returns a vector containing the first n primes.
std::unique_ptr<std::vector<size_t>> primes(size_t n) {
  // This is implemented as a basic sieve. We construct a table of candidate
  // primes. Then, for each remaining candidate, we consider it prime and
  // eliminate all candidates that contain it as a factor. Assuming our table
  // is big enough, we will find n primes by the time we've finished iterating
  // through the candidates in this fashion.
  //
  // If p_n is the nth prime, our candidate table must contain at least n
  // entries. We know [0] that for n > 5, p_n < n log(n log(n)). We
  // deterministically allocate space for up to the 5th prime (11) and rely on
  // that bound for larger primes.
  //
  auto primes = std::make_unique<std::vector<size_t>>(n);
  // Candidate table size.
  size_t x = std::max<int>(12, ceil(n * log(n * log(n))));
  // table of candidate primes; eliminated[i] is true if i is composite.
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

} // namespace fc

// [0] http://functions.wolfram.com/NumberTheoryFunctions/Prime/29/0002/
//     The nth prime number: Inequalities (formula 13.03.29.0002).

#endif
