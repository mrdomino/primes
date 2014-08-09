// Template metaprogramming prime multiplication table generator.
//
// This is provided as a proof of concept only, and is obviously silly.
//
// CAUTION: compiling this with large values for PRIMES will use
// lots of memory and CPU. On my system with g++ 4.9.1, the
// compilation took several minutes and used several gigabytes of virtual
// memory memory for 200 primes.
//
#include <iomanip>
#include <iostream>
#include <functional>
#include <type_traits>
#include <vector>

using std::cout;
using std::endl;
using std::function;
using std::false_type;
using std::ostream;
using std::setw;
using std::true_type;
using std::vector;

#ifndef PRIMES
#define PRIMES 10
#endif


template <bool V, typename T, typename F>
class if_ : public false_type {
// Compile-time if-statement. If V is true, this subclasses true_type and
// result is T. Else, this subclasses false_type and result is F.
public:
  typedef F result;
};

template <typename T, typename F>
class if_<true, T, F> : public true_type {
public:
  typedef T result;
};

constexpr bool is_prime(int n, int i) {
// Compile-time-available primality test. Uses the naive approach.
  return (i * i > n) ? true :
    (n % i == 0) ? false :
    is_prime(n, i + 1);
}

template <int i,int N>
class prime {
// Gives the Nth prime starting from i.
public:
  typedef if_<is_prime(i,2), prime<i + 1, N - 1>,
                             prime<i + 1, N>> check;
  static constexpr int value() {
    return check::result::value();
  }
};

template <int i>
class prime<i,0> {
public:
  static constexpr int value() {
    return i - 1;
  }
};

template <int i, int N, int wid>
class print_header {
// Prints a list of N primes starting at i in wid-sized columns.
public:
  typedef if_<is_prime(i,2), print_header<i + 1, N - 1, wid>,
                             print_header<i + 1, N, wid>> check;
  static inline void go() {
    if (check::value) {
      cout << setw(wid) << i;
    }
    check::result::go();
  }
};

template <int i, int wid>
class print_header<i,0, wid> {
public:
  static inline void go() { }
};

template <int p, int i, int N, int wid>
class print_col {
// Prints a single wid-sized column of p * the Nth prime starting from i.
public:
  typedef if_<is_prime(i,2), print_col<p, i+1, N-1, wid>,
                             print_col<p, i+1, N, wid>> check;
  static inline void go() {
    if (check::value) {
      cout << setw(wid) << p * i;
    }
    check::result::go();
  }
};

template <int p, int i, int wid>
class print_col<p,i,0,wid> {
public:
  static inline void go() { }
};

template <int i, int N, int M, int wid>
class print_row {
// Prints a row of M multiples of the Nth prime starting from i.
public:
  typedef if_<is_prime(i,2), print_row<i + 1, N - 1, M, wid>,
                             print_row<i + 1, N, M, wid>> check;
  static inline void go() {
    if (check::value) {
      cout << setw(wid) << i;
      print_col<i,2,M,wid>::go();
      cout << endl;
    }
    check::result::go();
  }
};

template <int i, int M, int wid>
class print_row<i,0, M, wid> {
public:
  static inline void go() { }
};

template <int N, int wid>
class print_table {
// Prints a multiplication table of N primes.
public:
  print_table() {
    if (N) {
      cout << setw(wid) << "";
    }
    print_header<2,N,wid>::go();
    cout << endl;
    print_row<2,N,N,wid>::go();
  }
};

constexpr int width_of(int x) {
// Compile-time width of integer.
  return (x / 10) ? 1 + width_of(x / 10) : 1;
}

constexpr int square(int x) {
// Compile-time square.
  return x * x;
}

int main(int argc, char* argv[]) {
  print_table<PRIMES, 1 + width_of(square(prime<2,PRIMES>::value()))>();
  return 0;
}
