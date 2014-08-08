#include <iostream>
#include <functional>
#include <type_traits>
#include <vector>

#include "print-table.h"

using fc::print_table;
using std::cout;
using std::endl;
using std::function;
using std::false_type;
using std::ostream;
using std::true_type;
using std::vector;


template <bool V, typename T, typename F>
class if_ : public false_type {
public:
  typedef F result;
};

template <typename T, typename F>
class if_<true, T, F> : public true_type {
public:
  typedef T result;
};

constexpr bool is_prime(int n, int i) {
  return (i * i > n) ? true :
    (n % i == 0) ? false :
    is_prime(n, i + 1);
}

template <int i, int N>
class emit_prime {
public:
  typedef if_<is_prime(i, 2), emit_prime<i + 1, N - 1>,
                              emit_prime<i + 1, N>> check;
  check i_is_prime;
  typename check::result a;

  void operator()(function<void(int)> f) {
    if (i_is_prime) {
      f(i);
    }
    a(f);
  }
};

template <int i>
class emit_prime<i,1> {
public:
  void operator()(function<void(int)> _) { }
};

int main(int argc, char* argv[]) {
  auto ps = vector<int>();
  emit_prime<2, 10>()([&](int x) { ps.push_back(x); });
  print_table(cout, ps);
  return 0;
}